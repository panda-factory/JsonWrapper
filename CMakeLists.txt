cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)
project(jsonwrapper VERSION 0.0.0
    DESCRIPTION ""
    HOMEPAGE_URL ""
    LANGUAGES CXX)

option(BUILDING_SHARED "compile for shared library" OFF)
option(USE_CJSON "enable benchmark test for taskrunner" ON)
option(ENABLE_BENCHMARK "enable benchmark test for taskrunner" OFF)
option(ENABLE_UNITTESTS "enable UT for showmaker" ON)
option(ENABLE_EXAMPLES "enable examples for taskrunner" ON)

set(PROJECT_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/")
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_subdirectory(src)

if (USE_CJSON)
    add_subdirectory(third-party/cJSON)
endif()


if(ENABLE_UNITTESTS)
    ADD_DEFINITIONS(-DTESTING=1)
    add_subdirectory(test)
endif()