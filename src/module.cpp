#include <wizard/plugin.h>
#include <wizard/language_module.h>
#include "module_export.h"

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
		bool Initialize() override {
			return true;
		}

		void Shutdown() override {
		}

		void OnNativeAdded(/* data */) override {
			// TODO: Add to natives map
		}

		LoadResult OnLoadPlugin(const IPlugin& plugin) override {
			return {};
		}

		void OnStartPlugin(const IPlugin& plugin) override {
			// TODO: implement
		}

		void OnEndPlugin(const IPlugin& plugin) override {
			// TODO: implement
		}

	private:
		//TODO: _nativesMap
	};

	CppLanguageModule g_cpplm;

    CPP_LANG_MODULE_EXPORT void* GetNativeMethod(std::string_view method_name) {
		return g_cpplm.GetNativeMethod(method_name);
	}
}

extern "C" CPP_LANG_MODULE_EXPORT wizard::ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
