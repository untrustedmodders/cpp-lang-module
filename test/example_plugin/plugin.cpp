#include <plugify/cpp_plugin.h>
#include <plugin_export.h>
#include <iostream>

class ExamplePlugin : public plugify::IPluginEntry {
public:
	void OnPluginStart() override {
		std::cout << "Example Start!" << std::endl;
	}

	void OnPluginEnd() override {
		std::cout << "Example End!" << std::endl;
	}

	void MakePrint(int count, const std::string& message) {
		for (int i = 0; i < count; ++i) {
			std::cout << message << std::endl;
		}
	}
} g_examplePlugin;

EXPOSE_PLUGIN(PLUGIN_API, &g_examplePlugin)

extern "C"
PLUGIN_API void MakePrint(int count, const std::string& message) {
	g_examplePlugin.MakePrint(count, message);
}
