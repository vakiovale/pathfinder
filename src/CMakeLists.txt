file(GLOB_RECURSE SOURCES *.cpp *.h)
list(REMOVE_ITEM SOURCES "main.cpp" "main.h")
set(SOURCES ${SOURCES})
message(STATUS "Found sources: " ${SOURCES})

add_library(PathFinder ${SOURCES})
add_executable(pathfinder main.cpp)
target_link_libraries(pathfinder PathFinder)
