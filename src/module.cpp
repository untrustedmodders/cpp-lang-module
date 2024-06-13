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

    const int resultVersion = initFunc(const_cast<void**>(_pluginApi.data()), kApiVersion);
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
void* CppLanguageModule::GetNativeMethod(const std::string& method_name) const {
    if (const auto it = _nativesMap.find(method_name); it != _nativesMap.end()) {
        return std::get<void*>(*it);
    }
    _provider->Log(std::format(LOG_PREFIX "GetNativeMethod failed to find {}", method_name), Severity::Fatal);
    return nullptr;
}

namespace cpplm {
    CppLanguageModule g_cpplm;
}

void* GetNativeMethodImpl(const std::string& method_name) {
    return g_cpplm.GetNativeMethod(method_name);
}

const std::array<void*, 1> CppLanguageModule::_pluginApi = {
        reinterpret_cast<void*>(&GetNativeMethodImpl),
};

ILanguageModule* GetLanguageModule() {
	return &cpplm::g_cpplm;
}
