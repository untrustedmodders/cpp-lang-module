#include <pps/cross_call_worker.h>
#include <plugify/cpp_plugin.h>
#include <plugin_export.h>
#include "simple_tests.h"
#include <format>
#include <limits>
#include <cstdint>

#define TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES 0x0001
#define TEST_NO_PARAM_ONLY_RETURN_OBJECTS 0x0002
#define TEST_NO_PARAM_ONLY_RETURN_ARRAYS 0x0004
#define TEST_NO_PARAM_ONLY_RETURN_VECTORS 0x0008
#define TEST_PARAMS_NO_REFS 0x0010
#define TEST_PARAMS_WITH_REFS 0x0020
#define TEST_PARAMS_REF_ARRAYS 0x0040
#define TEST_PARAMS_ALL_PRIMITIVES 0x0080
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES 0x0100
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS 0x0200
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS 0x0400
#define TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS 0x0800
#define TEST_REVERSE_PARAMS_NO_REFS 0x1000
#define TEST_REVERSE_PARAMS_WITH_REFS 0x2000
#define TEST_REVERSE_PARAMS_REF_ARRAYS 0x4000
#define TEST_REVERSE_PARAMS_ALL_PRIMITIVES 0x8000
#define TEST_ALL 0xFFFFFFFF
#ifndef TEST_CASES
#define TEST_CASES TEST_ALL
#endif // !def TEST_CASE

class CrossCallMaster : public plugify::IPluginEntry {
	void OnPluginStart() override {
		NoParamOnlyReturn();
		ParamsNoRefs();
		ParamsWithRefs();
		ParamsRefVectors();
		ParamsAllPrimitives();
		ReverseNoParamOnlyReturn();
		ReverseParamsNoRefs();
		ReverseParamsWithRefs();
		ReverseParamsRefVectors();
		ReverseParamsAllPrimitives();
		_tests.Run();
	}

    void OnPluginEnd() override {
        _tests.Reset();
    };

	void NoParamOnlyReturn() {
#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES
		_tests.Add("NoParamReturnVoid", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::NoParamReturnVoid();
		});
		_tests.Add("NoParamReturnBool", [](SimpleTests::Test& test) {
			auto expected = true;
			auto result = cross_call_worker::NoParamReturnBool();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnChar8", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<char>::max();
			auto result = cross_call_worker::NoParamReturnChar8();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", static_cast<uint8_t>(result), static_cast<uint8_t>(expected)));
			}
		});
		_tests.Add("NoParamReturnChar16", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<char16_t>::max();
			auto result = cross_call_worker::NoParamReturnChar16();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", static_cast<uint16_t>(result), static_cast<uint16_t>(expected)));
			}
		});
		_tests.Add("NoParamReturnInt8", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int8_t>::max();
			auto result = cross_call_worker::NoParamReturnInt8();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnInt16", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int16_t>::max();
			auto result = cross_call_worker::NoParamReturnInt16();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnInt32", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int32_t>::max();
			auto result = cross_call_worker::NoParamReturnInt32();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnInt64", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<int64_t>::max();
			auto result = cross_call_worker::NoParamReturnInt64();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt8", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint8_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt8();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt16", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint16_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt16();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt32", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint32_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt32();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnUInt64", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<uint64_t>::max();
			auto result = cross_call_worker::NoParamReturnUInt64();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnPointer", [](SimpleTests::Test& test) {
			auto expected = reinterpret_cast<void*>(0x1);
			auto result = cross_call_worker::NoParamReturnPointer();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnFloat", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<float>::max();
			auto result = cross_call_worker::NoParamReturnFloat();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
		_tests.Add("NoParamReturnDouble", [](SimpleTests::Test& test) {
			auto expected = std::numeric_limits<double>::max();
			auto result = cross_call_worker::NoParamReturnDouble();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
#endif // TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES

#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_OBJECTS
		_tests.Add("NoParamReturnFunction", [](SimpleTests::Test& test) {
			cross_call_worker::NoParamReturnFunctionFunc expected = nullptr;
			auto result = cross_call_worker::NoParamReturnFunction();
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", reinterpret_cast<void*>(result), reinterpret_cast<void*>(expected)));
			}
		});
		_tests.Add("NoParamReturnString", [](SimpleTests::Test& test) {
			auto expected = "Hello World";
			auto result = cross_call_worker::NoParamReturnString();
			if (result != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", result, expected));
			}
		});
#endif // TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_OBJECTS

#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_ARRAYS
		_tests.Add("NoParamReturnArrayBool", [](SimpleTests::Test& test) {
			auto expected = std::vector<bool>{true, false};
			auto result = cross_call_worker::NoParamReturnArrayBool();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", static_cast<bool>(result[0]));
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", static_cast<bool>(*it));
					}
				}
				std::string expected_formated = std::format("{}", static_cast<bool>(expected[0]));
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", static_cast<bool>(*it));
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayChar8", [](SimpleTests::Test& test) {
			auto expected = std::vector<char>{'a', 'b', 'c', 'd'};
			auto result = cross_call_worker::NoParamReturnArrayChar8();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", static_cast<uint8_t>(result[0]));
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", static_cast<uint8_t>(*it));
					}
				}
				std::string expected_formated = std::format("{}", static_cast<uint8_t>(expected[0]));
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", static_cast<uint8_t>(*it));
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayChar16", [](SimpleTests::Test& test) {
			auto expected = std::vector<char16_t>{u'a', u'b', u'c', u'd'};
			auto result = cross_call_worker::NoParamReturnArrayChar16();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", static_cast<uint16_t>(result[0]));
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", static_cast<uint16_t>(*it));
					}
				}
				std::string expected_formated = std::format("{}", static_cast<uint16_t>(expected[0]));
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", static_cast<uint16_t>(*it));
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayInt8", [](SimpleTests::Test& test) {
			auto expected = std::vector<int8_t>{-3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt8();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayInt16", [](SimpleTests::Test& test) {
			auto expected = std::vector<int16_t>{-4, -3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt16();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayInt32", [](SimpleTests::Test& test) {
			auto expected = std::vector<int32_t>{-5, -4, -3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt32();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayInt64", [](SimpleTests::Test& test) {
			auto expected = std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1};
			auto result = cross_call_worker::NoParamReturnArrayInt64();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayUInt8", [](SimpleTests::Test& test) {
			auto expected = std::vector<uint8_t>{0, 1, 2, 3, 4, 5, 6, 7, 8};
			auto result = cross_call_worker::NoParamReturnArrayUInt8();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayUInt16", [](SimpleTests::Test& test) {
			auto expected = std::vector<uint16_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			auto result = cross_call_worker::NoParamReturnArrayUInt16();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayUInt32", [](SimpleTests::Test& test) {
			auto expected = std::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			auto result = cross_call_worker::NoParamReturnArrayUInt32();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayUInt64", [](SimpleTests::Test& test) {
			auto expected = std::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
			auto result = cross_call_worker::NoParamReturnArrayUInt64();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayPointer", [](SimpleTests::Test& test) {
			auto expected = std::vector<void*>{reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2), reinterpret_cast<void*>(3)};
			auto result = cross_call_worker::NoParamReturnArrayPointer();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayFloat", [](SimpleTests::Test& test) {
			auto expected = std::vector<float>{-12.34f, 0.0f, 12.34f};
			auto result = cross_call_worker::NoParamReturnArrayFloat();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayDouble", [](SimpleTests::Test& test) {
			auto expected = std::vector<double>{-12.345, 0.0, 12.345};
			auto result = cross_call_worker::NoParamReturnArrayDouble();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
		_tests.Add("NoParamReturnArrayString", [](SimpleTests::Test& test) {
			auto expected = std::vector<std::string>{"1st string", "2nd string", "3rd element string (Should be big enough to avoid small string optimization)"};
			auto result = cross_call_worker::NoParamReturnArrayString();
			if (result != expected) {
				std::string result_formated;
				if (!result.empty()) {
					result_formated = std::format("{}", result[0]);
					for (auto it = std::next(result.begin()); it != result.end(); ++it) {
						std::format_to(std::back_inserter(result_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", expected[0]);
				for (auto it = std::next(expected.begin()); it != expected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong return {{{}}}, expected {{{}}}", result_formated, expected_formated));
			}
		});
#endif// TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_ARRAYS

#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_VECTORS
		_tests.Add("NoParamReturnVector2", [](SimpleTests::Test& test) {
			auto expected = plugify::Vector2(1, 2);
			auto result = cross_call_worker::NoParamReturnVector2();
			if (result != expected) {
				test.Fail(std::format("Wrong return {{{}, {}}}, expected {{{}, {}}}", result.x, result.y, expected.x, expected.y));
			}
		});
		_tests.Add("NoParamReturnVector3", [](SimpleTests::Test& test) {
			auto expected = plugify::Vector3(1, 2, 3);
			auto result = cross_call_worker::NoParamReturnVector3();
			if (result != expected) {
				test.Fail(std::format("Wrong return {{{}, {}, {}}}, expected {{{}, {}, {}}}", result.x, result.y, result.z, expected.x, expected.y, expected.z));
			}
		});
		_tests.Add("NoParamReturnVector4", [](SimpleTests::Test& test) {
			auto expected = plugify::Vector4(1, 2, 3, 4);
			auto result = cross_call_worker::NoParamReturnVector4();
			if (result != expected) {
				test.Fail(std::format("Wrong return {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}", result.x, result.y, result.z, result.w,
					expected.x, expected.y, expected.z, expected.w));
			}
		});
		_tests.Add("NoParamReturnMatrix4x4", [](SimpleTests::Test& test) {
			auto expected = plugify::Matrix4x4({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
			auto result = cross_call_worker::NoParamReturnMatrix4x4();
			if (result != expected) {
				test.Fail(std::format("Wrong return {{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}, "
					"expected {{{{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}, {{{}, {}, {}, {}}}}}",
					result.m[0][0], result.m[0][1], result.m[0][2], result.m[0][3],
					result.m[1][0], result.m[1][1], result.m[1][2], result.m[1][3],
					result.m[2][0], result.m[2][1], result.m[2][2], result.m[2][3],
					result.m[3][0], result.m[3][1], result.m[3][2], result.m[3][3],
					expected.m[0][0], expected.m[0][1], expected.m[0][2], expected.m[0][3],
					expected.m[1][0], expected.m[1][1], expected.m[1][2], expected.m[1][3], 
					expected.m[2][0], expected.m[2][1], expected.m[2][2], expected.m[2][3], 
					expected.m[3][0], expected.m[3][1], expected.m[3][2], expected.m[3][3]));
			}
		});
#endif// TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_VECTORS
	}

	void ParamsNoRefs() {
#if TEST_CASES & TEST_PARAMS_NO_REFS
		constexpr const int32_t intValue = 42;
		constexpr float floatValue = 3.14f;
		constexpr const double doubleValue = 6.28;
		constexpr const char charValue = 'A';
		constexpr const char16_t char16Value = 'B';
		constexpr const int16_t shortValue = 10;
		constexpr void* const ptrValue = nullptr;
		
		_tests.Add("Param1", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::Param1(intValue);
		});

		_tests.Add("Param2", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::Param2(intValue, floatValue);
		});

		_tests.Add("Param3", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::Param3(intValue, floatValue, doubleValue);
		});

		_tests.Add("Param4", [](SimpleTests::Test& /*test*/) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			cross_call_worker::Param4(intValue, floatValue, doubleValue, vector4Value);
		});

		_tests.Add("Param5", [](SimpleTests::Test& /*test*/) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			cross_call_worker::Param5(intValue, floatValue, doubleValue, vector4Value, longListValue);
		});

		_tests.Add("Param6", [](SimpleTests::Test& /*test*/) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			cross_call_worker::Param6(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue);
		});

		_tests.Add("Param7", [](SimpleTests::Test& /*test*/) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			const std::string stringValue = "Hello";
			cross_call_worker::Param7(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue);
		});

		_tests.Add("Param9", [](SimpleTests::Test& /*test*/) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			const std::string stringValue = "Hello";
			cross_call_worker::Param9(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue);
		});

		_tests.Add("Param10", [](SimpleTests::Test& /*test*/) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			const std::string stringValue = "Hello";
			cross_call_worker::Param10(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue, ptrValue);
		});
