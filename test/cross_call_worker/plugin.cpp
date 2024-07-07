#include <pps/cross_call_master.h>
#include <plugify/cpp_plugin.h>
#include <plugin_export.h>
#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <limits>
#include <cstdint>

class CrossCallWorker : public plugify::IPluginEntry {
};

CrossCallWorker g_plugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_plugin)

extern "C"
PLUGIN_API void NoParamReturnVoid() {
}

extern "C"
PLUGIN_API bool NoParamReturnBool() {
	return true;
}

extern "C"
PLUGIN_API char NoParamReturnChar8() {
	return std::numeric_limits<char>::max();
}

extern "C"
PLUGIN_API char16_t NoParamReturnChar16() {
	return std::numeric_limits<char16_t>::max();
}

extern "C"
PLUGIN_API int8_t NoParamReturnInt8() {
	return std::numeric_limits<int8_t>::max();
}

extern "C"
PLUGIN_API int16_t NoParamReturnInt16() {
	return std::numeric_limits<int16_t>::max();
}

extern "C"
PLUGIN_API int32_t NoParamReturnInt32() {
	return std::numeric_limits<int32_t>::max();
}

extern "C"
PLUGIN_API int64_t NoParamReturnInt64() {
	return std::numeric_limits<int64_t>::max();
}

extern "C"
PLUGIN_API uint8_t NoParamReturnUInt8() {
	return std::numeric_limits<uint8_t>::max();
}

extern "C"
PLUGIN_API uint16_t NoParamReturnUInt16() {
	return std::numeric_limits<uint16_t>::max();
}

extern "C"
PLUGIN_API uint32_t NoParamReturnUInt32() {
	return std::numeric_limits<uint32_t>::max();
}

extern "C"
PLUGIN_API uint64_t NoParamReturnUInt64() {
	return std::numeric_limits<uint64_t>::max();
}

extern "C"
PLUGIN_API void* NoParamReturnPointer() {
	return reinterpret_cast<void*>(0x1);
}

extern "C"
PLUGIN_API float NoParamReturnFloat() {
	return std::numeric_limits<float>::max();
}

extern "C"
PLUGIN_API double NoParamReturnDouble() {
	return std::numeric_limits<double>::max();
}

using NoParamReturnFunctionFunc = void (*)();

extern "C"
PLUGIN_API NoParamReturnFunctionFunc NoParamReturnFunction() {
	return nullptr;
}

extern "C"
PLUGIN_API void NoParamReturnString(std::string& stringRet) {
	std::construct_at(&stringRet, "Hello World");
}

extern "C"
PLUGIN_API void NoParamReturnArrayBool(std::vector<bool>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<bool>{true, false});
}

extern "C"
PLUGIN_API void NoParamReturnArrayChar8(std::vector<char>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<char>{'a', 'b', 'c', 'd'});
}

