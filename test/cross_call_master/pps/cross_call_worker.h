#pragma once

#include <plugify/cpp_plugin.h>
#include <vector>
#include <string>
#include <cstdint>

// Generated from cross_call_worker.pplugin by https://github.com/untrustedmodders/cpp-lang-module/blob/main/generator/generator.py 

namespace cross_call_worker {
	inline void NoParamReturnVoid() {
		using NoParamReturnVoidFn = void (*)();
		static auto __func = reinterpret_cast<NoParamReturnVoidFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnVoid"));
		__func();
	}
	inline bool NoParamReturnBool() {
		using NoParamReturnBoolFn = bool (*)();
		static auto __func = reinterpret_cast<NoParamReturnBoolFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnBool"));
		return __func();
	}
	inline char NoParamReturnChar8() {
		using NoParamReturnChar8Fn = char (*)();
		static auto __func = reinterpret_cast<NoParamReturnChar8Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnChar8"));
		return __func();
	}
	inline char16_t NoParamReturnChar16() {
		using NoParamReturnChar16Fn = char16_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnChar16Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnChar16"));
		return __func();
	}
	inline int8_t NoParamReturnInt8() {
		using NoParamReturnInt8Fn = int8_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnInt8Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnInt8"));
		return __func();
	}
	inline int16_t NoParamReturnInt16() {
		using NoParamReturnInt16Fn = int16_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnInt16Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnInt16"));
		return __func();
	}
	inline int32_t NoParamReturnInt32() {
		using NoParamReturnInt32Fn = int32_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnInt32Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnInt32"));
		return __func();
	}
	inline int64_t NoParamReturnInt64() {
		using NoParamReturnInt64Fn = int64_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnInt64Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnInt64"));
		return __func();
	}
	inline uint8_t NoParamReturnUInt8() {
		using NoParamReturnUInt8Fn = uint8_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnUInt8Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnUInt8"));
		return __func();
	}
	inline uint16_t NoParamReturnUInt16() {
		using NoParamReturnUInt16Fn = uint16_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnUInt16Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnUInt16"));
		return __func();
	}
	inline uint32_t NoParamReturnUInt32() {
		using NoParamReturnUInt32Fn = uint32_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnUInt32Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnUInt32"));
		return __func();
	}
	inline uint64_t NoParamReturnUInt64() {
		using NoParamReturnUInt64Fn = uint64_t (*)();
		static auto __func = reinterpret_cast<NoParamReturnUInt64Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnUInt64"));
		return __func();
	}
	inline void* NoParamReturnPointer() {
		using NoParamReturnPointerFn = void* (*)();
		static auto __func = reinterpret_cast<NoParamReturnPointerFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnPointer"));
		return __func();
	}
	inline float NoParamReturnFloat() {
		using NoParamReturnFloatFn = float (*)();
		static auto __func = reinterpret_cast<NoParamReturnFloatFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnFloat"));
		return __func();
	}
	inline double NoParamReturnDouble() {
		using NoParamReturnDoubleFn = double (*)();
		static auto __func = reinterpret_cast<NoParamReturnDoubleFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnDouble"));
		return __func();
	}
	using NoParamReturnFunctionFunc = void (*)();
	inline NoParamReturnFunctionFunc NoParamReturnFunction() {
		using NoParamReturnFunctionFn = NoParamReturnFunctionFunc (*)();
		static auto __func = reinterpret_cast<NoParamReturnFunctionFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnFunction"));
		return __func();
	}
	inline std::string NoParamReturnString() {
		using NoParamReturnStringFn = std::string (*)();
		static auto __func = reinterpret_cast<NoParamReturnStringFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnString"));
		return __func();
	}
	inline std::vector<bool> NoParamReturnArrayBool() {
		using NoParamReturnArrayBoolFn = std::vector<bool> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayBoolFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayBool"));
		return __func();
	}
	inline std::vector<char> NoParamReturnArrayChar8() {
		using NoParamReturnArrayChar8Fn = std::vector<char> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayChar8Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayChar8"));
		return __func();
	}
	inline std::vector<char16_t> NoParamReturnArrayChar16() {
		using NoParamReturnArrayChar16Fn = std::vector<char16_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayChar16Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayChar16"));
		return __func();
	}
	inline std::vector<int8_t> NoParamReturnArrayInt8() {
		using NoParamReturnArrayInt8Fn = std::vector<int8_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayInt8Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayInt8"));
		return __func();
	}
	inline std::vector<int16_t> NoParamReturnArrayInt16() {
		using NoParamReturnArrayInt16Fn = std::vector<int16_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayInt16Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayInt16"));
		return __func();
	}
	inline std::vector<int32_t> NoParamReturnArrayInt32() {
		using NoParamReturnArrayInt32Fn = std::vector<int32_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayInt32Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayInt32"));
		return __func();
	}
	inline std::vector<int64_t> NoParamReturnArrayInt64() {
		using NoParamReturnArrayInt64Fn = std::vector<int64_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayInt64Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayInt64"));
		return __func();
	}
	inline std::vector<uint8_t> NoParamReturnArrayUInt8() {
		using NoParamReturnArrayUInt8Fn = std::vector<uint8_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayUInt8Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayUInt8"));
		return __func();
	}
	inline std::vector<uint16_t> NoParamReturnArrayUInt16() {
		using NoParamReturnArrayUInt16Fn = std::vector<uint16_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayUInt16Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayUInt16"));
		return __func();
	}
	inline std::vector<uint32_t> NoParamReturnArrayUInt32() {
		using NoParamReturnArrayUInt32Fn = std::vector<uint32_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayUInt32Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayUInt32"));
		return __func();
	}
	inline std::vector<uint64_t> NoParamReturnArrayUInt64() {
		using NoParamReturnArrayUInt64Fn = std::vector<uint64_t> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayUInt64Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayUInt64"));
		return __func();
	}
	inline std::vector<void*> NoParamReturnArrayPointer() {
		using NoParamReturnArrayPointerFn = std::vector<void*> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayPointerFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayPointer"));
		return __func();
	}
	inline std::vector<float> NoParamReturnArrayFloat() {
		using NoParamReturnArrayFloatFn = std::vector<float> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayFloatFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayFloat"));
		return __func();
	}
	inline std::vector<double> NoParamReturnArrayDouble() {
		using NoParamReturnArrayDoubleFn = std::vector<double> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayDoubleFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayDouble"));
		return __func();
	}
	inline std::vector<std::string> NoParamReturnArrayString() {
		using NoParamReturnArrayStringFn = std::vector<std::string> (*)();
		static auto __func = reinterpret_cast<NoParamReturnArrayStringFn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnArrayString"));
		return __func();
	}
	inline plugify::Vector2 NoParamReturnVector2() {
		using NoParamReturnVector2Fn = plugify::Vector2 (*)();
		static auto __func = reinterpret_cast<NoParamReturnVector2Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnVector2"));
		return __func();
	}
	inline plugify::Vector3 NoParamReturnVector3() {
		using NoParamReturnVector3Fn = plugify::Vector3 (*)();
		static auto __func = reinterpret_cast<NoParamReturnVector3Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnVector3"));
		return __func();
	}
	inline plugify::Vector4 NoParamReturnVector4() {
		using NoParamReturnVector4Fn = plugify::Vector4 (*)();
		static auto __func = reinterpret_cast<NoParamReturnVector4Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnVector4"));
		return __func();
	}
	inline plugify::Matrix4x4 NoParamReturnMatrix4x4() {
		using NoParamReturnMatrix4x4Fn = plugify::Matrix4x4 (*)();
		static auto __func = reinterpret_cast<NoParamReturnMatrix4x4Fn>(plugify::GetMethodPtr("cross_call_worker.NoParamReturnMatrix4x4"));
		return __func();
	}
	inline void Param1(int32_t a) {
		using Param1Fn = void (*)(int32_t);
		static auto __func = reinterpret_cast<Param1Fn>(plugify::GetMethodPtr("cross_call_worker.Param1"));
		__func(a);
	}
	inline void Param2(int32_t a, float b) {
		using Param2Fn = void (*)(int32_t, float);
		static auto __func = reinterpret_cast<Param2Fn>(plugify::GetMethodPtr("cross_call_worker.Param2"));
		__func(a, b);
	}
	inline void Param3(int32_t a, float b, double c) {
		using Param3Fn = void (*)(int32_t, float, double);
		static auto __func = reinterpret_cast<Param3Fn>(plugify::GetMethodPtr("cross_call_worker.Param3"));
		__func(a, b, c);
	}
	inline void Param4(int32_t a, float b, double c, const plugify::Vector4& d) {
		using Param4Fn = void (*)(int32_t, float, double, const plugify::Vector4&);
		static auto __func = reinterpret_cast<Param4Fn>(plugify::GetMethodPtr("cross_call_worker.Param4"));
		__func(a, b, c, d);
	}
	inline void Param5(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e) {
		using Param5Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&);
		static auto __func = reinterpret_cast<Param5Fn>(plugify::GetMethodPtr("cross_call_worker.Param5"));
		__func(a, b, c, d, e);
	}
	inline void Param6(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f) {
		using Param6Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char);
		static auto __func = reinterpret_cast<Param6Fn>(plugify::GetMethodPtr("cross_call_worker.Param6"));
		__func(a, b, c, d, e, f);
	}
	inline void Param7(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g) {
		using Param7Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&);
		static auto __func = reinterpret_cast<Param7Fn>(plugify::GetMethodPtr("cross_call_worker.Param7"));
		__func(a, b, c, d, e, f, g);
	}
	inline void Param8(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h) {
		using Param8Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t);
		static auto __func = reinterpret_cast<Param8Fn>(plugify::GetMethodPtr("cross_call_worker.Param8"));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void Param9(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k) {
		using Param9Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t, int16_t);
		static auto __func = reinterpret_cast<Param9Fn>(plugify::GetMethodPtr("cross_call_worker.Param9"));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void Param10(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k, void* l) {
		using Param10Fn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t, int16_t, void*);
		static auto __func = reinterpret_cast<Param10Fn>(plugify::GetMethodPtr("cross_call_worker.Param10"));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRef1(int32_t& a) {
		using ParamRef1Fn = void (*)(int32_t&);
		static auto __func = reinterpret_cast<ParamRef1Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef1"));
		__func(a);
	}
	inline void ParamRef2(int32_t& a, float& b) {
		using ParamRef2Fn = void (*)(int32_t&, float&);
		static auto __func = reinterpret_cast<ParamRef2Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef2"));
		__func(a, b);
	}
	inline void ParamRef3(int32_t& a, float& b, double& c) {
		using ParamRef3Fn = void (*)(int32_t&, float&, double&);
		static auto __func = reinterpret_cast<ParamRef3Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef3"));
		__func(a, b, c);
	}
	inline void ParamRef4(int32_t& a, float& b, double& c, plugify::Vector4& d) {
		using ParamRef4Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&);
		static auto __func = reinterpret_cast<ParamRef4Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef4"));
		__func(a, b, c, d);
	}
	inline void ParamRef5(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e) {
		using ParamRef5Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&);
		static auto __func = reinterpret_cast<ParamRef5Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef5"));
		__func(a, b, c, d, e);
	}
	inline void ParamRef6(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f) {
		using ParamRef6Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&);
		static auto __func = reinterpret_cast<ParamRef6Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef6"));
		__func(a, b, c, d, e, f);
	}
	inline void ParamRef7(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g) {
		using ParamRef7Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&);
		static auto __func = reinterpret_cast<ParamRef7Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef7"));
		__func(a, b, c, d, e, f, g);
	}
	inline void ParamRef8(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h) {
		using ParamRef8Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&);
		static auto __func = reinterpret_cast<ParamRef8Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef8"));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void ParamRef9(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k) {
		using ParamRef9Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&, int16_t&);
		static auto __func = reinterpret_cast<ParamRef9Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef9"));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void ParamRef10(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k, void*& l) {
		using ParamRef10Fn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&, int16_t&, void*&);
		static auto __func = reinterpret_cast<ParamRef10Fn>(plugify::GetMethodPtr("cross_call_worker.ParamRef10"));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRefVectors(std::vector<bool>& p1, std::vector<char>& p2, std::vector<char16_t>& p3, std::vector<int8_t>& p4, std::vector<int16_t>& p5, std::vector<int32_t>& p6, std::vector<int64_t>& p7, std::vector<uint8_t>& p8, std::vector<uint16_t>& p9, std::vector<uint32_t>& p10, std::vector<uint64_t>& p11, std::vector<void*>& p12, std::vector<float>& p13, std::vector<double>& p14, std::vector<std::string>& p15) {
		using ParamRefVectorsFn = void (*)(std::vector<bool>&, std::vector<char>&, std::vector<char16_t>&, std::vector<int8_t>&, std::vector<int16_t>&, std::vector<int32_t>&, std::vector<int64_t>&, std::vector<uint8_t>&, std::vector<uint16_t>&, std::vector<uint32_t>&, std::vector<uint64_t>&, std::vector<void*>&, std::vector<float>&, std::vector<double>&, std::vector<std::string>&);
		static auto __func = reinterpret_cast<ParamRefVectorsFn>(plugify::GetMethodPtr("cross_call_worker.ParamRefVectors"));
		__func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}
	inline int64_t ParamAllPrimitives(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
		using ParamAllPrimitivesFn = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
		static auto __func = reinterpret_cast<ParamAllPrimitivesFn>(plugify::GetMethodPtr("cross_call_worker.ParamAllPrimitives"));
		return __func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	}
}
