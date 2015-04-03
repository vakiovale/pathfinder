file(GLOB_RECURSE SOURCES *.cpp *.h)
list(REMOVE_ITEM SOURCES "main.cpp" "main.h")
set(SOURCES ${SOURCES})
message(STATUS "Found sources: " ${SOURCES})

include_directories("${PROJECT_SOURCE_DIR}/src/graphs/")
include_directories("${PROJECT_SOURCE_DIR}/src/algorithms/astar/")
include_directories("${PROJECT_SOURCE_DIR}/src/pathtools/")
include_directories("${PROJECT_SOURCE_DIR}/include/")

add_library(PathFinder ${SOURCES})
add_executable(pathfinder main.cpp)
target_link_libraries(pathfinder PathFinder)
