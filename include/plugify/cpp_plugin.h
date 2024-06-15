#pragma once

#include <string>
#include <cstdint>

namespace plugify {
	constexpr int kApiVersion = 1;

	using InitFunc = int (*)(const void* const*, int, const void*);
	using StartFunc = void (*)();
	using EndFunc = void (*)();

	using GetMethodFn = void* (*)(const std::string&);
	extern GetMethodFn GetMethod;
	
	namespace plugin {
		extern void* handle;

		using GetIdFn = std::ptrdiff_t (*)(void*);
		using GetNameFn = const std::string& (*)(void*);
		using GetFullNameFn = const std::string& (*)(void*);
		using GetDescriptionFn = const std::string& (*)(void*);
		using GetVersionFn = const std::string& (*)(void*);
		using GetAuthorFn = const std::string& (*)(void*);
		using GetWebsiteFn = const std::string& (*)(void*);
		using GetDependenciesFn = std::vector<std::string_view> (*)(void*);
		using FindResourceFn = std::optional<std::filesystem::path> (*)(void*, const std::filesystem::path&);

		extern GetIdFn GetId;
		extern GetNameFn GetName;
		extern GetFullNameFn GetFullName;
		extern GetDescriptionFn GetDescription;
		extern GetVersionFn GetVersion;
		extern GetAuthorFn GetAuthor;
		extern GetWebsiteFn GetWebsite;
		extern GetDependenciesFn GetDependencies;
		extern FindResourceFn FindResource;
	}
	
	class IPluginEntry {
	protected:
		IPluginEntry() = default;
		~IPluginEntry() = default;

	public:
		std::ptrdiff_t GetId() const { return plugin::GetId(plugin::handle); }
		const std::string& GetName() const { return plugin::GetName(plugin::handle); }
		const std::string& GetFullName() const { return plugin::GetFullName(plugin::handle); }
		const std::string& GetDescription() const { return plugin::GetDescription(plugin::handle); }
		const std::string& GetVersion() const { return plugin::GetVersion(plugin::handle); }
		const std::string& GetAuthor() const { return plugin::GetAuthor(plugin::handle); }
		const std::string& GetWebsite() const { return plugin::GetWebsite(plugin::handle); }
		std::vector<std::string_view> GetDependencies() const { return plugin::GetDependencies(plugin::handle); }
		std::optional<std::filesystem::path> FindResource(const std::filesystem::path& path) const { return plugin::FindResource(plugin::handle, path); }

		virtual void OnPluginStart() {};
		virtual void OnPluginEnd() {};
	};

	IPluginEntry* GetPluginEntry();
}

#define EXPOSE_PLUGIN(plugin_api, interface_addr) namespace plugify { \
	GetMethodFn GetMethod{ nullptr }; \
	namespace plugin { \
        void* handle{ nullptr }; \
		GetIdFn GetId{ nullptr }; \
		GetNameFn GetName{ nullptr }; \
		GetFullNameFn GetFullName{ nullptr }; \
		GetDescriptionFn GetDescription{ nullptr }; \
		GetVersionFn GetVersion{ nullptr }; \
		GetAuthorFn GetAuthor{ nullptr }; \
		GetWebsiteFn GetWebsite{ nullptr }; \
		GetDependenciesFn GetDependencies{ nullptr }; \
		FindResourceFn FindResource{ nullptr }; \
	} \
	extern "C" \
	plugin_api int Plugify_Init(void** api, int version, void* handle) { \
		if (version < kApiVersion) { \
			return kApiVersion; \
		} \
		GetMethod = reinterpret_cast<GetMethodFn>(api[0]); \
		plugin::GetName = reinterpret_cast<GetNameFn>(api[1]); \
		plugin::GetId = reinterpret_cast<GetNameFn>(api[2]); \
		plugin::GetFullName = reinterpret_cast<GetFullNameFn>(api[3]); \
		plugin::GetDescription = reinterpret_cast<GetDescriptionFn>(api[4]); \
		plugin::GetVersion = reinterpret_cast<GetVersionFn>(api[5]); \
		plugin::GetAuthor = reinterpret_cast<GetAuthorFn>(api[6]); \
		plugin::GetWebsite = reinterpret_cast<GetWebsiteFn>(api[7]); \
		plugin::GetDependencies = reinterpret_cast<GetDependenciesFn>(api[8]); \
		plugin::FindResource = reinterpret_cast<FindResourceFn>(api[9]); \
		plugin::handle = handle; \
		return 0; \
	} \
	extern "C" \
	plugin_api void Plugify_PluginStart() { \
		GetPluginEntry()->OnPluginStart(); \
	} \
	extern "C" \
	plugin_api void Plugify_PluginEnd() { \
		GetPluginEntry()->OnPluginEnd(); \
	} \
	plugify::IPluginEntry* GetPluginEntry() { \
		return interface_addr; \
	} \
}

namespace plugify {
	struct Vector2 {
		float x{};
		float y{};
	};

	struct Vector3 {
		float x{};
		float y{};
		float z{};
	};

	struct Vector4 {
		float x{};
		float y{};
		float z{};
		float w{};
	};

	struct Matrix4x4 {
		float m[4][4]{};
	};
}