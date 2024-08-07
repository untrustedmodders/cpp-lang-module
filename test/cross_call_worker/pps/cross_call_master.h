#pragma once

#include <plugify/cpp_plugin.h>
#include <vector>
#include <string>
#include <cstdint>

// Generated from cross_call_master.pplugin by https://github.com/untrustedmodders/cpp-lang-module/blob/main/generator/generator.py 

namespace cross_call_master {
	inline void ReverseReturn(const std::string& returnString) {
		using ReverseReturnFn = void (*)(const std::string&);
		static ReverseReturnFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ReverseReturn", reinterpret_cast<void**>(&__func));
		__func(returnString);
	}
	inline void NoParamReturnVoidCallback() {
		using NoParamReturnVoidCallbackFn = void (*)();
		static NoParamReturnVoidCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnVoidCallback", reinterpret_cast<void**>(&__func));
		__func();
	}
	inline bool NoParamReturnBoolCallback() {
		using NoParamReturnBoolCallbackFn = bool (*)();
		static NoParamReturnBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnBoolCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char NoParamReturnChar8Callback() {
		using NoParamReturnChar8CallbackFn = char (*)();
		static NoParamReturnChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnChar8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline char16_t NoParamReturnChar16Callback() {
		using NoParamReturnChar16CallbackFn = char16_t (*)();
		static NoParamReturnChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnChar16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int8_t NoParamReturnInt8Callback() {
		using NoParamReturnInt8CallbackFn = int8_t (*)();
		static NoParamReturnInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int16_t NoParamReturnInt16Callback() {
		using NoParamReturnInt16CallbackFn = int16_t (*)();
		static NoParamReturnInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int32_t NoParamReturnInt32Callback() {
		using NoParamReturnInt32CallbackFn = int32_t (*)();
		static NoParamReturnInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline int64_t NoParamReturnInt64Callback() {
		using NoParamReturnInt64CallbackFn = int64_t (*)();
		static NoParamReturnInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint8_t NoParamReturnUInt8Callback() {
		using NoParamReturnUInt8CallbackFn = uint8_t (*)();
		static NoParamReturnUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint16_t NoParamReturnUInt16Callback() {
		using NoParamReturnUInt16CallbackFn = uint16_t (*)();
		static NoParamReturnUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint32_t NoParamReturnUInt32Callback() {
		using NoParamReturnUInt32CallbackFn = uint32_t (*)();
		static NoParamReturnUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline uint64_t NoParamReturnUInt64Callback() {
		using NoParamReturnUInt64CallbackFn = uint64_t (*)();
		static NoParamReturnUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void* NoParamReturnPointerCallback() {
		using NoParamReturnPointerCallbackFn = void* (*)();
		static NoParamReturnPointerCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnPointerCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline float NoParamReturnFloatCallback() {
		using NoParamReturnFloatCallbackFn = float (*)();
		static NoParamReturnFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnFloatCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline double NoParamReturnDoubleCallback() {
		using NoParamReturnDoubleCallbackFn = double (*)();
		static NoParamReturnDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	using NoParamReturnFunctionCallbackFunc = int32_t (*)();
	inline NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
		using NoParamReturnFunctionCallbackFn = NoParamReturnFunctionCallbackFunc (*)();
		static NoParamReturnFunctionCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnFunctionCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::string NoParamReturnStringCallback() {
		using NoParamReturnStringCallbackFn = std::string (*)();
		static NoParamReturnStringCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnStringCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<bool> NoParamReturnArrayBoolCallback() {
		using NoParamReturnArrayBoolCallbackFn = std::vector<bool> (*)();
		static NoParamReturnArrayBoolCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayBoolCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<char> NoParamReturnArrayChar8Callback() {
		using NoParamReturnArrayChar8CallbackFn = std::vector<char> (*)();
		static NoParamReturnArrayChar8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayChar8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<char16_t> NoParamReturnArrayChar16Callback() {
		using NoParamReturnArrayChar16CallbackFn = std::vector<char16_t> (*)();
		static NoParamReturnArrayChar16CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayChar16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int8_t> NoParamReturnArrayInt8Callback() {
		using NoParamReturnArrayInt8CallbackFn = std::vector<int8_t> (*)();
		static NoParamReturnArrayInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int16_t> NoParamReturnArrayInt16Callback() {
		using NoParamReturnArrayInt16CallbackFn = std::vector<int16_t> (*)();
		static NoParamReturnArrayInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int32_t> NoParamReturnArrayInt32Callback() {
		using NoParamReturnArrayInt32CallbackFn = std::vector<int32_t> (*)();
		static NoParamReturnArrayInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<int64_t> NoParamReturnArrayInt64Callback() {
		using NoParamReturnArrayInt64CallbackFn = std::vector<int64_t> (*)();
		static NoParamReturnArrayInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint8_t> NoParamReturnArrayUInt8Callback() {
		using NoParamReturnArrayUInt8CallbackFn = std::vector<uint8_t> (*)();
		static NoParamReturnArrayUInt8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt8Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint16_t> NoParamReturnArrayUInt16Callback() {
		using NoParamReturnArrayUInt16CallbackFn = std::vector<uint16_t> (*)();
		static NoParamReturnArrayUInt16CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt16Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint32_t> NoParamReturnArrayUInt32Callback() {
		using NoParamReturnArrayUInt32CallbackFn = std::vector<uint32_t> (*)();
		static NoParamReturnArrayUInt32CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt32Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<uint64_t> NoParamReturnArrayUInt64Callback() {
		using NoParamReturnArrayUInt64CallbackFn = std::vector<uint64_t> (*)();
		static NoParamReturnArrayUInt64CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayUInt64Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<void*> NoParamReturnArrayPointerCallback() {
		using NoParamReturnArrayPointerCallbackFn = std::vector<void*> (*)();
		static NoParamReturnArrayPointerCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayPointerCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<float> NoParamReturnArrayFloatCallback() {
		using NoParamReturnArrayFloatCallbackFn = std::vector<float> (*)();
		static NoParamReturnArrayFloatCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayFloatCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<double> NoParamReturnArrayDoubleCallback() {
		using NoParamReturnArrayDoubleCallbackFn = std::vector<double> (*)();
		static NoParamReturnArrayDoubleCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayDoubleCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline std::vector<std::string> NoParamReturnArrayStringCallback() {
		using NoParamReturnArrayStringCallbackFn = std::vector<std::string> (*)();
		static NoParamReturnArrayStringCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnArrayStringCallback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Vector2 NoParamReturnVector2Callback() {
		using NoParamReturnVector2CallbackFn = plugify::Vector2 (*)();
		static NoParamReturnVector2CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnVector2Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Vector3 NoParamReturnVector3Callback() {
		using NoParamReturnVector3CallbackFn = plugify::Vector3 (*)();
		static NoParamReturnVector3CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnVector3Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Vector4 NoParamReturnVector4Callback() {
		using NoParamReturnVector4CallbackFn = plugify::Vector4 (*)();
		static NoParamReturnVector4CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnVector4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline plugify::Matrix4x4 NoParamReturnMatrix4x4Callback() {
		using NoParamReturnMatrix4x4CallbackFn = plugify::Matrix4x4 (*)();
		static NoParamReturnMatrix4x4CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.NoParamReturnMatrix4x4Callback", reinterpret_cast<void**>(&__func));
		return __func();
	}
	inline void Param1Callback(int32_t a) {
		using Param1CallbackFn = void (*)(int32_t);
		static Param1CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param1Callback", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void Param2Callback(int32_t a, float b) {
		using Param2CallbackFn = void (*)(int32_t, float);
		static Param2CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param2Callback", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void Param3Callback(int32_t a, float b, double c) {
		using Param3CallbackFn = void (*)(int32_t, float, double);
		static Param3CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param3Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void Param4Callback(int32_t a, float b, double c, const plugify::Vector4& d) {
		using Param4CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&);
		static Param4CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param4Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void Param5Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e) {
		using Param5CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&);
		static Param5CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param5Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void Param6Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f) {
		using Param6CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char);
		static Param6CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param6Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void Param7Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g) {
		using Param7CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&);
		static Param7CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param7Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void Param8Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h) {
		using Param8CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t);
		static Param8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param8Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void Param9Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k) {
		using Param9CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t, int16_t);
		static Param9CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param9Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void Param10Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k, void* l) {
		using Param10CallbackFn = void (*)(int32_t, float, double, const plugify::Vector4&, const std::vector<int64_t>&, char, const std::string&, char16_t, int16_t, void*);
		static Param10CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.Param10Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRef1Callback(int32_t& a) {
		using ParamRef1CallbackFn = void (*)(int32_t&);
		static ParamRef1CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef1Callback", reinterpret_cast<void**>(&__func));
		__func(a);
	}
	inline void ParamRef2Callback(int32_t& a, float& b) {
		using ParamRef2CallbackFn = void (*)(int32_t&, float&);
		static ParamRef2CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef2Callback", reinterpret_cast<void**>(&__func));
		__func(a, b);
	}
	inline void ParamRef3Callback(int32_t& a, float& b, double& c) {
		using ParamRef3CallbackFn = void (*)(int32_t&, float&, double&);
		static ParamRef3CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef3Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c);
	}
	inline void ParamRef4Callback(int32_t& a, float& b, double& c, plugify::Vector4& d) {
		using ParamRef4CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&);
		static ParamRef4CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef4Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d);
	}
	inline void ParamRef5Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e) {
		using ParamRef5CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&);
		static ParamRef5CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef5Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e);
	}
	inline void ParamRef6Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f) {
		using ParamRef6CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&);
		static ParamRef6CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef6Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f);
	}
	inline void ParamRef7Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g) {
		using ParamRef7CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&);
		static ParamRef7CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef7Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g);
	}
	inline void ParamRef8Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h) {
		using ParamRef8CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&);
		static ParamRef8CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef8Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h);
	}
	inline void ParamRef9Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k) {
		using ParamRef9CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&, int16_t&);
		static ParamRef9CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef9Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k);
	}
	inline void ParamRef10Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k, void*& l) {
		using ParamRef10CallbackFn = void (*)(int32_t&, float&, double&, plugify::Vector4&, std::vector<int64_t>&, char&, std::string&, char16_t&, int16_t&, void*&);
		static ParamRef10CallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRef10Callback", reinterpret_cast<void**>(&__func));
		__func(a, b, c, d, e, f, g, h, k, l);
	}
	inline void ParamRefVectorsCallback(std::vector<bool>& p1, std::vector<char>& p2, std::vector<char16_t>& p3, std::vector<int8_t>& p4, std::vector<int16_t>& p5, std::vector<int32_t>& p6, std::vector<int64_t>& p7, std::vector<uint8_t>& p8, std::vector<uint16_t>& p9, std::vector<uint32_t>& p10, std::vector<uint64_t>& p11, std::vector<void*>& p12, std::vector<float>& p13, std::vector<double>& p14, std::vector<std::string>& p15) {
		using ParamRefVectorsCallbackFn = void (*)(std::vector<bool>&, std::vector<char>&, std::vector<char16_t>&, std::vector<int8_t>&, std::vector<int16_t>&, std::vector<int32_t>&, std::vector<int64_t>&, std::vector<uint8_t>&, std::vector<uint16_t>&, std::vector<uint32_t>&, std::vector<uint64_t>&, std::vector<void*>&, std::vector<float>&, std::vector<double>&, std::vector<std::string>&);
		static ParamRefVectorsCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamRefVectorsCallback", reinterpret_cast<void**>(&__func));
		__func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
	}
	inline int64_t ParamAllPrimitivesCallback(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10, uint64_t p11, void* p12, float p13, double p14) {
		using ParamAllPrimitivesCallbackFn = int64_t (*)(bool, char, char16_t, int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t, void*, float, double);
		static ParamAllPrimitivesCallbackFn __func = nullptr;
		if (__func == nullptr) plugify::GetMethodPtr2("cross_call_master.ParamAllPrimitivesCallback", reinterpret_cast<void**>(&__func));
		return __func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
	}
}
