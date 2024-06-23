#pragma once

#include <string_view>
#include <string>
#include <filesystem>
#include <memory>

namespace cpplm {
	class Assembly {
	public:
		static std::unique_ptr<Assembly> LoadFromPath(const std::filesystem::path& assemblyPath, bool preferOwnSymbols = false);
		static std::string GetError();

		~Assembly();

		void* GetFunction(const char* functionName) const;
		template<class F> requires(std::is_pointer_v<F> && std::is_function_v<std::remove_pointer_t<F>>)
		F GetFunction(const char* functionName) const {
			return reinterpret_cast<F>(GetFunction(functionName));
		}

	private:
		explicit Assembly(void* handle);

	private:
		void* _handle{ nullptr };
	};
}