extern "C"
PLUGIN_API void NoParamReturnArrayChar16(std::vector<char16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<char16_t>{u'a', u'b', u'c', u'd'});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt8(std::vector<int8_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int8_t>{-3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt16(std::vector<int16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int16_t>{-4, -3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt32(std::vector<int32_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int32_t>{-5, -4, -3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt64(std::vector<int64_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt8(std::vector<uint8_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint8_t>{0, 1, 2, 3, 4, 5, 6, 7, 8});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt16(std::vector<uint16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint16_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt32(std::vector<uint32_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt64(std::vector<uint64_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
}

extern "C"
PLUGIN_API void NoParamReturnArrayPointer(std::vector<void*>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<void*>{reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2), reinterpret_cast<void*>(3)});
}

extern "C"
PLUGIN_API void NoParamReturnArrayFloat(std::vector<float>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<float>{-12.34f, 0.0f, 12.34f});
}

extern "C"
PLUGIN_API void NoParamReturnArrayDouble(std::vector<double>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<double>{-12.345, 0.0, 12.345});
}

extern "C"
PLUGIN_API void NoParamReturnArrayString(std::vector<std::string>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<std::string>{"1st string", "2nd string", "3rd element string (Should be big enough to avoid small string optimization)"});
}

extern "C"
PLUGIN_API plugify::Vector2 NoParamReturnVector2() {
	return {1.f, 2.f};
}

extern "C"
PLUGIN_API plugify::Vector3 NoParamReturnVector3() {
	return {1.f, 2.f, 3.f};
}

extern "C"
PLUGIN_API plugify::Vector4 NoParamReturnVector4() {
	return {1.f, 2.f, 3.f, 4.f};
}

extern "C"
PLUGIN_API plugify::Matrix4x4 NoParamReturnMatrix4x4() {
	return {1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f};
}

extern "C"
PLUGIN_API void Param1(int32_t a) {
	const auto buffer = std::format("{}", a);
}

extern "C"
PLUGIN_API void Param2(int32_t a, float b) {
	const auto buffer = std::format("{}{:.2f}", a, b);
}

extern "C"
PLUGIN_API void Param3(int32_t a, float b, double c) {
	const auto buffer = std::format("{}{:.2f}{:.2f}", a, b, c);
}

extern "C"
PLUGIN_API void Param4(int32_t a, float b, double c, const plugify::Vector4& d) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}", a, b, c, d.x, d.w);
}

extern "C"
PLUGIN_API void Param5(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0});
}

extern "C"
PLUGIN_API void Param6(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f));
}

extern "C"
PLUGIN_API void Param7(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g);
}

extern "C"
PLUGIN_API void Param8(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h));
}

extern "C"
PLUGIN_API void Param9(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k);
}

extern "C"
PLUGIN_API void Param10(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k, void* l) {
	const auto buffer = std::format("{}{:.2f}{:.2f}{:.1f}{:.1f}{}{}{}{}{}{}{}", a, b, c, d.x, d.w, e.size(), e.size() == 3 ? e[2] : int64_t{0}, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k, l);
}

extern "C"
PLUGIN_API void ParamRef1(int32_t& a) {
	a = 42;
}

extern "C"
PLUGIN_API void ParamRef2(int32_t& a, float& b) {
	a = 10;
	b = 3.14f;
}

extern "C"
PLUGIN_API void ParamRef3(int32_t& a, float& b, double& c) {
	a = -20;
	b = 2.718f;
	c = 3.14159;
}

extern "C"
PLUGIN_API void ParamRef4(int32_t& a, float& b, double& c, plugify::Vector4& d) {
	a = 100;
	b = -5.55f;
	c = 1.618;
	d = {1.0f, 2.0f, 3.0f, 4.0f};
}

extern "C"
PLUGIN_API void ParamRef5(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e) {
	a = 500;
	b = -10.5f;
	c = 2.71828;
	d = {-1.0f, -2.0f, -3.0f, -4.0f};
	e = {-6, -5, -4, -3, -2, -1, 0, 1};
}

extern "C"
PLUGIN_API void ParamRef6(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f) {
	a = 750;
	b = 20.0f;
	c = 1.23456;
	d = {10.0f, 20.0f, 30.0f, 40.0f};
	e = {-6, -5, -4};
	f = 'Z';
}

extern "C"
PLUGIN_API void ParamRef7(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g) {
	a = -1000;
	b = 3.0f;
	c = -1.0;
	d = {100.0f, 200.0f, 300.0f, 400.0f};
	e = {-6, -5, -4, -3};
	f = 'Y';
	g = "Hello, World!";
}

extern "C"
PLUGIN_API void ParamRef8(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h) {
	a = 999;
	b = -7.5f;
	c = 0.123456;
	d = {-100.0f, -200.0f, -300.0f, -400.0f};
	e = {-6, -5, -4, -3, -2, -1};
	f = 'X';
	g = "Goodbye, World!";
	h = 'A';
}

