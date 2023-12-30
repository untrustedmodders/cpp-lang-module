#include <wizard_export.h>
#include <string_view>
#include <iostream>

namespace wizard {
	constexpr int kApiVersion = 1;

	class IPluginEntry {
	protected:
		~IPluginEntry() = default;

	public:
		virtual void OnPluginStart() {};
		virtual void OnPluginEnd() {};
	};

	IPluginEntry* GetPluginEntry();

	using GetMethodFn = void* (*)(std::string_view);
	GetMethodFn GetMethod;

	extern "C"
	WIZARD_EXPORT int Wizard_Init(void** api, int version) {
		if (version < kApiVersion) {
			return kApiVersion;
		}

		GetMethod = reinterpret_cast<GetMethodFn>(api[0]);

		return 0;
	}

	extern "C"
	WIZARD_EXPORT void Wizard_PluginStart() {
		GetPluginEntry()->OnPluginStart();
	}

	extern "C"
	WIZARD_EXPORT void Wizard_PluginEnd() {
		GetPluginEntry()->OnPluginEnd();
	}
}

class ExamplePlugin : public wizard::IPluginEntry {
public:
	void OnPluginStart() override;
	void OnPluginEnd() override;
};

ExamplePlugin g_examplePlugin;

namespace wizard {
	wizard::IPluginEntry* GetPluginEntry() {
		return &g_examplePlugin;
	}
}

void ExamplePlugin::OnPluginStart() {
	std::cout << "Example Start!" << std::endl;
}

void ExamplePlugin::OnPluginEnd() {
	std::cout << "Example End!" << std::endl;
}
