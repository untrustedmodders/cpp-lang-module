#include "assembly.h"
#include <plugify/compat_format.h>
#include <plugify/plugin_descriptor.h>
#include <plugify/plugin.h>
#include <plugify/plugify_provider.h>
#include <plugify/language_module.h>
#include <plugify/cpp_plugin.h>
#include <plugify/log.h>
#include <module_export.h>
#include <unordered_map>
#include <array>

namespace cpplm {
	class AssemblyHolder {
	public:
		AssemblyHolder(std::unique_ptr<Assembly> assembly, plugify::StartFunc startFunc, plugify::EndFunc endFunc) : _assembly{ std::move(assembly) }, _startFunc{ startFunc }, _endFunc{ endFunc } {}

		plugify::StartFunc GetStartFunc() const { return _startFunc; }
		plugify::EndFunc GetEndFunc() const { return _endFunc; }

	private:
		std::unique_ptr<Assembly> _assembly;
		plugify::StartFunc _startFunc{ nullptr };
		plugify::EndFunc _endFunc{ nullptr };
	};

	class CppLanguageModule final : public plugify::ILanguageModule {
	public:
		CppLanguageModule() = default;

		// ILanguageModule
		plugify::InitResult Initialize(std::weak_ptr<plugify::IPlugifyProvider> provider, const plugify::IModule& module) override;
		void Shutdown() override;
		void OnMethodExport(const plugify::IPlugin& plugin) override;
		plugify::LoadResult OnPluginLoad(const plugify::IPlugin& plugin) override;
		void OnPluginStart(const plugify::IPlugin& plugin) override;
		void OnPluginEnd(const plugify::IPlugin& plugin) override;

		void* GetNativeMethod(const std::string& method_name) const;

	private:
		std::shared_ptr<plugify::IPlugifyProvider> _provider;
		std::unordered_map<std::string, AssemblyHolder> _assemblyMap;
		std::unordered_map<std::string, void*> _nativesMap;

		static const std::array<void*, 10> _pluginApi;
	};

	extern CppLanguageModule g_golm;
}

extern "C" CPPLM_EXPORT plugify::ILanguageModule* GetLanguageModule();