extern "C"
PLUGIN_API void ParamRef9(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k) {
	a = -1234;
	b = 123.45f;
	c = -678.9;
	d = {987.65f, 432.1f, 123.456f, 789.123f};
	e = {-6, -5, -4, -3, -2, -1, 0, 1, 5, 9};
	f = 'W';
	g = "Testing, 1 2 3";
	h = 'B';
	k = 42;
}

extern "C"
PLUGIN_API void ParamRef10(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k, void*& l) {
	a = 987;
	b = -0.123f;
	c = 456.789;
	d = {-123.456f, 0.987f, 654.321f, -789.123f};
	e = {-6, -5, -4, -3, -2, -1, 0, 1, 5, 9, 4, -7};
	f = 'V';
	g = "Another string";
	h = 'C';
	k = -444;
	l = reinterpret_cast<void*>(0x12345678);
}

extern "C"
PLUGIN_API void ParamRefVectors(std::vector<bool>& p1, std::vector<char>& p2, std::vector<char16_t>& p3, std::vector<int8_t>& p4, std::vector<int16_t>& p5,
	std::vector<int32_t>& p6, std::vector<int64_t>& p7, std::vector<uint8_t>& p8, std::vector<uint16_t>& p9, std::vector<uint32_t>& p10, std::vector<uint64_t>& p11,
	std::vector<void*>& p12, std::vector<float>& p13, std::vector<double>& p14, std::vector<std::string>& p15
) {
	p1 = {true};
	p2 = {'a', 'b', 'c'};
	p3 = {'d', 'e', 'f'};
	p4 = {-3, -2, -1, 0, 1, 2, 3};
	p5 = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
	p6 = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
	p7 = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
	p8 = {0, 1, 2, 3, 4, 5, 6, 7};
	p9 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
	p10 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	p11 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	p12 = {reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2)};
	p13 = {-12.34f, 0.0f, 12.34f};
	p14 = {-12.345, 0.0, 12.345};
	p15 = {"1", "12", "123", "1234", "12345", "123456"};
}

