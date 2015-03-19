cmake_minimum_required(VERSION 2.6)
project(pathfinder)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_definitions(-std=c++11)

include_directories("${PROJECT_SOURCE_DIR}/src/")
include_directories("${PROJECT_SOURCE_DIR}/include/")

add_subdirectory(test)

set(SOURCES ${SOURCES} src/main.cpp)
message(STATUS "Found sources: " ${SOURCES})

add_executable(pathfinder ${SOURCES})
target_link_libraries(pathfinder)
