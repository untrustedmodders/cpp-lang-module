cmake_minimum_required(VERSION 3.14 FATAL_ERROR)


project(cpp-lang-module)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# CPP Language Module for Wizard
#
file(GLOB_RECURSE CPPLM_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(${PROJECT_NAME} SHARED ${CPPLM_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "external/wizard/include")
