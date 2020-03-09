cmake_minimum_required(VERSION 3.5)

project(memory_test LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake)
add_executable(test test.cpp)
target_include_directories( test PRIVATE ${CMAKE_SOURCE_DIR}/../includes )


include(CTest)
include(Catch)
include(ParseAndAddCatchTests)

catch_discover_tests(test)
