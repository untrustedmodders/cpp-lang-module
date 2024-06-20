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

	void NoParamOnlyReturn() {
#if TEST_CASES & TEST_NO_PARAM_ONLY_RETURN_PRIMITIVES
		_tests.Add("NoParamReturnVoid", [](SimpleTests::Test& test) {
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
				test.Fail(std::format("Wrong return {}, expected {}", result, expected));
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
				test.Fail(std::format("Wrong return {{{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}}}, "
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
		
		_tests.Add("Param1", [](SimpleTests::Test& test) {
			cross_call_worker::Param1(intValue);
		});

		_tests.Add("Param2", [](SimpleTests::Test& test) {
			cross_call_worker::Param2(intValue, floatValue);
		});

		_tests.Add("Param3", [](SimpleTests::Test& test) {
			cross_call_worker::Param3(intValue, floatValue, doubleValue);
		});

		_tests.Add("Param4", [](SimpleTests::Test& test) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			cross_call_worker::Param4(intValue, floatValue, doubleValue, vector4Value);
		});

		_tests.Add("Param5", [](SimpleTests::Test& test) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			cross_call_worker::Param5(intValue, floatValue, doubleValue, vector4Value, longListValue);
		});

		_tests.Add("Param6", [](SimpleTests::Test& test) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			cross_call_worker::Param6(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue);
		});

		_tests.Add("Param7", [](SimpleTests::Test& test) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			const std::string stringValue = "Hello";
			cross_call_worker::Param7(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue);
		});

		_tests.Add("Param9", [](SimpleTests::Test& test) {
			const plugify::Vector4 vector4Value(1.0f, 2.0f, 3.0f, 4.0f);
			const std::vector<int64_t> longListValue = {100, 200, 300};
			const std::string stringValue = "Hello";
			cross_call_worker::Param9(intValue, floatValue, doubleValue, vector4Value, longListValue, charValue, stringValue, char16Value, shortValue);
		});

		_tests.Add("Param10", [](SimpleTests::Test& test) {
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
				test.Fail(std::format("Wrong charValue param {}, expected {}", charValue, charExpected));
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
				test.Fail(std::format("Wrong charValue param {}, expected {}", charValue, charExpected));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param {}, expected {}", stringValue, stringExpected));
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
				test.Fail(std::format("Wrong charValue param {}, expected {}", charValue, charExpected));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param {}, expected {}", stringValue, stringExpected));
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
				test.Fail(std::format("Wrong charValue param {}, expected {}", charValue, charExpected));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param {}, expected {}", stringValue, stringExpected));
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
				test.Fail(std::format("Wrong charValue param {}, expected {}", charValue, charExpected));
			}
			if (stringValue != stringExpected) {
				test.Fail(std::format("Wrong stringValue param {}, expected {}", stringValue, stringExpected));
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
					modified_formated = std::format("{}", stringArray[0]);
					for (auto it = std::next(stringArray.begin()); it != stringArray.end(); ++it) {
						std::format_to(std::back_inserter(modified_formated), ", {}", *it);
					}
				}
				std::string expected_formated = std::format("{}", stringArrayExpected[0]);
				for (auto it = std::next(stringArrayExpected.begin()); it != stringArrayExpected.end(); ++it) {
					std::format_to(std::back_inserter(expected_formated), ", {}", *it);
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
		//cross_call_worker::ReverseCalls();

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES
		
#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_PRIMITIVES

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS

#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_OBJECTS

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS

#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_ARRAYS

#if TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS

#endif// TEST_CASES & TEST_REVERSE_NO_PARAM_ONLY_RETURN_VECTORS
	}

	void ReverseParamsNoRefs() {
#if TEST_CASES & TEST_REVERSE_PARAMS_NO_REFS
#endif// TEST_CASES & TEST_REVERSE_PARAMS_NO_REFS
	}

	void ReverseParamsWithRefs() {
#if TEST_CASES & TEST_REVERSE_PARAMS_WITH_REFS
#endif// TEST_CASES & TEST_REVERSE_PARAMS_WITH_REFS
	}

	void ReverseParamsRefVectors() {
#if TEST_CASES & TEST_REVERSE_PARAMS_REF_ARRAYS
#endif// TEST_CASES & TEST_REVERSE_PARAMS_REF_ARRAYS
	}

	void ReverseParamsAllPrimitives() {
#if TEST_CASES & TEST_REVERSE_PARAMS_ALL_PRIMITIVES
#endif// TEST_CASES & TEST_REVERSE_PARAMS_ALL_PRIMITIVES
	}

private:
	SimpleTests _tests;
};

CrossCallMaster g_plugin;
EXPOSE_PLUGIN(PLUGIN_API, &g_plugin)
