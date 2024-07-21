#pragma once

#include <plugify/cpp_plugin.h>
#include <vector>
#include <string>
#include <cstdint>

// Generated from cross_call_worker.pplugin by https://github.com/untrustedmodders/cpp-lang-module/blob/main/generator/generator.py 

namespace cross_call_worker {
	inline void NoParamReturnVoid() {
		using NoParamReturnVoidFn = void (*)();
		static NoParamReturnVoidFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnVoid", reinterpret_cast<void**>(&__func));
		__func();
	}
	inline bool NoParamReturnBool() {
		using NoParamReturnBoolFn = bool (*)();
		static NoParamReturnBoolFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnBool", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char NoParamReturnChar8() {
		using NoParamReturnChar8Fn = char (*)();
		static NoParamReturnChar8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnChar8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char16_t NoParamReturnChar16() {
		using NoParamReturnChar16Fn = char16_t (*)();
		static NoParamReturnChar16Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnChar16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int8_t NoParamReturnInt8() {
		using NoParamReturnInt8Fn = int8_t (*)();
		static NoParamReturnInt8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int16_t NoParamReturnInt16() {
		using NoParamReturnInt16Fn = int16_t (*)();
		static NoParamReturnInt16Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int32_t NoParamReturnInt32() {
		using NoParamReturnInt32Fn = int32_t (*)();
		static NoParamReturnInt32Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int64_t NoParamReturnInt64() {
		using NoParamReturnInt64Fn = int64_t (*)();
		static NoParamReturnInt64Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint8_t NoParamReturnUInt8() {
		using NoParamReturnUInt8Fn = uint8_t (*)();
		static NoParamReturnUInt8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnUInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint16_t NoParamReturnUInt16() {
		using NoParamReturnUInt16Fn = uint16_t (*)();
		static NoParamReturnUInt16Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnUInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint32_t NoParamReturnUInt32() {
		using NoParamReturnUInt32Fn = uint32_t (*)();
		static NoParamReturnUInt32Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnUInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint64_t NoParamReturnUInt64() {
		using NoParamReturnUInt64Fn = uint64_t (*)();
		static NoParamReturnUInt64Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnUInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void* NoParamReturnPointer() {
		using NoParamReturnPointerFn = void* (*)();
		static NoParamReturnPointerFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnPointer", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline float NoParamReturnFloat() {
		using NoParamReturnFloatFn = float (*)();
		static NoParamReturnFloatFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnFloat", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline double NoParamReturnDouble() {
		using NoParamReturnDoubleFn = double (*)();
		static NoParamReturnDoubleFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnDouble", reinterpret_cast<void**>(&__func));
		return __func();
	}
	using NoParamReturnFunctionFunc = void (*)();
	inline NoParamReturnFunctionFunc NoParamReturnFunction() {
		using NoParamReturnFunctionFn = NoParamReturnFunctionFunc (*)();
		static NoParamReturnFunctionFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnFunction", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::string NoParamReturnString() {
		using NoParamReturnStringFn = std::string (*)();
		static NoParamReturnStringFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnString", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<bool> NoParamReturnArrayBool() {
		using NoParamReturnArrayBoolFn = std::vector<bool> (*)();
		static NoParamReturnArrayBoolFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayBool", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<char> NoParamReturnArrayChar8() {
		using NoParamReturnArrayChar8Fn = std::vector<char> (*)();
		static NoParamReturnArrayChar8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayChar8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<char16_t> NoParamReturnArrayChar16() {
		using NoParamReturnArrayChar16Fn = std::vector<char16_t> (*)();
		static NoParamReturnArrayChar16Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayChar16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int8_t> NoParamReturnArrayInt8() {
		using NoParamReturnArrayInt8Fn = std::vector<int8_t> (*)();
		static NoParamReturnArrayInt8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int16_t> NoParamReturnArrayInt16() {
		using NoParamReturnArrayInt16Fn = std::vector<int16_t> (*)();
		static NoParamReturnArrayInt16Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int32_t> NoParamReturnArrayInt32() {
		using NoParamReturnArrayInt32Fn = std::vector<int32_t> (*)();
		static NoParamReturnArrayInt32Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int64_t> NoParamReturnArrayInt64() {
		using NoParamReturnArrayInt64Fn = std::vector<int64_t> (*)();
		static NoParamReturnArrayInt64Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint8_t> NoParamReturnArrayUInt8() {
		using NoParamReturnArrayUInt8Fn = std::vector<uint8_t> (*)();
		static NoParamReturnArrayUInt8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt8", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint16_t> NoParamReturnArrayUInt16() {
		using NoParamReturnArrayUInt16Fn = std::vector<uint16_t> (*)();
		static NoParamReturnArrayUInt16Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt16", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint32_t> NoParamReturnArrayUInt32() {
		using NoParamReturnArrayUInt32Fn = std::vector<uint32_t> (*)();
		static NoParamReturnArrayUInt32Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt32", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint64_t> NoParamReturnArrayUInt64() {
		using NoParamReturnArrayUInt64Fn = std::vector<uint64_t> (*)();
		static NoParamReturnArrayUInt64Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayUInt64", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<void*> NoParamReturnArrayPointer() {
		using NoParamReturnArrayPointerFn = std::vector<void*> (*)();
		static NoParamReturnArrayPointerFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayPointer", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<float> NoParamReturnArrayFloat() {
		using NoParamReturnArrayFloatFn = std::vector<float> (*)();
		static NoParamReturnArrayFloatFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayFloat", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<double> NoParamReturnArrayDouble() {
		using NoParamReturnArrayDoubleFn = std::vector<double> (*)();
		static NoParamReturnArrayDoubleFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayDouble", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<std::string> NoParamReturnArrayString() {
		using NoParamReturnArrayStringFn = std::vector<std::string> (*)();
		static NoParamReturnArrayStringFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnArrayString", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Vector2 NoParamReturnVector2() {
		using NoParamReturnVector2Fn = plugify::Vector2 (*)();
		static NoParamReturnVector2Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnVector2", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Vector3 NoParamReturnVector3() {
		using NoParamReturnVector3Fn = plugify::Vector3 (*)();
		static NoParamReturnVector3Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnVector3", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Vector4 NoParamReturnVector4() {
		using NoParamReturnVector4Fn = plugify::Vector4 (*)();
		static NoParamReturnVector4Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnVector4", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Matrix4x4 NoParamReturnMatrix4x4() {
		using NoParamReturnMatrix4x4Fn = plugify::Matrix4x4 (*)();
		static NoParamReturnMatrix4x4Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.NoParamReturnMatrix4x4", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void Param1(int32_t a) {
		using Param1Fn = void (*)(int32_t);
		static Param1Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param1", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void Param2(int32_t a, float b) {
		using Param2Fn = void (*)(int32_t, float);
		static Param2Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param2", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void Param3(int32_t a, float b, double c) {
		using Param3Fn = void (*)(int32_t, float, double);
		static Param3Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param3", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void Param4(int32_t a, float b, double c, const plugify::Vector4& d) {
		using Param4Fn = void (*)(int32_t, float, double, const plugify::Vector4&);
		static Param4Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param4", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void Param5(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e) {
		using Param5Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&);
		static Param5Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param5", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void Param6(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f) {
		using Param6Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char);
		static Param6Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param6", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void Param7(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g) {
		using Param7Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&);
		static Param7Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param7", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void Param8(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h) {
		using Param8Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t);
		static Param8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param8", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void Param9(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k) {
		using Param9Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t, int16_t);
		static Param9Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param9", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void Param10(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k, void* l) {
		using Param10Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t, int16_t, void*);
		static Param10Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.Param10", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRef1(int32_t& a) {
		using ParamRef1Fn = void (*)(int32_t&);
		static ParamRef1Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef1", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void ParamRef2(int32_t& a, float& b) {
		using ParamRef2Fn = void (*)(int32_t&, float&);
		static ParamRef2Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef2", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void ParamRef3(int32_t& a, float& b, double& c) {
		using ParamRef3Fn = void (*)(int32_t&, float&, double&);
		static ParamRef3Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef3", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void ParamRef4(int32_t& a, float& b, double& c, plugify::Vector4& d) {
		using ParamRef4Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&);
		static ParamRef4Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef4", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void ParamRef5(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e) {
		using ParamRef5Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&);
		static ParamRef5Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef5", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void ParamRef6(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f) {
		using ParamRef6Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&);
		static ParamRef6Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef6", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void ParamRef7(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g) {
		using ParamRef7Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&);
		static ParamRef7Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef7", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void ParamRef8(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h) {
		using ParamRef8Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&);
		static ParamRef8Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef8", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void ParamRef9(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k) {
		using ParamRef9Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&, int16_t&);
		static ParamRef9Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef9", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void ParamRef10(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k, void*& l) {
		using ParamRef10Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&, int16_t&, void*&);
		static ParamRef10Fn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRef10", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRefVectors(std::vector<bool>& p1, std::vector<char>& p2, std::vector<char16_t>& p3, std::vector<int8_t>& p4, std::vector<int16_t>& p5, std::vector<int32_t>& p6, std::vector<int64_t>& p7, std::vector<uint8_t>& p8, std::vector<uint16_t>& p9, std::vector<uint32_t>& p10, std::vector<uint64_t>& p11, std::vector<void*>& p12, std::vector<float>& p13, std::vector<double>& p14, std::vector<std::string>& p15) {
		using ParamRefVectorsFn = void (*)(std::vector<bool>&, std::vector<char>&, std::vector<char16_t>&, std::vector<int8_t>&, std::vector<int16_t>&, std::vector<int32_t>&, std::vector<int64_t>&, std::vector<uint8_t>&, std::vector<uint16_t>&, std::vector<uint32_t>&, std::vector<uint64_t>&, std::vector<void*>&, std::vector<float>&, std::vector<double>&, std::vector<std::string>&);
		static ParamRefVectorsFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamRefVectors", reinterpret_cast<void**>(&__func));
		__func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}
	inline int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
		using ParamAllPrimitivesFn = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
		static ParamAllPrimitivesFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ParamAllPrimitives", reinterpret_cast<void**>(&__func));
		return __func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	}
	inline void ReverseCall(const std::string& test) {
		using ReverseCallFn = void (*)(const std::string&);
		static ReverseCallFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_worker.ReverseCall", reinterpret_cast<void**>(&__func));
		__func(test);
	}
}
