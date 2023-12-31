cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

if(POLICY CMP0092)
    cmake_policy(SET CMP0092 NEW) # Don't add -W3 warning level by default.
endif()


project(cpp-lang-module VERSION 1.0.0.0  DESCRIPTION "C++ Language Module" HOMEPAGE_URL "https://github.com/untrustedmodders/cpp-lang-module" LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Wizard
#
set(WIZARD_BUILD_DLL ON CACHE INTERNAL "")
set(WIZARD_BUILD_SHARED_LIB ON CACHE INTERNAL "")
add_subdirectory(external/wizard)

#
# CPP Language Module for Wizard
#
file(GLOB_RECURSE CPPLM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${CPPLM_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE wizard)

include(GenerateExportHeader)
generate_export_header(${PROJECT_NAME} EXPORT_MACRO_NAME CPPLM_EXPORT EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/module_export.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/exports)

target_compile_definitions(${PROJECT_NAME} PRIVATE
        CPPLM_PLATFORM_WINDOWS=$<BOOL:${WIN32}>
        CPPLM_PLATFORM_APPLE=$<BOOL:${APPLE}>
        CPPLM_PLATFORM_LINUX=$<BOOL:${UNIX}>
        BINARY_MODULE_SUFFIX="${CMAKE_SHARED_LIBRARY_SUFFIX}"
        BINARY_MODULE_PREFIX="${CMAKE_SHARED_LIBRARY_PREFIX}")
