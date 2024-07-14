#include "module.h"

#include <plugify/mem_addr.h>
#include <plugify/mem_accessor.h>
#include <plugify/mem_protector.h>
#include <plugify/compat_format.h>
#include <plugify/plugin_reference_descriptor.h>
#include <plugify/plugin_descriptor.h>
#include <plugify/plugin.h>
#include <plugify/log.h>

using namespace plugify;
using namespace cpplm;
namespace fs = std::filesystem;

#define LOG_PREFIX "[CPPLM] "

// ILanguageModule
InitResult CppLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, IModule /*module*/) {
	if (!(_provider = provider.lock())) {
		return ErrorData{ "Provider not exposed" };
	}

	_provider->Log(LOG_PREFIX "Inited!", Severity::Debug);

	return InitResultData{};
}

void CppLanguageModule::Shutdown() {
	_nativesMap.clear();
#if CPPLM_PLATFORM_LINUX || CPPLM_PLATFORM_APPLE
#if CPPLM_PLATFORM_LINUX
	const auto name = ".bss";
#else
	const auto name = "__BSS";
#endif
	for (auto& [_, holder] : _assemblyMap) {
		auto bss = holder.GetAssembly().GetSectionByName(name);
		if (bss.IsValid()) {
			MemProtector protector(bss.base, bss.size, ProtFlag::RWX);
			std::memset(bss.base, 0, bss.size);
		}
	}
#endif
	_assemblyMap.clear();
	_provider.reset();
}

void CppLanguageModule::OnMethodExport(IPlugin plugin) {
	auto pluginName = plugin.GetName();
	for (const auto& [name, addr] : plugin.GetMethods()) {
		_nativesMap.try_emplace(std::format("{}.{}", pluginName, name), addr);
	}
}

LoadResult CppLanguageModule::OnPluginLoad(IPlugin plugin) {
	fs::path entryPoint(plugin.GetDescriptor().GetEntryPoint());
	fs::path assemblyPath(plugin.GetBaseDir() / entryPoint.parent_path() / std::format(CPPLM_LIBRARY_PREFIX "{}" CPPLM_LIBRARY_SUFFIX, entryPoint.filename().string()));

#if CPPLM_PLATFORM_LINUX || CPPLM_PLATFORM_APPLE
	const bool sections = true;
#else
	const bool sections = false;
#endif

	LoadFlag flags = LoadFlag::Lazy;
	if (_provider->IsPreferOwnSymbols())
		flags |= LoadFlag::Deepbind;

	auto assembly = std::make_unique<Assembly>(assemblyPath, flags, sections);
	if (!assembly->IsValid()) {
		return ErrorData{ std::format("Failed to load assembly: {}", assembly->GetError()) };
	}

	std::vector<std::string_view> funcErrors;

	auto* const initFunc = assembly->GetFunctionByName("Plugify_Init").RCast<InitFunc>();
	if (!initFunc) {
		funcErrors.emplace_back("Plugify_Init");
	}

	auto* const startFunc = assembly->GetFunctionByName("Plugify_PluginStart").RCast<StartFunc>();
	if (!startFunc) {
		funcErrors.emplace_back("Plugify_PluginStart");
	}

	auto* const endFunc = assembly->GetFunctionByName("Plugify_PluginEnd").RCast<EndFunc>();
	if (!endFunc) {
		funcErrors.emplace_back("Plugify_PluginEnd");
	}

	if (!funcErrors.empty()) {
		std::string funcs(funcErrors[0]);
		for (auto it = std::next(funcErrors.begin()); it != funcErrors.end(); ++it) {
			std::format_to(std::back_inserter(funcs), ", {}", *it);
		}
		return ErrorData{ std::format("Not found {} function(s)", funcs) };
	}

	funcErrors.clear();

	std::vector<IMethod> exportedMethods = plugin.GetDescriptor().GetExportedMethods();
	std::vector<MethodData> methods;
	methods.reserve(exportedMethods.size());

	for (const auto& method : exportedMethods) {
		if (auto const func = assembly->GetFunctionByName(method.GetFunctionName())) {
			methods.emplace_back(method.GetName(), func);
		} else {
			funcErrors.emplace_back(method.GetName());
		}
	}
	if (!funcErrors.empty()) {
		std::string funcs(funcErrors[0]);
		for (auto it = std::next(funcErrors.begin()); it != funcErrors.end(); ++it) {
			std::format_to(std::back_inserter(funcs), ", {}", *it);
		}
		return ErrorData{ std::format("Not found {} method function(s)", funcs) };
	}

	union {
		IPlugin plugin;
		void* ptr;
	} cast{plugin};

	const int resultVersion = initFunc(_pluginApi, kApiVersion, cast.ptr);
	if (resultVersion != 0) {
		return ErrorData{ std::format("Not supported plugin api {}, max supported {}", resultVersion, kApiVersion) };
	}

	const auto [_, result] = _assemblyMap.try_emplace(plugin.GetId(), std::move(assembly), startFunc, endFunc);
	if (!result) {
		return ErrorData{ std::format("Plugin id duplicate") };
	}

	return LoadResultData{ std::move(methods) };
}

