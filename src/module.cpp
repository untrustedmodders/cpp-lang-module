#include "assembly.h"
#include <plugify/plugin_descriptor.h>
#include <plugify/plugin.h>
#include <plugify/plugify_provider.h>
#include <plugify/language_module.h>
#include <plugify/cpp_plugin.h>
#include <plugify/log.h>
#include <module_export.h>
#include <unordered_map>
#include <format>
#include <array>

using namespace plugify;
namespace fs = std::filesystem;

namespace cpplm {
	class CppLanguageModule final : public ILanguageModule {
	public:
		CppLanguageModule() = default;

		// ILanguageModule
		InitResult Initialize(std::weak_ptr<IPlugifyProvider> provider, const IModule& /*module*/) override {
			if (!(_provider = provider.lock())) {
				return ErrorData{ "Provider not exposed" };
			}

			_provider->Log("[CPPLM] Inited!", Severity::Debug);

			return InitResultData{};
		}

		void Shutdown() override {
			_nativesMap.clear();
			_assemblyMap.clear();
			_provider.reset();
		}

		void OnMethodExport(const IPlugin& plugin) override {
			const auto& pluginName = plugin.GetName();
			for (const auto& [name, addr] : plugin.GetMethods()) {
				_nativesMap.try_emplace(std::format("{}.{}", pluginName, name), addr);
			}
		}

		LoadResult OnPluginLoad(const IPlugin& plugin) override {
			fs::path assemblyPath = plugin.GetBaseDir() / std::format(BINARY_MODULE_PREFIX "{}" BINARY_MODULE_SUFFIX, plugin.GetDescriptor().entryPoint);

			auto assembly = Assembly::LoadFromPath(assemblyPath);
			if (!assembly) {
				return ErrorData{ std::format("Failed to load assembly: {}", Assembly::GetError()) };
			}

			bool funcFail = false;
			std::vector<std::string_view> funcErrors;

			auto* const initFunc = assembly->GetFunction<InitFunc>("Plugify_Init");
			if (!initFunc) {
				funcFail = true;
				funcErrors.emplace_back("Plugify_Init");
			}

			auto* const startFunc = assembly->GetFunction<StartFunc>("Plugify_PluginStart");
			if (!startFunc) {
				funcFail = true;
				funcErrors.emplace_back("Plugify_PluginStart");
			}

			auto* const endFunc = assembly->GetFunction<EndFunc>("Plugify_PluginEnd");
			if (!endFunc) {
				funcFail = true;
				funcErrors.emplace_back("Plugify_PluginEnd");
			}

			if (funcFail) {
				std::string funcs(funcErrors[0]);
				for (auto it = std::next(funcErrors.begin()); it != funcErrors.end(); ++it) {
					std::format_to(std::back_inserter(funcs), ", {}", *it);
				}
				return ErrorData{ std::format("Not found {} function(s)", funcs) };
			}

			funcFail = false;
			funcErrors.clear();
			
			const auto& exportedMethods = plugin.GetDescriptor().exportedMethods;
			std::vector<MethodData> methods;
			methods.reserve(exportedMethods.size());
			
			for (const auto& method : exportedMethods) {
				if (auto* const func = assembly->GetFunction(method.funcName.c_str())) {
					methods.emplace_back(method.name, func);
				}
				else {
					funcFail = true;
					funcErrors.emplace_back(method.name);
				}
			}
			if (funcFail) {
				std::string funcs(funcErrors[0]);
				for (auto it = std::next(funcErrors.begin()); it != funcErrors.end(); ++it) {
					std::format_to(std::back_inserter(funcs), ", {}", *it);
				}
				return ErrorData{ std::format("Not found {} method function(s)", funcs) };
			}

			const int resultVersion = initFunc(const_cast<void**>(_pluginApi.data()), kApiVersion);
			if (resultVersion != 0) {
				return ErrorData{ std::format("Not supported plugin api {}, max supported {}", resultVersion, kApiVersion) };
			}

			const auto [_, result] = _assemblyMap.try_emplace(plugin.GetName(), std::move(assembly), startFunc, endFunc);
			if (!result) {
				return ErrorData{ std::format("Plugin name duplicate") };
			}

			return LoadResultData{ std::move(methods) };
		}

		void OnPluginStart(const IPlugin& plugin) override {
			if (const auto it = _assemblyMap.find(plugin.GetName()); it != _assemblyMap.end()) {
				const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
				assemblyHolder.GetStartFunc()();
			}
		}

		void OnPluginEnd(const IPlugin& plugin) override {
			if (const auto it = _assemblyMap.find(plugin.GetName()); it != _assemblyMap.end()) {
				const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
				assemblyHolder.GetEndFunc()();
			}
		}

		// Plugin API methods
		void* GetNativeMethod(const std::string& method_name) const {
			if (const auto it = _nativesMap.find(method_name); it != _nativesMap.end()) {
				return std::get<void*>(*it);
			}
			_provider->Log(std::format("[CPPLM] GetNativeMethod failed to find {}", method_name), Severity::Fatal);
			return nullptr;
		}

	private:
		class AssemblyHolder {
		public:
			AssemblyHolder(std::unique_ptr<Assembly> assembly, StartFunc startFunc, EndFunc endFunc) : _assembly{ std::move(assembly) }, _startFunc{ startFunc }, _endFunc{ endFunc } {}

			StartFunc GetStartFunc() const { return _startFunc; }
			EndFunc GetEndFunc() const { return _endFunc; }

		private:
			std::unique_ptr<Assembly> _assembly;
			StartFunc _startFunc{ nullptr };
			EndFunc _endFunc{ nullptr };
		};

		std::shared_ptr<IPlugifyProvider> _provider;
		std::unordered_map<std::string, AssemblyHolder> _assemblyMap;
		std::unordered_map<std::string, void*> _nativesMap;

		static const std::array<void*, 1> _pluginApi;
	};

	CppLanguageModule g_cpplm;

	void* GetNativeMethodImpl(const std::string& method_name) {
		return g_cpplm.GetNativeMethod(method_name);
	}

	const std::array<void*, 1> CppLanguageModule::_pluginApi = {
		reinterpret_cast<void*>(&GetNativeMethodImpl),
	};
}

extern "C"
CPPLM_EXPORT ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
