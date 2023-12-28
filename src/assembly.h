#pragma once

#include <string_view>
#include <filesystem>

namespace cpplm {
    class Assembly {
    public:
        explicit Assembly(const std::filesystem::path& assemblyPath);
        ~Assembly();

        void* GetFunction(std::string_view functionName) const;
        template<class _Fn> requires(std::is_pointer_v<_Fn> && std::is_function_v<std::remove_pointer_t<_Fn>>)
        _Fn GetFunction(std::string_view functionName) const {
            return reinterpret_cast<_Fn>(GetFunction(functionName));
        }

    private:
        void* _handle{ nullptr };
    };
}
