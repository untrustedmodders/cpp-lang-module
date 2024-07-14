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
InitResult CppLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, ModuleRef /*module*/) {
	if (!(_provider = provider.lock())) {
		return ErrorData{ "Provider not exposed" };
	}

	_provider->Log(LOG_PREFIX "Inited!", Severity::Debug);

	return InitResultData{};
}

void CppLanguageModule::Shutdown() {
	for (MemAddr* addr : _addresses) {
		*addr = nullptr;
	}
	_nativesMap.clear();
	_addresses.clear();
	_assemblyMap.clear();
	_provider.reset();
}

void CppLanguageModule::OnMethodExport(PluginRef plugin) {
	auto pluginName = plugin.GetName();
	for (const auto& [name, addr] : plugin.GetMethods()) {
		_nativesMap.try_emplace(std::format("{}.{}", pluginName, name), addr);
	}
}

LoadResult CppLanguageModule::OnPluginLoad(PluginRef plugin) {
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

	std::span<const MethodRef> exportedMethods = plugin.GetDescriptor().GetExportedMethods();
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
		PluginRef plugin;
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

void CppLanguageModule::OnPluginStart(PluginRef plugin) {
	if (const auto it = _assemblyMap.find(plugin.GetId()); it != _assemblyMap.end()) {
		const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
		assemblyHolder.GetStartFunc()();
	}
}

void CppLanguageModule::OnPluginEnd(PluginRef plugin) {
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

void CppLanguageModule::GetNativeMethod(std::string_view methodName, plugify::MemAddr* addressDest) {
	if (const auto it = _nativesMap.find(methodName); it != _nativesMap.end()) {
		*addressDest = std::get<MemAddr>(*it);
		_addresses.emplace_back(addressDest);
		return;
	}
	_provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find: '{}'", methodName), Severity::Fatal);
}

namespace cpplm {
	CppLanguageModule g_cpplm;
}

void* GetMethodPtr(std::string_view methodName) {
	return g_cpplm.GetNativeMethod(methodName);
}

void GetMethodPtr2(std::string_view methodName, MemAddr* addressDest) {
	g_cpplm.GetNativeMethod(methodName, addressDest);
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

UniqueId GetPluginId(PluginRef plugin) {
	return plugin.GetId();
}

std::string_view GetPluginName(PluginRef plugin) {
	return plugin.GetName();
}

std::string_view GetPluginFullName(PluginRef plugin) {
	return plugin.GetFriendlyName();
}

std::string_view GetPluginDescription(PluginRef plugin) {
	return plugin.GetDescriptor().GetDescription();
}

std::string_view GetPluginVersion(PluginRef plugin) {
	return plugin.GetDescriptor().GetVersionName();
}

std::string_view GetPluginAuthor(PluginRef plugin) {
	return plugin.GetDescriptor().GetCreatedBy();
}

std::string_view GetPluginWebsite(PluginRef plugin) {
	return plugin.GetDescriptor().GetCreatedByURL();
}

const fs::path& GetPluginBaseDir(PluginRef plugin) {
	return plugin.GetBaseDir();
}

std::vector<std::string_view> GetPluginDependencies(PluginRef plugin) {
	std::span<const PluginReferenceDescriptorRef> dependencies = plugin.GetDescriptor().GetDependencies();
	std::vector<std::string_view> deps;
	deps.reserve(dependencies.size());
	for (const auto& dependency : dependencies) {
		deps.emplace_back(dependency.GetName());
	}
	return deps;
}

std::optional<fs::path> FindPluginResource(PluginRef plugin, const fs::path& path) {
	return plugin.FindResource(path);
}

std::array<void*, 15> CppLanguageModule::_pluginApi = {
		reinterpret_cast<void*>(&::GetMethodPtr),
		reinterpret_cast<void*>(&::GetMethodPtr2),
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
