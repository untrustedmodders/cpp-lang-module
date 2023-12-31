#pragma once

#include <wizard/cpp_plugin.h>

namespace example_plugin {
	void MakePrint(int count) {
		using MakePrintFn = void (*)(int);
		static MakePrintFn func = reinterpret_cast<MakePrintFn>(wizard::GetMethod("example_plugin.MakePrint"));
		func(count);
	}
}