#endif // TEST_CASES & TEST_PARAMS_NO_REFS
	}

	void ParamsWithRefs() {
#if TEST_CASES & TEST_PARAMS_WITH_REFS
		_tests.Add("ParamRef1", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{42};
			int32_t intValue{};
			cross_call_worker::ParamRef1(intValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
		});
		_tests.Add("ParamRef2", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{10};
			const auto floatExpected = 3.14f;
			int32_t intValue{};
			float floatValue{};
			cross_call_worker::ParamRef2(intValue, floatValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
		});
		_tests.Add("ParamRef3", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{-20};
			const auto floatExpected = 2.718f;
			const auto doubleExpected = 3.14159;
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			cross_call_worker::ParamRef3(intValue, floatValue, doubleValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
		});
		_tests.Add("ParamRef4", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{100};
			const auto floatExpected = -5.55f;
			const auto doubleExpected = 1.618;
			const auto vector4Expected = plugify::Vector4(1.0f, 2.0f, 3.0f, 4.0f);
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			cross_call_worker::ParamRef4(intValue, floatValue, doubleValue, vector4Value);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
		});
		_tests.Add("ParamRef5", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{500};
			const auto floatExpected = -10.5f;
			const auto doubleExpected = 2.71828;
			const auto vector4Expected = plugify::Vector4(-1.0f, -2.0f, -3.0f, -4.0f);
			const auto longListExpected = std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			std::vector<int64_t> longListValue{};
			cross_call_worker::ParamRef5(intValue, floatValue, doubleValue, vector4Value, longListValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
			if (longListValue != longListExpected) {
				std::string modified_formated;
				if (!longListValue.empty()) {
					modified_formated = std::format("{}", longListValue[0]);
					for (auto it = std::next(longListValue.begin()); it != longListValue.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longListExpected[0]);
				for (auto it = std::next(longListExpected.begin()); it != longListExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longListValue param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
		});
		_tests.Add("ParamRef6", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{750};
			const auto floatExpected = 20.0f;
			const auto doubleExpected = 1.23456;
			const auto vector4Expected = plugify::Vector4(10.0f, 20.0f, 30.0f, 40.0f);
			const auto longListExpected = std::vector<int64_t>{-6, -5, -4};
			const auto charExpected = 'Z';
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			std::vector<int64_t> longListValue{};
			char charValue{};
			cross_call_worker::ParamRef6(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
			if (longListValue != longListExpected) {
				std::string modified_formated;
				if (!longListValue.empty()) {
					modified_formated = std::format("{}", longListValue[0]);
					for (auto it = std::next(longListValue.begin()); it != longListValue.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longListExpected[0]);
				for (auto it = std::next(longListExpected.begin()); it != longListExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longListValue param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
		});
		_tests.Add("ParamRef7", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{-1000};
			const auto floatExpected = 3.0f;
			const auto doubleExpected = -1;
			const auto vector4Expected = plugify::Vector4(100.0f, 200.0f, 300.0f, 400.0f);
			const auto longListExpected = std::vector<int64_t>{-6, -5, -4, -3};
			const auto charExpected = 'Y';
			const auto stringExpected = std::string{"Hello, World!"};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			std::vector<int64_t> longListValue{};
			char charValue{};
			std::string stringValue{};
			cross_call_worker::ParamRef7(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
			if (longListValue != longListExpected) {
				std::string modified_formated;
				if (!longListValue.empty()) {
					modified_formated = std::format("{}", longListValue[0]);
					for (auto it = std::next(longListValue.begin()); it != longListValue.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longListExpected[0]);
				for (auto it = std::next(longListExpected.begin()); it != longListExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longListValue param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
		});
		_tests.Add("ParamRef8", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{999};
			const auto floatExpected = -7.5f;
			const auto doubleExpected = 0.123456;
			const auto vector4Expected = plugify::Vector4(-100.0f, -200.0f, -300.0f, -400.0f);
			const auto longListExpected = std::vector<int64_t>{-6, -5, -4, -3, -2, -1};
			const auto charExpected = 'X';
			const auto stringExpected = std::string{"Goodbye, World!"};
			const auto char16Expected = 'A';
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			std::vector<int64_t> longListValue{};
			char charValue{};
			std::string stringValue{};
			char16_t char16Value{};
			cross_call_worker::ParamRef8(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
			if (longListValue != longListExpected) {
				std::string modified_formated;
				if (!longListValue.empty()) {
					modified_formated = std::format("{}", longListValue[0]);
					for (auto it = std::next(longListValue.begin()); it != longListValue.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longListExpected[0]);
				for (auto it = std::next(longListExpected.begin()); it != longListExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longListValue param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
			if (char16Value != char16Expected) {
				test.Fail(std::format("Wrong char16Value param {}, expected {}", static_cast<uint16_t>(char16Value), static_cast<uint16_t>(char16Expected)));
			}
		});
		_tests.Add("ParamRef9", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{-1234};
			const auto floatExpected = 123.45f;
			const auto doubleExpected = -678.9;
			const auto vector4Expected = plugify::Vector4(987.65f, 432.1f, 123.456f, 789.123f);
			const auto longListExpected = std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1, 5, 9};
			const auto charExpected = 'W';
			const auto stringExpected = std::string{"Testing, 1 2 3"};
			const auto char16Expected = 'B';
			const auto shortExpected = int16_t{42};
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			std::vector<int64_t> longListValue{};
			char charValue{};
			std::string stringValue{};
			char16_t char16Value{};
			int16_t shortValue{};
			cross_call_worker::ParamRef9(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
			if (longListValue != longListExpected) {
				std::string modified_formated;
				if (!longListValue.empty()) {
					modified_formated = std::format("{}", longListValue[0]);
					for (auto it = std::next(longListValue.begin()); it != longListValue.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longListExpected[0]);
				for (auto it = std::next(longListExpected.begin()); it != longListExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longListValue param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
			if (char16Value != char16Expected) {
				test.Fail(std::format("Wrong char16Value param {}, expected {}", static_cast<uint16_t>(char16Value), static_cast<uint16_t>(char16Expected)));
			}
			if (shortValue != shortExpected) {
				test.Fail(std::format("Wrong shortValue param {}, expected {}", shortValue, shortExpected));
			}
		});
		_tests.Add("ParamRef10", [](SimpleTests::Test& test) {
			const auto intExpected = int32_t{987};
			const auto floatExpected = -0.123f;
			const auto doubleExpected = 456.789;
			const auto vector4Expected = plugify::Vector4(-123.456f, 0.987f, 654.321f, -789.123f);
			const auto longListExpected = std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1, 5, 9, 4, -7};
			const auto charExpected = 'V';
			const auto stringExpected = std::string{"Another string"};
			const auto char16Expected = 'C';
			const auto shortExpected = int16_t{-444};
			const auto ptrExpected = reinterpret_cast<void*>(0x12345678);
			int32_t intValue{};
			float floatValue{};
			double doubleValue{};
			plugify::Vector4 vector4Value{};
			std::vector<int64_t> longListValue{};
			char charValue{};
			std::string stringValue{};
			char16_t char16Value{};
			int16_t shortValue{};
			void* ptrValue{};
			cross_call_worker::ParamRef10(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue, ptrValue);
			if (intValue != intExpected) {
				test.Fail(std::format("Wrong intValue param {}, expected {}", intValue, intExpected));
			}
			if (floatValue != floatExpected) {
				test.Fail(std::format("Wrong floatValue param {}, expected {}", floatValue, floatExpected));
			}
			if (doubleValue != doubleExpected) {
				test.Fail(std::format("Wrong doubleValue param {}, expected {}", doubleValue, doubleExpected));
			}
			if (vector4Value != vector4Expected) {
				test.Fail(std::format("Wrong vector4Value param {{{}, {}, {}, {}}}, expected {{{}, {}, {}, {}}}",
									  vector4Value.x, vector4Value.y, vector4Value.z, vector4Value.w,
									  vector4Expected.x, vector4Expected.y, vector4Expected.z, vector4Expected.w));
			}
			if (longListValue != longListExpected) {
				std::string modified_formated;
				if (!longListValue.empty()) {
					modified_formated = std::format("{}", longListValue[0]);
					for (auto it = std::next(longListValue.begin()); it != longListValue.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longListExpected[0]);
				for (auto it = std::next(longListExpected.begin()); it != longListExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longListValue param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (charValue != charExpected) {
				test.Fail(std::format("Wrong charValue param {}, expected {}", static_cast<uint8_t>(charValue), static_cast<uint8_t>(charExpected)));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param '{}', expected '{}'", stringValue, stringExpected));
			}
			if (char16Value != char16Expected) {
				test.Fail(std::format("Wrong char16Value param {}, expected {}", static_cast<uint16_t>(char16Value), static_cast<uint16_t>(char16Expected)));
			}
			if (shortValue != shortExpected) {
				test.Fail(std::format("Wrong shortValue param {}, expected {}", shortValue, shortExpected));
			}
			if (ptrValue != ptrExpected) {
				test.Fail(std::format("Wrong ptrValue param {}, expected {}", ptrValue, ptrExpected));
			}
		});
#endif// TEST_CASES & TEST_PARAMS_WITH_REFS
	}

	void ParamsRefVectors() {
#if TEST_CASES & TEST_PARAMS_REF_ARRAYS
		_tests.Add("ParamRefArrays", [](SimpleTests::Test& test) {
			const auto boolArrayExpected = std::vector<bool>{true};
			const auto char8ArrayExpected = std::vector<char>{'a', 'b', 'c'};
			const auto char16ArrayExpected = std::vector<char16_t>{'d', 'e', 'f'};
			const auto sbyteArrayExpected = std::vector<int8_t>{-3, -2, -1, 0, 1, 2, 3};
			const auto shortArrayExpected = std::vector<int16_t>{-4, -3, -2, -1, 0, 1, 2, 3, 4};
			const auto intArrayExpected = std::vector<int32_t>{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
			const auto longArrayExpected = std::vector<int64_t>{-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
			const auto byteArrayExpected = std::vector<uint8_t>{0, 1, 2, 3, 4, 5, 6, 7};
			const auto ushortArrayExpected = std::vector<uint16_t>{0, 1, 2, 3, 4, 5, 6, 7, 8};
			const auto uintArrayExpected = std::vector<uint32_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			const auto ulongArrayExpected = std::vector<uint64_t>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			const auto intPtrArrayExpected = std::vector<void*>{reinterpret_cast<void*>(0), reinterpret_cast<void*>(1), reinterpret_cast<void*>(2)};
			const auto floatArrayExpected = std::vector<float>{-12.34f, 0.0f, 12.34f};
			const auto doubleArrayExpected = std::vector<double>{-12.345, 0.0, 12.345};
			const auto stringArrayExpected = std::vector<std::string>{"1", "12", "123", "1234", "12345", "123456"};
			std::vector<bool> boolArray{true, false, true};
			std::vector<char> char8Array{'A', 'B', 'C'};
			std::vector<char16_t> char16Array{'D', 'E', 'F'};
			std::vector<int8_t> sbyteArray{-1, -2, -3};
			std::vector<int16_t> shortArray{10, 20, 30};
			std::vector<int32_t> intArray{100, 200, 300};
			std::vector<int64_t> longArray{1000, 2000, 3000};
			std::vector<uint8_t> byteArray{1, 2, 3};
			std::vector<uint16_t> ushortArray{1000, 2000, 3000};
			std::vector<uint32_t> uintArray{10000, 20000, 30000};
			std::vector<uint64_t> ulongArray{100000, 200000, 300000};
			std::vector<void*> intPtrArray{nullptr, nullptr, nullptr};
			std::vector<float> floatArray{1.1f, 2.2f, 3.3f};
			std::vector<double> doubleArray{1.1, 2.2, 3.3};
			std::vector<std::string> stringArray{"Hello", "World", "!"};
			cross_call_worker::ParamRefVectors(boolArray, char8Array, char16Array, sbyteArray, shortArray, intArray, longArray,
				byteArray, ushortArray, uintArray, ulongArray, intPtrArray, floatArray, doubleArray, stringArray);
			if (boolArray != boolArrayExpected) {
				std::string modified_formated;
				if (!boolArray.empty()) {
					modified_formated = std::format("{}", static_cast<bool>(boolArray[0]));
					for (auto it = std::next(boolArray.begin()); it != boolArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", static_cast<bool>(*it));
					}
				}
				std::string expected_formated = std::format("{}", static_cast<bool>(boolArrayExpected[0]));
				for (auto it = std::next(boolArrayExpected.begin()); it != boolArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", static_cast<bool>(*it));
				}
				test.Fail(std::format("Wrong boolArray param {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (char8Array != char8ArrayExpected) {
				std::string modified_formated;
				if (!char8Array.empty()) {
					modified_formated = std::format("{}", static_cast<uint8_t>(char8Array[0]));
					for (auto it = std::next(char8Array.begin()); it != char8Array.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", static_cast<uint8_t>(*it));
					}
				}
				std::string expected_formated = std::format("{}", static_cast<uint8_t>(char8ArrayExpected[0]));
				for (auto it = std::next(char8ArrayExpected.begin()); it != char8ArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", static_cast<uint8_t>(*it));
				}
				test.Fail(std::format("Wrong char8Array array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (char16Array != char16ArrayExpected) {
				std::string modified_formated;
				if (!char16Array.empty()) {
					modified_formated = std::format("{}", static_cast<uint16_t>(char16Array[0]));
					for (auto it = std::next(char16Array.begin()); it != char16Array.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", static_cast<uint16_t>(*it));
					}
				}
				std::string expected_formated = std::format("{}", static_cast<uint16_t>(char16ArrayExpected[0]));
				for (auto it = std::next(char16ArrayExpected.begin()); it != char16ArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", static_cast<uint16_t>(*it));
				}
				test.Fail(std::format("Wrong char16Array array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (sbyteArray != sbyteArrayExpected) {
				std::string modified_formated;
				if (!sbyteArray.empty()) {
					modified_formated = std::format("{}", sbyteArray[0]);
					for (auto it = std::next(sbyteArray.begin()); it != sbyteArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", sbyteArrayExpected[0]);
				for (auto it = std::next(sbyteArrayExpected.begin()); it != sbyteArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong sbyteArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (shortArray != shortArrayExpected) {
				std::string modified_formated;
				if (!shortArray.empty()) {
					modified_formated = std::format("{}", shortArray[0]);
					for (auto it = std::next(shortArray.begin()); it != shortArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", shortArrayExpected[0]);
				for (auto it = std::next(shortArrayExpected.begin()); it != shortArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong shortArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (intArray != intArrayExpected) {
				std::string modified_formated;
				if (!intArray.empty()) {
					modified_formated = std::format("{}", intArray[0]);
					for (auto it = std::next(intArray.begin()); it != intArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", intArrayExpected[0]);
				for (auto it = std::next(intArrayExpected.begin()); it != intArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong intArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (longArray != longArrayExpected) {
				std::string modified_formated;
				if (!longArray.empty()) {
					modified_formated = std::format("{}", longArray[0]);
					for (auto it = std::next(longArray.begin()); it != longArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", longArrayExpected[0]);
				for (auto it = std::next(longArrayExpected.begin()); it != longArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong longArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (byteArray != byteArrayExpected) {
				std::string modified_formated;
				if (!byteArray.empty()) {
					modified_formated = std::format("{}", byteArray[0]);
					for (auto it = std::next(byteArray.begin()); it != byteArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", byteArrayExpected[0]);
				for (auto it = std::next(byteArrayExpected.begin()); it != byteArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong byteArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (ushortArray != ushortArrayExpected) {
				std::string modified_formated;
				if (!ushortArray.empty()) {
					modified_formated = std::format("{}", ushortArray[0]);
					for (auto it = std::next(ushortArray.begin()); it != ushortArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", ushortArrayExpected[0]);
				for (auto it = std::next(ushortArrayExpected.begin()); it != ushortArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong ushortArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (uintArray != uintArrayExpected) {
				std::string modified_formated;
				if (!uintArray.empty()) {
					modified_formated = std::format("{}", uintArray[0]);
					for (auto it = std::next(uintArray.begin()); it != uintArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", uintArrayExpected[0]);
				for (auto it = std::next(uintArrayExpected.begin()); it != uintArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong uintArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (ulongArray != ulongArrayExpected) {
				std::string modified_formated;
				if (!ulongArray.empty()) {
					modified_formated = std::format("{}", ulongArray[0]);
					for (auto it = std::next(ulongArray.begin()); it != ulongArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", ulongArrayExpected[0]);
				for (auto it = std::next(ulongArrayExpected.begin()); it != ulongArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong ulongArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (intPtrArray != intPtrArrayExpected) {
				std::string modified_formated;
				if (!intPtrArray.empty()) {
					modified_formated = std::format("{}", intPtrArray[0]);
					for (auto it = std::next(intPtrArray.begin()); it != intPtrArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", intPtrArrayExpected[0]);
				for (auto it = std::next(intPtrArrayExpected.begin()); it != intPtrArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong intPtrArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (floatArray != floatArrayExpected) {
				std::string modified_formated;
				if (!floatArray.empty()) {
					modified_formated = std::format("{}", floatArray[0]);
					for (auto it = std::next(floatArray.begin()); it != floatArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", floatArrayExpected[0]);
				for (auto it = std::next(floatArrayExpected.begin()); it != floatArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong floatArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (doubleArray != doubleArrayExpected) {
				std::string modified_formated;
				if (!doubleArray.empty()) {
					modified_formated = std::format("{}", doubleArray[0]);
					for (auto it = std::next(doubleArray.begin()); it != doubleArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", doubleArrayExpected[0]);
				for (auto it = std::next(doubleArrayExpected.begin()); it != doubleArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
				}
				test.Fail(std::format("Wrong doubleArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
			if (stringArray != stringArrayExpected) {
				std::string modified_formated;
				if (!stringArray.empty()) {
					modified_formated = std::format("'{}'", stringArray[0]);
					for (auto it = std::next(stringArray.begin()); it != stringArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", '{}'", *it);
					}
				}
				std::string expected_formated = std::format("'{}'", stringArrayExpected[0]);
				for (auto it = std::next(stringArrayExpected.begin()); it != stringArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", '{}'", *it);
				}
				test.Fail(std::format("Wrong stringArray array {{{}}}, expected {{{}}}", modified_formated, expected_formated));
			}
		});
#endif// TEST_CASES & TEST_PARAMS_REF_ARRAYS
	}

	void ParamsAllPrimitives() {
#if TEST_CASES & TEST_PARAMS_ALL_PRIMITIVES
		_tests.Add("ParamAllPrimitives", [](SimpleTests::Test& test) {
			const auto expected = int64_t{56};
			const auto boolValue = true;
			const auto charValue = 'a';
			const auto char16Value = char16_t{'d'};
			const auto sbyteValue = int8_t{-3};
			const auto shortValue = int16_t{-4};
			const auto intValue = int32_t{-5};
			const auto longValue = int64_t{-6};
			const auto byteValue = uint8_t{7};
			const auto ushortValue = uint16_t{8};
			const auto uintValue = uint32_t{9};
			const auto ulongValue = uint64_t{10};
			const auto intPtrValue = reinterpret_cast<void*>(0);
			const auto floatValue = 1.1f;
			const auto doubleValue = 1.1;
			const auto result = cross_call_worker::ParamAllPrimitives(boolValue, charValue, char16Value, sbyteValue, shortValue, intValue, longValue,
																	  byteValue, ushortValue, uintValue, ulongValue, intPtrValue, floatValue, doubleValue);
			if (result != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
			}
		});
#endif// TEST_CASES & TEST_PARAMS_ALL_PRIMITIVES
	}

	void ReverseNoParamOnlyReturn() {
#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES
		_tests.Add("ReverseNoParamReturnVoid", [](SimpleTests::Test& /*test*/) {
			cross_call_worker::ReverseCall("NoParamReturnVoid");
		});
		_tests.Add("ReverseNoParamReturnBool", [this](SimpleTests::Test& test) {
			const std::string expected = "true";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnBool");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnChar8", [this](SimpleTests::Test& test) {
			const std::string expected = "80"; // P
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnChar8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnChar16", [this](SimpleTests::Test& test) {
			const std::string expected = "1060"; // Ф
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnChar16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt8", [this](SimpleTests::Test& test) {
			const std::string expected = "123";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt16", [this](SimpleTests::Test& test) {
			const std::string expected = "32765";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt32", [this](SimpleTests::Test& test) {
			const std::string expected = "2112211221";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnInt64", [this](SimpleTests::Test& test) {
			const std::string expected = "8526495038839145831";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt8", [this](SimpleTests::Test& test) {
			const std::string expected = "205";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt16", [this](SimpleTests::Test& test) {
			const std::string expected = "52685";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt32", [this](SimpleTests::Test& test) {
			const std::string expected = "3452816845";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnUInt64", [this](SimpleTests::Test& test) {
			const std::string expected = "14829735431805717965";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnUInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnPointer", [this](SimpleTests::Test& test) {
			const std::string expected = "0xaabbccdd87655678";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnPointer");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnFloat", [this](SimpleTests::Test& test) {
			const std::string expected = "0.123";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnFloat");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnDouble", [this](SimpleTests::Test& test) {
			const std::string expected = "987.321";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnDouble");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS
		_tests.Add("ReverseNoParamReturnFunction", [this](SimpleTests::Test& test) {
			const std::string expected = "365";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnFunction");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnString", [this](SimpleTests::Test& test) {
			const std::string expected = "Convertiplane";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnString");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return '{}', expected '{}'", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS
		_tests.Add("ReverseNoParamReturnArrayBool", [this](SimpleTests::Test& test) {
			const std::string expected = "{false, true, true}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayBool");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayChar8", [this](SimpleTests::Test& test) {
			const std::string expected = "{112, 108, 117, 103}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayChar8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}

		});
		_tests.Add("ReverseNoParamReturnArrayChar16", [this](SimpleTests::Test& test) {
			const std::string expected = "{1095, 1072, 1088, 33}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayChar16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt8", [this](SimpleTests::Test& test) {
			const std::string expected = "{10, -15, 20}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt16", [this](SimpleTests::Test& test) {
			const std::string expected = "{10, -15, 20, -25}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt32", [this](SimpleTests::Test& test) {
			const std::string expected = "{10, -15, 20, -25, 30}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayInt64", [this](SimpleTests::Test& test) {
			const std::string expected = "{10, -15, 20, -25, 30, -35}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt8", [this](SimpleTests::Test& test) {
			const std::string expected = "{1, 2, 3, 200}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt8");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt16", [this](SimpleTests::Test& test) {
			const std::string expected = "{1, 2, 3, 200, 60000}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt16");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt32", [this](SimpleTests::Test& test) {
			const std::string expected = "{1, 2, 3, 200, 60000, 4000000000}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt32");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayUInt64", [this](SimpleTests::Test& test) {
			const std::string expected = "{1, 2, 3, 200, 60000, 4000000000, 12223334445556667778}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayUInt64");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayPointer", [this](SimpleTests::Test& test) {
			const std::string expected = "{0x0, 0xdeadbeaf, 0xcdccddcccdddcccc}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayPointer");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayFloat", [this](SimpleTests::Test& test) {
			const std::string expected = "{1.1, -10.82, 555.555}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayFloat");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayDouble", [this](SimpleTests::Test& test) {
			const std::string expected = "{1.1, -10.82, 555.555, 55555.55555, 123456789.98765}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayDouble");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnArrayString", [this](SimpleTests::Test& test) {
			const std::string expected = "{'5', 'true', '0.0', 'Hello', 'And Goodbay', 'Another long string to test. Pi equal 3,1415926535 8979323846 2643383279 5028841971 6939937510'}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnArrayString");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS
		_tests.Add("ReverseNoParamReturnVector2", [this](SimpleTests::Test& test) {
			const std::string expected = "{100.9, 200.8}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnVector2");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnVector3", [this](SimpleTests::Test& test) {
			const std::string expected = "{100.9, 200.8, 300.7}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnVector3");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnVector4", [this](SimpleTests::Test& test) {
			const std::string expected = "{100.9, 200.8, 300.7, 400.6}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnVector4");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseNoParamReturnMatrix4x4", [this](SimpleTests::Test& test) {
			const std::string expected = "{{1.1, 2.2, 3.3, 4.4}, {9.9, 1.1, 2.2, 3.3}, {8.8, 9.9, 1.1, 2.2}, {7.7, 8.8, 9.9, 1.1}}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("NoParamReturnMatrix4x4");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS
	}

	void ReverseParamsNoRefs() {
#if TEST_CASES & TEST_REVERSE_PARAMS_NO_REFS
		_tests.Add("ReverseParam1", [this](SimpleTests::Test& test) {
			const std::string expected = "999";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param1");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam2", [this](SimpleTests::Test& test) {
			const std::string expected = "888|9.9";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param2");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam3", [this](SimpleTests::Test& test) {
			const std::string expected = "777|8.8|9.8765";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param3");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam4", [this](SimpleTests::Test& test) {
			const std::string expected = "666|7.7|8.7659|{100.1, 200.2, 300.3, 400.4}";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param4");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam5", [this](SimpleTests::Test& test) {
			const std::string expected = "555|6.6|7.6598|{-105.1, -205.2, -305.3, -405.4}|{}";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param5");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam6", [this](SimpleTests::Test& test) {
			const std::string expected = "444|5.5|6.5987|{110.1, 210.2, 310.3, 410.4}|{90000, -100, 20000}|65";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param6");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam7", [this](SimpleTests::Test& test) {
			const std::string expected = "333|4.4|5.9876|{-115.1, -215.2, -315.3, -415.4}|{800000, 30000, -4000000}|66|red gold";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param7");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam8", [this](SimpleTests::Test& test) {
			const std::string expected = "222|3.3|1.2345|{120.1, 220.2, 320.3, 420.4}|{7000000, 5000000, -600000000}|67|blue ice|90";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param8");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam9", [this](SimpleTests::Test& test) {
			const std::string expected = "111|2.2|5.1234|{-125.1, -225.2, -325.3, -425.4}|{60000000, -700000000, 80000000000}|68|pink metal|89|-100";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param9");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
		_tests.Add("ReverseParam10", [this](SimpleTests::Test& test) {
			const std::string expected = "1234|1.1|4.5123|{130.1, 230.2, 330.3, 430.4}|{500000000, 90000000000, 1000000000000}|69|green wood|88|-200|0xabeba";
			_reverseParams.reset();
			cross_call_worker::ReverseCall("Param10");
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != expected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_NO_REFS
	}

	void ReverseParamsWithRefs() {
#if TEST_CASES & TEST_REVERSE_PARAMS_WITH_REFS
		_tests.Add("ReverseParamRef1", [this](SimpleTests::Test& test) {
			const std::string expected = "147";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef1");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef2", [this](SimpleTests::Test& test) {
			const std::string expected = "852|0.1";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef2");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef3", [this](SimpleTests::Test& test) {
			const std::string expected = "369|0.2|11111.11111";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef3");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef4", [this](SimpleTests::Test& test) {
			const std::string expected = "987|0.3|22222.22222|{4.4, 3.3, 2.2, 1.1}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef4");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef5", [this](SimpleTests::Test& test) {
			const std::string expected = "456|0.4|33333.33333|{1.4, 4.3, 3.2, 2.1}|{}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef5");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef6", [this](SimpleTests::Test& test) {
			const std::string expected = "321|0.5|44444.44444|{1.1, 4.4, 3.3, 2.2}|{99}|122";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef6");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef7", [this](SimpleTests::Test& test) {
			const std::string expected = "157|0.6|55555.55555|{2.1, 1.4, 4.3, 3.2}|{99, 8888}|121|my string";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef7");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef8", [this](SimpleTests::Test& test) {
			const std::string expected = "759|0.7|66666.66666|{2.2, 1.1, 4.4, 3.3}|{99, 8888, 777777}|120|his string|1098";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef8");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef9", [this](SimpleTests::Test& test) {
			const std::string expected = "953|0.8|77777.77777|{3.2, 2.1, 1.4, 4.3}|{99, 8888, 777777, 66666666}|119|her string|1099|-30003";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef9");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
		_tests.Add("ReverseParamRef10", [this](SimpleTests::Test& test) {
			const std::string expected = "351|0.9|88888.88888|{3.3, 2.2, 1.1, 4.4}|{99, 8888, 777777, 66666666, 5555555555}|118|they string|1100|30003|0xabcdef";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRef10");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_WITH_REFS
	}

	void ReverseParamsRefVectors() {
#if TEST_CASES & TEST_REVERSE_PARAMS_REF_ARRAYS
		_tests.Add("ReverseParamRefArrays", [this](SimpleTests::Test& test) {
			const std::string expected = "{true, false}|{94}|{1103, 1094}|{-4, -3, -2, -1}|{-555, -444, -333}|{-66666, -77777}|{-7666555444}|"
				"{0, 1, 1, 2, 3, 5}|{32999}|{3000000000, 1}|{1, 22, 333, 4444, 55555, 999999999999}|{0xd, 0x9, 0x5, 0x1}|"
				"{91.23, 12.34, 23.45, 8.08}|{777.777777}|{'one', '1 two', '1 2 three'}";
			_reverseReturn.reset();
			cross_call_worker::ReverseCall("ParamRefArrays");
			if (!_reverseReturn) {
				test.Fail("Params return not set");
			} else if (*_reverseReturn != expected) {
				test.Fail(std::format("Wrong ref params return {}, expected {}", *_reverseReturn, expected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_REF_ARRAYS
	}

	void ReverseParamsAllPrimitives() {
#if TEST_CASES & TEST_REVERSE_PARAMS_ALL_PRIMITIVES
		_tests.Add("ReverseParamAllPrimitives", [this](SimpleTests::Test& test) {
			const std::string returnExpected = "65";
			const std::string paramsExpected = "true|37|9762|-1|-1000|-1000000|-1000000000000|200|50000|3000000000|9999999999|0xfedcbaabcdef|0.001|987654.456789";
			_reverseReturn.reset();
			_reverseParams.reset();
			cross_call_worker::ReverseCall("ParamAllPrimitives");
			if (!_reverseReturn) {
				test.Fail("Return not set");
			} else if (*_reverseReturn != returnExpected) {
				test.Fail(std::format("Wrong return {}, expected {}", *_reverseReturn, returnExpected));
			}
			if (!_reverseParams) {
				test.Fail("Params not set");
			} else if (*_reverseParams != paramsExpected) {
				test.Fail(std::format("Wrong param values {}, expected {}", *_reverseParams, paramsExpected));
			}
		});
#endif// TEST_CASES & TEST_REVERSE_PARAMS_ALL_PRIMITIVES
	}

public:
	void ReverseReturn(const std::string& returnString) {
		_reverseReturn = {returnString};
	}
	void ReverseParams(const std::string& paramsString) {
		_reverseParams = {paramsString};
	}

private:
	SimpleTests _tests;
	std::optional<std::string> _reverseReturn;
	std::optional<std::string> _reverseParams;
};

CrossCallMaster g_plugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_plugin)

extern "C"
PLUGIN_API void ReverseReturn(const std::string& returnString) {
	g_plugin.ReverseReturn(returnString);
}

extern "C"
PLUGIN_API void NoParamReturnVoidCallback() {
	return;
}

extern "C"
PLUGIN_API bool NoParamReturnBoolCallback() {
	return true;
}

extern "C"
PLUGIN_API char NoParamReturnChar8Callback() {
	return 'P';
}

extern "C"
PLUGIN_API char16_t NoParamReturnChar16Callback() {
	return u'Ф';
}

extern "C"
PLUGIN_API int8_t NoParamReturnInt8Callback() {
	return 123;
}

extern "C"
PLUGIN_API int16_t NoParamReturnInt16Callback() {
	return 32765;
}

extern "C"
PLUGIN_API int32_t NoParamReturnInt32Callback() {
	return 2112211221;
}

extern "C"
PLUGIN_API int64_t NoParamReturnInt64Callback() {
	return 0x7654321001234567;
}

extern "C"
PLUGIN_API uint8_t NoParamReturnUInt8Callback() {
	return 0xCD;
}

extern "C"
PLUGIN_API uint16_t NoParamReturnUInt16Callback() {
	return 0xCDCD;
}

extern "C"
PLUGIN_API uint32_t NoParamReturnUInt32Callback() {
	return 0xCDCDCDCD;
}

extern "C"
PLUGIN_API uint64_t NoParamReturnUInt64Callback() {
	return 0xCDCDCDCDCDCDCDCD;
}

extern "C"
PLUGIN_API void* NoParamReturnPointerCallback() {
	return reinterpret_cast<void*>(0xAABBCCDD87655678);
}

extern "C"
PLUGIN_API float NoParamReturnFloatCallback() {
	return 0.123f;
}

extern "C"
PLUGIN_API double NoParamReturnDoubleCallback() {
	return 987.321;
}

using NoParamReturnFunctionCallbackFunc = int32_t (*)();

int32_t DaysInYear() {
	return 365;
}

extern "C"
PLUGIN_API NoParamReturnFunctionCallbackFunc NoParamReturnFunctionCallback() {
	return &DaysInYear;
}

extern "C"
PLUGIN_API void NoParamReturnStringCallback(std::string& stringRet) {
	std::construct_at(&stringRet, "Convertiplane");
}

extern "C"
PLUGIN_API void NoParamReturnArrayBoolCallback(std::vector<bool>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<bool>{false, true, true});
}

extern "C"
PLUGIN_API void NoParamReturnArrayChar8Callback(std::vector<char>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<char>{'p', 'l', 'u', 'g'});
}

extern "C"
PLUGIN_API void NoParamReturnArrayChar16Callback(std::vector<char16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<char16_t>{u'ч', u'а', u'р', u'!'});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt8Callback(std::vector<int8_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int8_t>{10, -15, 20});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt16Callback(std::vector<int16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int16_t>{10, -15, 20, -25});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt32Callback(std::vector<int32_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int32_t>{10, -15, 20, -25, 30});
}

extern "C"
PLUGIN_API void NoParamReturnArrayInt64Callback(std::vector<int64_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<int64_t>{10, -15, 20, -25, 30, -35});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt8Callback(std::vector<uint8_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint8_t>{1, 2, 3, 200});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt16Callback(std::vector<uint16_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint16_t>{1, 2, 3, 200, 60000});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt32Callback(std::vector<uint32_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint32_t>{1, 2, 3, 200, 60000, 4000000000});
}

extern "C"
PLUGIN_API void NoParamReturnArrayUInt64Callback(std::vector<uint64_t>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<uint64_t>{1, 2, 3, 200, 60000, 4000000000, 12223334445556667778ULL});
}

extern "C"
PLUGIN_API void NoParamReturnArrayPointerCallback(std::vector<void*>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<void*>{reinterpret_cast<void*>(0x0), reinterpret_cast<void*>(0xdeadbeafLL), reinterpret_cast<void*>(0xcdccddcccdddcccc)});
}

extern "C"
PLUGIN_API void NoParamReturnArrayFloatCallback(std::vector<float>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<float>{1.1f, -10.82f, 555.555f});
}

extern "C"
PLUGIN_API void NoParamReturnArrayDoubleCallback(std::vector<double>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<double>{1.1, -10.82, 555.555, 55555.55555, 123456789.98765});
}

extern "C"
PLUGIN_API void NoParamReturnArrayStringCallback(std::vector<std::string>& arrayRet) {
	std::construct_at(&arrayRet, std::vector<std::string>{"5", "true", "0.0", "Hello", "And Goodbay", "Another long string to test. Pi equal 3,1415926535 8979323846 2643383279 5028841971 6939937510"});
}

extern "C"
PLUGIN_API plugify::Vector2 NoParamReturnVector2Callback() {
	return {100.9f, 200.8f};
}

extern "C"
PLUGIN_API plugify::Vector3 NoParamReturnVector3Callback() {
	return {100.9f, 200.8f, 300.7f};
}

extern "C"
PLUGIN_API plugify::Vector4 NoParamReturnVector4Callback() {
	return {100.9f, 200.8f, 300.7f, 400.6f};
}

extern "C"
PLUGIN_API plugify::Matrix4x4 NoParamReturnMatrix4x4Callback() {
	return {1.1f, 2.2f, 3.3f, 4.4f, 9.9f, 1.1f, 2.2f, 3.3f, 8.8f, 9.9f, 1.1f, 2.2f, 7.7f, 8.8f, 9.9f, 1.1f};
}

extern "C"
PLUGIN_API void Param1Callback(int32_t a) {
	g_plugin.ReverseParams(std::format("{}", a));
}

extern "C"
PLUGIN_API void Param2Callback(int32_t a, float b) {
	g_plugin.ReverseParams(std::format("{}|{}", a, b));
}

extern "C"
PLUGIN_API void Param3Callback(int32_t a, float b, double c) {
	g_plugin.ReverseParams(std::format("{}|{}|{}", a, b, c));
}

extern "C"
PLUGIN_API void Param4Callback(int32_t a, float b, double c, const plugify::Vector4& d) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}", a, b, c, d.x, d.y, d.z, d.w));
}

extern "C"
PLUGIN_API void Param5Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e) {
	std::string e_formated;
	if (!e.empty()) {
		e_formated = std::format("'{}'", e[0]);
		for (auto it = std::next(e.begin()); it != e.end(); ++it) {
			std::format_to(std::back_inserter(e_formated), ", '{}'", *it);
		}
	}
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}", a, b, c, d.x, d.y, d.z, d.w, e_formated));
}

extern "C"
PLUGIN_API void Param6Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f) {
	std::string e_formated;
	if (!e.empty()) {
		e_formated = std::format("{}", e[0]);
		for (auto it = std::next(e.begin()); it != e.end(); ++it) {
			std::format_to(std::back_inserter(e_formated), ", {}", *it);
		}
	}
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated, static_cast<uint8_t>(f)));
}

extern "C"
PLUGIN_API void Param7Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g) {
	std::string e_formated;
	if (!e.empty()) {
		e_formated = std::format("{}", e[0]);
		for (auto it = std::next(e.begin()); it != e.end(); ++it) {
			std::format_to(std::back_inserter(e_formated), ", {}", *it);
		}
	}
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated, static_cast<uint8_t>(f), g));
}

extern "C"
PLUGIN_API void Param8Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h) {
	std::string e_formated;
	if (!e.empty()) {
		e_formated = std::format("{}", e[0]);
		for (auto it = std::next(e.begin()); it != e.end(); ++it) {
			std::format_to(std::back_inserter(e_formated), ", {}", *it);
		}
	}
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h)));
}

extern "C"
PLUGIN_API void Param9Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k) {
	std::string e_formated;
	if (!e.empty()) {
		e_formated = std::format("{}", e[0]);
		for (auto it = std::next(e.begin()); it != e.end(); ++it) {
			std::format_to(std::back_inserter(e_formated), ", {}", *it);
		}
	}
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k));
}

extern "C"
PLUGIN_API void Param10Callback(int32_t a, float b, double c, const plugify::Vector4& d, const std::vector<int64_t>& e, char f, const std::string& g, char16_t h, int16_t k, void* l) {
	std::string e_formated;
	if (!e.empty()) {
		e_formated = std::format("{}", e[0]);
		for (auto it = std::next(e.begin()); it != e.end(); ++it) {
			std::format_to(std::back_inserter(e_formated), ", {}", *it);
		}
	}
	g_plugin.ReverseParams(std::format("{}|{}|{}|{{{}, {}, {}, {}}}|{{{}}}|{}|{}|{}|{}|{}", a, b, c, d.x, d.y, d.z, d.w, e_formated, static_cast<uint8_t>(f), g, static_cast<uint16_t>(h), k, l));
}

extern "C"
PLUGIN_API void ParamRef1Callback(int32_t& a) {
	a = 147;
}

extern "C"
PLUGIN_API void ParamRef2Callback(int32_t& a, float& b) {
	a = 852;
	b = 0.1f;
}

extern "C"
PLUGIN_API void ParamRef3Callback(int32_t& a, float& b, double& c) {
	a = 369;
	b = 0.2f;
	c = 11111.11111;
}

extern "C"
PLUGIN_API void ParamRef4Callback(int32_t& a, float& b, double& c, plugify::Vector4& d) {
	a = 987;
	b = 0.3f;
	c = 22222.22222;
	d = {4.4f, 3.3f, 2.2f, 1.1f};
}

extern "C"
PLUGIN_API void ParamRef5Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e) {
	a = 456;
	b = 0.4f;
	c = 33333.33333;
	d = {1.4f, 4.3f, 3.2f, 2.1f};
	e = {};
}

extern "C"
PLUGIN_API void ParamRef6Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f) {
	a = 321;
	b = 0.5f;
	c = 44444.44444;
	d = {1.1f, 4.4f, 3.3f, 2.2f};
	e = {99};
	f = 'z';
}

extern "C"
PLUGIN_API void ParamRef7Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g) {
	a = 157;
	b = 0.6f;
	c = 55555.55555;
	d = {2.1f, 1.4f, 4.3f, 3.2f};
	e = {99, 8888};
	f = 'y';
	g = "my string";
}

extern "C"
PLUGIN_API void ParamRef8Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h) {
	a = 759;
	b = 0.7f;
	c = 66666.66666;
	d = {2.2f, 1.1f, 4.4f, 3.3f};
	e = {99, 8888, 777777};
	f = 'x';
	g = "his string";
	h = u'ъ';
}

extern "C"
PLUGIN_API void ParamRef9Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k) {
	a = 953;
	b = 0.8f;
	c = 77777.77777;
	d = {3.2f, 2.1f, 1.4f, 4.3f};
	e = {99, 8888, 777777, 66666666};
	f = 'w';
	g = "her string";
	h = u'ы';
	k = -30003;
}

extern "C"
PLUGIN_API void ParamRef10Callback(int32_t& a, float& b, double& c, plugify::Vector4& d, std::vector<int64_t>& e, char& f, std::string& g, char16_t& h, int16_t& k, void*& l) {
	a = 351;
	b = 0.9f;
	c = 88888.88888;
	d = {3.3f, 2.2f, 1.1f, 4.4f};
	e = {99, 8888, 777777, 66666666, 5555555555};
	f = 'v';
	g = "they string";
	h = u'ь';
	k = 30003;
	l = reinterpret_cast<void*>(0xabcdefLL);
}

extern "C"
PLUGIN_API void ParamRefVectorsCallback(std::vector<bool>& p1, std::vector<char>& p2, std::vector<char16_t>& p3, std::vector<int8_t>& p4, std::vector<int16_t>& p5,
	std::vector<int32_t>& p6, std::vector<int64_t>& p7, std::vector<uint8_t>& p8, std::vector<uint16_t>& p9, std::vector<uint32_t>& p10, std::vector<uint64_t>& p11,
	std::vector<void*>& p12, std::vector<float>& p13, std::vector<double>& p14, std::vector<std::string>& p15
) {
	p1 = {true, false};
	p2 = {'^'};
	p3 = {u'я', u'ц'};
	p4 = {-4, -3, -2, -1};
	p5 = {-555, -444, -333};
	p6 = {-66666, -77777};
	p7 = {-7666555444};
	p8 = {0, 1, 1, 2, 3, 5};
	p9 = {32999};
	p10 = {3000000000, 1};
	p11 = {1, 22, 333, 4444, 55555, 999999999999};
	p12 = {reinterpret_cast<void*>(13LL), reinterpret_cast<void*>(9LL), reinterpret_cast<void*>(5LL), reinterpret_cast<void*>(1LL)};
	p13 = {91.23f, 12.34f, 23.45f, 8.08f};
	p14 = {777.777777};
	p15 = {"one", "1 two", "1 2 three"};
}

extern "C"
PLUGIN_API int64_t ParamAllPrimitivesCallback(bool p1, char p2, char16_t p3, int8_t p4, int16_t p5, int32_t p6, int64_t p7, uint8_t p8, uint16_t p9, uint32_t p10,
	uint64_t p11, void* p12, float p13, double p14
) {
	g_plugin.ReverseParams(std::format("{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}|{}", p1, static_cast<uint8_t>(p2), static_cast<uint16_t>(p3), p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14));
	return 65;
}
