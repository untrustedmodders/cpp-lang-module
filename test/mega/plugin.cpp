#include <wps/example_plugin.h>
#include <plugify/cpp_plugin.h>
#include <plugin_export.h>

class MegaPlugin : public plugify::IPluginEntry {
public:
	void OnPluginStart() override {
		example_plugin::MakePrint(3, "!!! Merry Christmas !!!");
	}

	void OnPluginEnd() override {
		example_plugin::MakePrint(5, "!!! And Happy New Year !!!");
	}
};

MegaPlugin g_megaPlugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_megaPlugin)
