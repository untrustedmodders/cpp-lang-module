#pragma once

namespace wizard {
	constexpr int kApiVersion = 1;

	using InitFunc = int (*)(void**, int);
	using StartFunc = void (*)();
	using EndFunc = void (*)();

	using GetMethodFn = void* (*)(std::string_view);
}
