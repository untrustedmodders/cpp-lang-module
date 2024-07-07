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
