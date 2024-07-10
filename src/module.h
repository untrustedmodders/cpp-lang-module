#include <plugify/assembly.h>
#include <plugify/plugin.h>
#include <plugify/plugify_provider.h>
#include <plugify/language_module.h>
#include <plugify/cpp_plugin.h>

#include <module_export.h>
#include <unordered_map>
#include <map>
#include <array>

namespace cpplm {
	class AssemblyHolder {
	public:
		AssemblyHolder(std::unique_ptr<plugify::Assembly> assembly, plugify::StartFunc startFunc, plugify::EndFunc endFunc) : _assembly{std::move(assembly)}, _startFunc{startFunc}, _endFunc{endFunc} {}

		plugify::Assembly& GetAssembly() const { return *_assembly; }
		plugify::StartFunc GetStartFunc() const { return _startFunc; }
		plugify::EndFunc GetEndFunc() const { return _endFunc; }

	private:
		std::unique_ptr<plugify::Assembly> _assembly;
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

		const std::shared_ptr<plugify::IPlugifyProvider>& GetProvider() { return _provider; }
		plugify::MemAddr GetNativeMethod(const std::string& methodName) const;

	private:
		std::shared_ptr<plugify::IPlugifyProvider> _provider;
		std::map<plugify::UniqueId, AssemblyHolder> _assemblyMap;
		std::unordered_map<std::string, plugify::MemAddr> _nativesMap;

		static const std::array<void*, 14> _pluginApi;
	};

	extern CppLanguageModule g_cpplm;
}

extern "C" CPPLM_EXPORT plugify::ILanguageModule* GetLanguageModule();