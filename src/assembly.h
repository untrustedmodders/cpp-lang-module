#pragma once

#include <string_view>
#include <string>
#include <filesystem>
#include <memory>

namespace cpplm {
    class Assembly {
    public:
        static std::unique_ptr<Assembly> LoadFromPath(const std::filesystem::path& assemblyPath);
        static std::string GetError();

        ~Assembly();

        void* GetFunction(std::string_view functionName) const;
        template<class _Fn> requires(std::is_pointer_v<_Fn> && std::is_function_v<std::remove_pointer_t<_Fn>>)
        _Fn GetFunction(std::string_view functionName) const {
            return reinterpret_cast<_Fn>(GetFunction(functionName));
        }

    private:
        explicit Assembly(void* handle);

    private:
        void* _handle{ nullptr };
    };
}
