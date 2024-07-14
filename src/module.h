#include <plugify/assembly.h>
#include <plugify/module.h>
#include <plugify/plugin.h>
#include <plugify/plugify_provider.h>
#include <plugify/language_module.h>
#include <plugify/cpp_plugin.h>

#include <module_export.h>
#include <unordered_map>
#include <map>
#include <array>

namespace cpplm {
	struct string_hash {
		using is_transparent = void;
		[[nodiscard]] size_t operator()(const char* txt) const {
			return std::hash<std::string_view>{}(txt);
		}
		[[nodiscard]] size_t operator()(std::string_view txt) const {
			return std::hash<std::string_view>{}(txt);
		}
		[[nodiscard]] size_t operator()(const std::string& txt) const {
			return std::hash<std::string>{}(txt);
		}
	};

	class AssemblyHolder {
	public:
		AssemblyHolder(std::unique_ptr<plugify::Assembly> assembly, plugify::StartFunc startFunc, plugify::EndFunc endFunc) : _assembly{std::move(assembly)}, _startFunc{startFunc}, _endFunc{endFunc} {}

		plugify::Assembly& GetAssembly() const { return *_assembly; }
		plugify::StartFunc GetStartFunc() const { return _startFunc; }
		plugify::EndFunc GetEndFunc() const { return _endFunc; }

	private:
		std::unique_ptr<plugify::Assembly> _assembly;
		plugify::StartFunc _startFunc;
		plugify::EndFunc _endFunc;
	};

	class CppLanguageModule final : public plugify::ILanguageModule {
	public:
		CppLanguageModule() = default;

		// ILanguageModule
		plugify::InitResult Initialize(std::weak_ptr<plugify::IPlugifyProvider> provider, plugify::ModuleRef module) override;
		void Shutdown() override;
		void OnMethodExport(plugify::PluginRef plugin) override;
		plugify::LoadResult OnPluginLoad(plugify::PluginRef plugin) override;
		void OnPluginStart(plugify::PluginRef plugin) override;
		void OnPluginEnd(plugify::PluginRef plugin) override;

		const std::shared_ptr<plugify::IPlugifyProvider>& GetProvider() { return _provider; }
		plugify::MemAddr GetNativeMethod(std::string_view methodName) const;
		void GetNativeMethod(std::string_view methodName, plugify::MemAddr* addressDest);

	private:
		std::shared_ptr<plugify::IPlugifyProvider> _provider;
		
		std::map<plugify::UniqueId, AssemblyHolder> _assemblyMap;
		std::unordered_map<std::string, plugify::MemAddr, string_hash, std::equal_to<>> _nativesMap;
		
		std::vector<plugify::MemAddr*> _addresses;

		static std::array<void*, 15> _pluginApi;
	};

	extern CppLanguageModule g_cpplm;
}

extern "C" CPPLM_EXPORT plugify::ILanguageModule* GetLanguageModule();