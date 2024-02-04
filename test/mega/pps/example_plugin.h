#pragma once

#include <plugify/cpp_plugin.h>

namespace example_plugin {
	inline void MakePrint(int count, const std::string& message) {
		using MakePrintFn = void (*)(int, const std::string&);
		static auto func = reinterpret_cast<MakePrintFn>(plugify::GetMethod("example_plugin.MakePrint"));
		func(count, message);
	}
}
