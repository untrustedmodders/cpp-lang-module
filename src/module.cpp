#include <wizard/plugin.h>
#include <wizard/wizard_provider.h>
#include <wizard/language_module.h>
#include <module_export.h>

using namespace wizard;

namespace cpplm {
	class CppLanguageModule final : public ILanguageModule {
	public:
		CppLanguageModule() = default;

		void* GetNativeMethod(std::string_view method_name) {
			// TODO: find in _nativesMap
			return nullptr;
		}

		// ILanguageModule
		InitResult Initialize(std::weak_ptr<IWizardProvider> provider, const IModule& module) override {
			if (!(_provider = provider.lock())) {
				return ErrorData{"Provider not exposed"};
			}

			_provider->Log("CPPLM Inited!", ErrorLevel::INFO);

			return LoadResultData{};
		}

		void Shutdown() override {
			_provider.reset();
		}

		void OnNativeAdded(/* data */) override {
			// TODO: Add to natives map
		}

		LoadResult OnPluginLoad(const IPlugin& plugin) override {
			return {};
		}

		void OnPluginStart(const IPlugin& plugin) override {
			// TODO: implement
		}

		void OnPluginEnd(const IPlugin& plugin) override {
			// TODO: implement
		}

	private:
		//TODO: _nativesMap
		std::shared_ptr<IWizardProvider> _provider;
	};

	CppLanguageModule g_cpplm;

	extern "C"
	CPPLM_EXPORT void* GetNativeMethod(std::string_view method_name) {
		return g_cpplm.GetNativeMethod(method_name);
	}
}

extern "C"
CPPLM_EXPORT ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
