#include <wizard/cpp_plugin.h>
#include <plugin_export.h>
#include <iostream>

class ExamplePlugin : public wizard::IPluginEntry {
public:
	void OnPluginStart() override {
		std::cout << "Example Start!" << std::endl;
	}

	void OnPluginEnd() override {
		std::cout << "Example End!" << std::endl;
	}
};

ExamplePlugin g_examplePlugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_examplePlugin)
