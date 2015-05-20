cmake_minimum_required(VERSION 2.8)
project(pathfinder)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_definitions(-std=c++0x)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
add_test(NAME TestAll COMMAND Test)
