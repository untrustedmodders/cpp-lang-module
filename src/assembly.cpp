#include "assembly.h"

namespace cpplm {
    Assembly::Assembly(const std::filesystem::path& assemblyPath) {

    }

    Assembly::~Assembly() = default;

    void* Assembly::GetFunction(std::string_view functionName) const {
        return nullptr;
    }
}
