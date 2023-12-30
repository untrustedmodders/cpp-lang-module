#include "assembly.h"

namespace cpplm {
    std::unique_ptr<Assembly> Assembly::LoadFromPath(const std::filesystem::path& assemblyPath) {
        return nullptr;
    }

    std::string Assembly::GetError() {
        return {};
    }

    Assembly::Assembly(void* handle) : _handle{handle} {
    }

    Assembly::~Assembly() = default;

    void* Assembly::GetFunction(std::string_view functionName) const {
        return nullptr;
    }
}
