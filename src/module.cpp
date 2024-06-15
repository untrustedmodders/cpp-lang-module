#include "module.h"

using namespace plugify;
using namespace cpplm;
namespace fs = std::filesystem;

#define LOG_PREFIX "[CPPLM] "

// ILanguageModule
InitResult CppLanguageModule::Initialize(std::weak_ptr<IPlugifyProvider> provider, const IModule& /*module*/) {
	if (!(_provider = provider.lock())) {
		return ErrorData{ "Provider not exposed" };
	}

	_provider->Log(LOG_PREFIX "Inited!", Severity::Debug);

	return InitResultData{};
}

void CppLanguageModule::Shutdown() {
	_nativesMap.clear();
	_assemblyMap.clear();
	_provider.reset();
}

void CppLanguageModule::OnMethodExport(const IPlugin& plugin) {
	const auto& pluginName = plugin.GetName();
	for (const auto& [name, addr] : plugin.GetMethods()) {
		_nativesMap.try_emplace(std::format("{}.{}", pluginName, name), addr);
	}
}

LoadResult CppLanguageModule::OnPluginLoad(const IPlugin& plugin) {
	fs::path entryPoint(plugin.GetDescriptor().entryPoint);
	fs::path assemblyPath(plugin.GetBaseDir() / entryPoint.parent_path() / std::format(CPPLM_LIBRARY_PREFIX "{}" CPPLM_LIBRARY_SUFFIX, entryPoint.filename().string()));

	auto assembly = Assembly::LoadFromPath(assemblyPath, _provider->IsPreferOwnSymbols());
	if (!assembly) {
		return ErrorData{ std::format("Failed to load assembly: {}", Assembly::GetError()) };
	}

	std::vector<std::string_view> funcErrors;

	auto* const initFunc = assembly->GetFunction<InitFunc>("Plugify_Init");
	if (!initFunc) {
		funcErrors.emplace_back("Plugify_Init");
	}

	auto* const startFunc = assembly->GetFunction<StartFunc>("Plugify_PluginStart");
	if (!startFunc) {
		funcErrors.emplace_back("Plugify_PluginStart");
	}

	auto* const endFunc = assembly->GetFunction<EndFunc>("Plugify_PluginEnd");
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

	const auto& exportedMethods = plugin.GetDescriptor().exportedMethods;
	std::vector<MethodData> methods;
	methods.reserve(exportedMethods.size());

	for (const auto& method : exportedMethods) {
		if (auto* const func = assembly->GetFunction(method.funcName.c_str())) {
			methods.emplace_back(method.name, func);
		} else {
			funcErrors.emplace_back(method.name);
		}
	}
	if (!funcErrors.empty()) {
		std::string funcs(funcErrors[0]);
		for (auto it = std::next(funcErrors.begin()); it != funcErrors.end(); ++it) {
			std::format_to(std::back_inserter(funcs), ", {}", *it);
		}
		return ErrorData{ std::format("Not found {} method function(s)", funcs) };
	}

	const int resultVersion = initFunc(_pluginApi.data(), kApiVersion, &plugin);
	if (resultVersion != 0) {
		return ErrorData{ std::format("Not supported plugin api {}, max supported {}", resultVersion, kApiVersion) };
	}

	const auto [_, result] = _assemblyMap.try_emplace(plugin.GetName(), std::move(assembly), startFunc, endFunc);
	if (!result) {
		return ErrorData{ std::format("Plugin name duplicate") };
	}

	return LoadResultData{ std::move(methods) };
}

void CppLanguageModule::OnPluginStart(const IPlugin& plugin) {
	if (const auto it = _assemblyMap.find(plugin.GetName()); it != _assemblyMap.end()) {
		const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
		assemblyHolder.GetStartFunc()();
	}
}

void CppLanguageModule::OnPluginEnd(const IPlugin& plugin) {
	if (const auto it = _assemblyMap.find(plugin.GetName()); it != _assemblyMap.end()) {
		const auto& assemblyHolder = std::get<AssemblyHolder>(*it);
		assemblyHolder.GetEndFunc()();
	}
}

// Plugin API methods
void* CppLanguageModule::GetNativeMethod(const std::string& methodName) const {
	if (const auto it = _nativesMap.find(methodName); it != _nativesMap.end()) {
		return std::get<void*>(*it);
	}
	_provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find {}", methodName), Severity::Fatal);
	return nullptr;
}

namespace cpplm {
	CppLanguageModule g_cpplm;
}

void* GetMethodPtr(const std::string& methodName) {
	return g_cpplm.GetNativeMethod(methodName);
}

UniqueId GetPluginId(const plugify::IPlugin& plugin) {
	return plugin.GetId();
}

const std::string& GetPluginName(const plugify::IPlugin& plugin) {
	return plugin.GetName();
}

const std::string& GetPluginFullName(const plugify::IPlugin& plugin) {
	return plugin.GetFriendlyName();
}

const std::string& GetPluginDescription(const plugify::IPlugin& plugin) {
	return plugin.GetDescriptor().description;
}

const std::string& GetPluginVersion(const plugify::IPlugin& plugin) {
	return plugin.GetDescriptor().versionName;
}

const std::string& GetPluginAuthor(const plugify::IPlugin& plugin) {
	return plugin.GetDescriptor().createdBy;
}

const std::string& GetPluginWebsite(const plugify::IPlugin& plugin) {
	return plugin.GetDescriptor().createdByURL;
}

std::vector<std::string_view> GetPluginDependencies(const plugify::IPlugin& plugin) {
	const auto& desc = plugin.GetDescriptor();
	std::vector<std::string_view> deps;
	deps.reserve(desc.dependencies.size());
	for (const auto& dependency : desc.dependencies) {
		deps.emplace_back(dependency.name);
	}
	return deps;
}

std::optional<std::filesystem::path> FindPluginResource(const plugify::IPlugin& plugin, const std::filesystem::path& path) {
	return plugin.FindResource(path);
}

const std::array<void*, 10> CppLanguageModule::_pluginApi = {
		reinterpret_cast<void*>(&GetMethodPtr),
		reinterpret_cast<void*>(&GetPluginId),
		reinterpret_cast<void*>(&GetPluginName),
		reinterpret_cast<void*>(&GetPluginFullName),
		reinterpret_cast<void*>(&GetPluginDescription),
		reinterpret_cast<void*>(&GetPluginVersion),
		reinterpret_cast<void*>(&GetPluginAuthor),
		reinterpret_cast<void*>(&GetPluginWebsite),
		reinterpret_cast<void*>(&GetPluginDependencies),
		reinterpret_cast<void*>(&FindPluginResource)
};

ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