extern "C"
PLUGIN_API int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10,
	uint64_t p11, void* p12, float p13, double p14
) {
	const auto buffer = std::format("{}{}{}{}{}{}{}{}{}{}{}{}{:.3f}{:.3f}", p1, static_cast<uint8_t>(p2), static_cast<uint8_t>(p3), p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	return 56;
}

extern "C"
PLUGIN_API void ReverseCall(const std::string& test) {
	if (test == "NoParamReturnVoid") {
		cross_call_master::NoParamReturnVoidCallback();
	} else if (test == "NoParamReturnBool") {
		const auto result = cross_call_master::NoParamReturnBoolCallback();
		cross_call_master::ReverseReturn(result == true ? "true" : (result == false ? "false" : "<wrong return>"));
	} else if (test == "NoParamReturnChar8") {
		const auto result = cross_call_master::NoParamReturnChar8Callback();
		cross_call_master::ReverseReturn(std::format("{}", static_cast<uint8_t>(result)));
	} else if (test == "NoParamReturnChar16") {
		const auto result = cross_call_master::NoParamReturnChar16Callback();
		cross_call_master::ReverseReturn(std::format("{}", static_cast<uint16_t>(result)));
	} else if (test == "NoParamReturnInt8") {
		const auto result = cross_call_master::NoParamReturnInt8Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnInt16") {
		const auto result = cross_call_master::NoParamReturnInt16Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnInt32") {
		const auto result = cross_call_master::NoParamReturnInt32Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnInt64") {
		const auto result = cross_call_master::NoParamReturnInt64Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnUInt8") {
		const auto result = cross_call_master::NoParamReturnUInt8Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnUInt16") {
		const auto result = cross_call_master::NoParamReturnUInt16Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnUInt32") {
		const auto result = cross_call_master::NoParamReturnUInt32Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnUInt64") {
		const auto result = cross_call_master::NoParamReturnUInt64Callback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnPointer") {
		const auto result = cross_call_master::NoParamReturnPointerCallback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnFloat") {
		const auto result = cross_call_master::NoParamReturnFloatCallback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnDouble") {
		const auto result = cross_call_master::NoParamReturnDoubleCallback();
		cross_call_master::ReverseReturn(std::format("{}", result));
	} else if (test == "NoParamReturnFunction") {
		const auto result = cross_call_master::NoParamReturnFunctionCallback();
		cross_call_master::ReverseReturn(result ? std::format("{}", result()) : "<null function pointer>");
	} else if (test == "NoParamReturnString") {
		const auto result = cross_call_master::NoParamReturnStringCallback();
		cross_call_master::ReverseReturn(result);
	} else if (test == "NoParamReturnArrayBool") {
		const auto result = cross_call_master::NoParamReturnArrayBoolCallback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", static_cast<bool>(result[0]));
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", static_cast<bool>(*it));
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayChar8") {
		const auto result = cross_call_master::NoParamReturnArrayChar8Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", static_cast<uint8_t>(result[0]));
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", static_cast<uint8_t>(*it));
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayChar16") {
		const auto result = cross_call_master::NoParamReturnArrayChar16Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", static_cast<uint16_t>(result[0]));
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", static_cast<uint16_t>(*it));
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayInt8") {
		const auto result = cross_call_master::NoParamReturnArrayInt8Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayInt16") {
		const auto result = cross_call_master::NoParamReturnArrayInt16Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayInt32") {
		const auto result = cross_call_master::NoParamReturnArrayInt32Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayInt64") {
		const auto result = cross_call_master::NoParamReturnArrayInt64Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayUInt8") {
		const auto result = cross_call_master::NoParamReturnArrayUInt8Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayUInt16") {
		const auto result = cross_call_master::NoParamReturnArrayUInt16Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayUInt32") {
		const auto result = cross_call_master::NoParamReturnArrayUInt32Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayUInt64") {
		const auto result = cross_call_master::NoParamReturnArrayUInt64Callback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayPointer") {
		const auto result = cross_call_master::NoParamReturnArrayPointerCallback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayFloat") {
		const auto result = cross_call_master::NoParamReturnArrayFloatCallback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayDouble") {
		const auto result = cross_call_master::NoParamReturnArrayDoubleCallback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("{}", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnArrayString") {
		const auto result = cross_call_master::NoParamReturnArrayStringCallback();
		std::string result_formated;
		if (!result.empty()) {
			result_formated = std::format("'{}'", result[0]);
			for (auto it = std::next(result.begin()); it != result.end(); ++it) {
				std::format_to(std::back_inserter(result_formated), ", '{}'", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}", result_formated));
	} else if (test == "NoParamReturnVector2") {
		const auto result = cross_call_master::NoParamReturnVector2Callback();
		cross_call_master::ReverseReturn(std::format("{{{}, {}}}", result.x, result.y));
	} else if (test == "NoParamReturnVector3") {
		const auto result = cross_call_master::NoParamReturnVector3Callback();
		cross_call_master::ReverseReturn(std::format("{{{}, {}, {}}}", result.x, result.y, result.z));
	} else if (test == "NoParamReturnVector4") {
		const auto result = cross_call_master::NoParamReturnVector4Callback();
		cross_call_master::ReverseReturn(std::format("{{{}, {}, {}, {}}}", result.x, result.y, result.z, result.w));
	} else if (test == "NoParamReturnMatrix4x4") {
		const auto result = cross_call_master::NoParamReturnMatrix4x4Callback();
		cross_call_master::ReverseReturn(std::format("{{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}",
			result.m[0][0], result.m[0][1], result.m[0][2], result.m[0][3],
			result.m[1][0], result.m[1][1], result.m[1][2], result.m[1][3],
			result.m[2][0], result.m[2][1], result.m[2][2], result.m[2][3],
			result.m[3][0], result.m[3][1], result.m[3][2], result.m[3][3]));
	} else if (test == "Param1") {
		cross_call_master::Param1Callback(999);
	} else if (test == "Param2") {
		cross_call_master::Param2Callback(888, 9.9f);
	} else if (test == "Param3") {
		cross_call_master::Param3Callback(777, 8.8f, 9.8765);
	} else if (test == "Param4") {
		cross_call_master::Param4Callback(666, 7.7f, 8.7659, {100.1f, 200.2f, 300.3f, 400.4f});
	} else if (test == "Param5") {
		cross_call_master::Param5Callback(555, 6.6f, 7.6598, {-105.1f, -205.2f, -305.3f, -405.4f}, {});
	} else if (test == "Param6") {
		cross_call_master::Param6Callback(444, 5.5f, 6.5987, {110.1f, 210.2f, 310.3f, 410.4f}, {90000, -100, 20000}, 'A');
	} else if (test == "Param7") {
		cross_call_master::Param7Callback(333, 4.4f, 5.9876, {-115.1f, -215.2f, -315.3f, -415.4f}, {800000, 30000, -4000000}, 'B', "red gold");
	} else if (test == "Param8") {
		cross_call_master::Param8Callback(222, 3.3f, 1.2345, {120.1f, 220.2f, 320.3f, 420.4f}, {7000000, 5000000, -600000000}, 'C', "blue ice", u'Z');
	} else if (test == "Param9") {
		cross_call_master::Param9Callback(111, 2.2f, 5.1234, {-125.1f, -225.2f, -325.3f, -425.4f}, {60000000, -700000000, 80000000000}, 'D', "pink metal", u'Y', -100);
	} else if (test == "Param10") {
		cross_call_master::Param10Callback(1234, 1.1f, 4.5123, {130.1f, 230.2f, 330.3f, 430.4f}, {500000000, 90000000000, 1000000000000}, 'E', "green wood", u'X', -200, reinterpret_cast<void*>(0xabebaLL));
	} else if (test == "ParamRef1") {
		int32_t a{};
		cross_call_master::ParamRef1Callback(a);
		cross_call_master::ReverseReturn(std::format("{}", a));
	} else if (test == "ParamRef2") {
		int32_t a{};
		float b{};
		cross_call_master::ParamRef2Callback(a, b);
		cross_call_master::ReverseReturn(std::format("{}|{}", a, b));
	} else if (test == "ParamRef3") {
		int32_t a{};
		float b{};
		double c{};
		cross_call_master::ParamRef3Callback(a, b, c);
		cross_call_master::ReverseReturn(std::format("{}|{}|{}", a, b, c));
	} else if (test == "ParamRef4") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		cross_call_master::ParamRef4Callback(a, b, c, d);
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}", a, b, c, d.x, d.y, d.z, d.w));
	} else if (test == "ParamRef5") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		std::vector<int64_t> e{};
		cross_call_master::ParamRef5Callback(a, b, c, d, e);
		std::string e_formated;
		if (!e.empty()) {
			e_formated = std::format("{}", e[0]);
			for (auto it = std::next(e.begin()); it != e.end(); ++it) {
				std::format_to(std::back_inserter(e_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}", a, b, c, d.x, d.y, d.z, d.w, e_formated));
	} else if (test == "ParamRef6") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		std::vector<int64_t> e{};
		char f{};
		cross_call_master::ParamRef6Callback(a, b, c, d, e, f);
		std::string e_formated;
		if (!e.empty()) {
			e_formated = std::format("{}", e[0]);
			for (auto it = std::next(e.begin()); it != e.end(); ++it) {
				std::format_to(std::back_inserter(e_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
													 static_cast<uint8_t>(f)));
	} else if (test == "ParamRef7") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		std::vector<int64_t> e{};
		char f{};
		std::string g{};
		cross_call_master::ParamRef7Callback(a, b, c, d, e, f, g);
		std::string e_formated;
		if (!e.empty()) {
			e_formated = std::format("{}", e[0]);
			for (auto it = std::next(e.begin()); it != e.end(); ++it) {
				std::format_to(std::back_inserter(e_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
													 static_cast<uint8_t>(f), g));
	} else if (test == "ParamRef8") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		std::vector<int64_t> e{};
		char f{};
		std::string g{};
		char16_t h{};
		cross_call_master::ParamRef8Callback(a, b, c, d, e, f, g, h);
		std::string e_formated;
		if (!e.empty()) {
			e_formated = std::format("{}", e[0]);
			for (auto it = std::next(e.begin()); it != e.end(); ++it) {
				std::format_to(std::back_inserter(e_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
													 static_cast<uint8_t>(f), g, static_cast<uint16_t>(h)));
	} else if (test == "ParamRef9") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		std::vector<int64_t> e{};
		char f{};
		std::string g{};
		char16_t h{};
		int16_t k{};
		cross_call_master::ParamRef9Callback(a, b, c, d, e, f, g, h, k);
		std::string e_formated;
		if (!e.empty()) {
			e_formated = std::format("{}", e[0]);
			for (auto it = std::next(e.begin()); it != e.end(); ++it) {
				std::format_to(std::back_inserter(e_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
													 static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k));
	} else if (test == "ParamRef10") {
		int32_t a{};
		float b{};
		double c{};
		plugify::Vector4 d{};
		std::vector<int64_t> e{};
		char f{};
		std::string g{};
		char16_t h{};
		int16_t k{};
		void* l{};
		cross_call_master::ParamRef10Callback(a, b, c, d, e, f, g, h, k, l);
		std::string e_formated;
		if (!e.empty()) {
			e_formated = std::format("{}", e[0]);
			for (auto it = std::next(e.begin()); it != e.end(); ++it) {
				std::format_to(std::back_inserter(e_formated), ", {}", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated,
													 static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k, l));
	} else if (test == "ParamRefArrays") {
		std::vector<bool> p1{true};
		std::vector<char> p2{'A'};
		std::vector<char16_t> p3{u'A'};
		std::vector<int8_t> p4{-1};
		std::vector<int16_t> p5{-1};
		std::vector<int32_t> p6{-1};
		std::vector<int64_t> p7{-1LL};
		std::vector<uint8_t> p8{0};
		std::vector<uint16_t> p9{0};
		std::vector<uint32_t> p10{0};
		std::vector<uint64_t> p11{0};
		std::vector<void*> p12{nullptr};
		std::vector<float> p13{1.0f};
		std::vector<double> p14{1.0};
		std::vector<std::string> p15{"Hi"};
		cross_call_master::ParamRefVectorsCallback(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
		std::string p1_formated;
		if (!p1.empty()) {
			p1_formated = std::format("{}", static_cast<bool>(p1[0]));
			for (auto it = std::next(p1.begin()); it != p1.end(); ++it) {
				std::format_to(std::back_inserter(p1_formated), ", {}", static_cast<bool>(*it));
			}
		}
		std::string p2_formated;
		if (!p2.empty()) {
			p2_formated = std::format("{}", static_cast<uint8_t>(p2[0]));
			for (auto it = std::next(p2.begin()); it != p2.end(); ++it) {
				std::format_to(std::back_inserter(p2_formated), ", {}", static_cast<uint8_t>(*it));
			}
		}
		std::string p3_formated;
		if (!p3.empty()) {
			p3_formated = std::format("{}", static_cast<uint16_t>(p3[0]));
			for (auto it = std::next(p3.begin()); it != p3.end(); ++it) {
				std::format_to(std::back_inserter(p3_formated), ", {}", static_cast<uint16_t>(*it));
			}
		}
		std::string p4_formated;
		if (!p4.empty()) {
			p4_formated = std::format("{}", p4[0]);
			for (auto it = std::next(p4.begin()); it != p4.end(); ++it) {
				std::format_to(std::back_inserter(p4_formated), ", {}", *it);
			}
		}
		std::string p5_formated;
		if (!p5.empty()) {
			p5_formated = std::format("{}", p5[0]);
			for (auto it = std::next(p5.begin()); it != p5.end(); ++it) {
				std::format_to(std::back_inserter(p5_formated), ", {}", *it);
			}
		}
		std::string p6_formated;
		if (!p6.empty()) {
			p6_formated = std::format("{}", p6[0]);
			for (auto it = std::next(p6.begin()); it != p6.end(); ++it) {
				std::format_to(std::back_inserter(p6_formated), ", {}", *it);
			}
		}
		std::string p7_formated;
		if (!p7.empty()) {
			p7_formated = std::format("{}", p7[0]);
			for (auto it = std::next(p7.begin()); it != p7.end(); ++it) {
				std::format_to(std::back_inserter(p7_formated), ", {}", *it);
			}
		}
		std::string p8_formated;
		if (!p8.empty()) {
			p8_formated = std::format("{}", p8[0]);
			for (auto it = std::next(p8.begin()); it != p8.end(); ++it) {
				std::format_to(std::back_inserter(p8_formated), ", {}", *it);
			}
		}
		std::string p9_formated;
		if (!p9.empty()) {
			p9_formated = std::format("{}", p9[0]);
			for (auto it = std::next(p9.begin()); it != p9.end(); ++it) {
				std::format_to(std::back_inserter(p9_formated), ", {}", *it);
			}
		}
		std::string p10_formated;
		if (!p10.empty()) {
			p10_formated = std::format("{}", p10[0]);
			for (auto it = std::next(p10.begin()); it != p10.end(); ++it) {
				std::format_to(std::back_inserter(p10_formated), ", {}", *it);
			}
		}
		std::string p11_formated;
		if (!p11.empty()) {
			p11_formated = std::format("{}", p11[0]);
			for (auto it = std::next(p11.begin()); it != p11.end(); ++it) {
				std::format_to(std::back_inserter(p11_formated), ", {}", *it);
			}
		}
		std::string p12_formated;
		if (!p12.empty()) {
			p12_formated = std::format("{}", p12[0]);
			for (auto it = std::next(p12.begin()); it != p12.end(); ++it) {
				std::format_to(std::back_inserter(p12_formated), ", {}", *it);
			}
		}
		std::string p13_formated;
		if (!p13.empty()) {
			p13_formated = std::format("{}", p13[0]);
			for (auto it = std::next(p13.begin()); it != p13.end(); ++it) {
				std::format_to(std::back_inserter(p13_formated), ", {}", *it);
			}
		}
		std::string p14_formated;
		if (!p14.empty()) {
			p14_formated = std::format("{}", p14[0]);
			for (auto it = std::next(p14.begin()); it != p14.end(); ++it) {
				std::format_to(std::back_inserter(p14_formated), ", {}", *it);
			}
		}
		std::string p15_formated;
		if (!p15.empty()) {
			p15_formated = std::format("'{}'", p15[0]);
			for (auto it = std::next(p15.begin()); it != p15.end(); ++it) {
				std::format_to(std::back_inserter(p15_formated), ", '{}'", *it);
			}
		}
		cross_call_master::ReverseReturn(std::format("{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}|{{{}}}",
													 p1_formated, p2_formated, p3_formated, p4_formated, p5_formated, p6_formated, p7_formated, p8_formated,
													 p9_formated, p10_formated, p11_formated, p12_formated, p13_formated, p14_formated, p15_formated));
	} else if (test == "ParamAllPrimitives") {
		const auto result = cross_call_master::ParamAllPrimitivesCallback(true, '%', u'☢', -1, -1000, -1000000, -1000000000000LL, 200, 50000, 3000000000LL, 9999999999LL,
		 																  reinterpret_cast<void*>(0xfedcbaabcdefLL), 0.001f, 987654.456789);
		cross_call_master::ReverseReturn(std::format("{}", result));
	}
}