void CppLanguageModule::OnPluginStart(IPlugin plugin) {
	if (const auto it = _assemblyMap.find(plugin.GetId()); it != _assemblyMap.end()) {
		const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
		assemblyHolder.GetStartFunc()();
	}
}

void CppLanguageModule::OnPluginEnd(IPlugin plugin) {
	if (const auto it = _assemblyMap.find(plugin.GetId()); it != _assemblyMap.end()) {
		const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
		assemblyHolder.GetEndFunc()();
	}
}

// Plugin API methods
MemAddr CppLanguageModule::GetNativeMethod(std::string_view methodName) const {
	if (const auto it = _nativesMap.find(methodName); it != _nativesMap.end()) {
		return std::get<MemAddr>(*it);
	}
	_provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find {}", methodName), Severity::Fatal);
	return nullptr;
}

namespace cpplm {
	CppLanguageModule g_cpplm;
}

void* GetMethodPtr(std::string_view methodName) {
	return g_cpplm.GetNativeMethod(methodName);
}

const fs::path& GetBaseDir() {
	return g_cpplm.GetProvider()->GetBaseDir();
}

bool IsModuleLoaded(std::string_view moduleName, std::optional<int32_t> requiredVersion, bool minimum) {
	return g_cpplm.GetProvider()->IsModuleLoaded(moduleName, requiredVersion, minimum);
}

bool IsPluginLoaded(std::string_view pluginName, std::optional<int32_t> requiredVersion, bool minimum) {
	return g_cpplm.GetProvider()->IsPluginLoaded(pluginName, requiredVersion, minimum);
}

UniqueId GetPluginId(IPlugin plugin) {
	return plugin.GetId();
}

std::string_view GetPluginName(IPlugin plugin) {
	return plugin.GetName();
}

std::string_view GetPluginFullName(IPlugin plugin) {
	return plugin.GetFriendlyName();
}

std::string_view GetPluginDescription(IPlugin plugin) {
	return plugin.GetDescriptor().GetDescription();
}

std::string_view GetPluginVersion(IPlugin plugin) {
	return plugin.GetDescriptor().GetVersionName();
}

std::string_view GetPluginAuthor(IPlugin plugin) {
	return plugin.GetDescriptor().GetCreatedBy();
}

std::string_view GetPluginWebsite(IPlugin plugin) {
	return plugin.GetDescriptor().GetCreatedByURL();
}

const fs::path& GetPluginBaseDir(IPlugin plugin) {
	return plugin.GetBaseDir();
}

std::vector<std::string_view> GetPluginDependencies(IPlugin plugin) {
	std::vector<IPluginReferenceDescriptor> deps = plugin.GetDescriptor().GetDependencies();
	std::vector<std::string_view> dependencies;
	dependencies.reserve(deps.size());
	for (const auto& dependency : deps) {
		dependencies.emplace_back(dependency.GetName());
	}
	return dependencies;
}

std::optional<fs::path> FindPluginResource(IPlugin plugin, const fs::path& path) {
	return plugin.FindResource(path);
}

std::array<void*, 14> CppLanguageModule::_pluginApi = {
		reinterpret_cast<void*>(&::GetMethodPtr),
		reinterpret_cast<void*>(&::GetBaseDir),
		reinterpret_cast<void*>(&::IsModuleLoaded),
		reinterpret_cast<void*>(&::IsPluginLoaded),
		reinterpret_cast<void*>(&::GetPluginId),
		reinterpret_cast<void*>(&::GetPluginName),
		reinterpret_cast<void*>(&::GetPluginFullName),
		reinterpret_cast<void*>(&::GetPluginDescription),
		reinterpret_cast<void*>(&::GetPluginVersion),
		reinterpret_cast<void*>(&::GetPluginAuthor),
		reinterpret_cast<void*>(&::GetPluginWebsite),
		reinterpret_cast<void*>(&::GetPluginBaseDir),
		reinterpret_cast<void*>(&::GetPluginDependencies),
		reinterpret_cast<void*>(&::FindPluginResource)
};

ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
