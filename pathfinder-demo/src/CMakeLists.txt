file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(SOURCES ${SOURCES})
message(STATUS "Found sources: " ${SOURCES})

set(HEADERS ${HEADERS})
message(STATUS "Found headers: " ${HEADERS})

include_directories("${PROJECT_SOURCE_DIR}/../libPathFinder/include")

add_library(PathFinderDemo ${SOURCES})
add_executable(pathfinderDemo main.cpp)
target_link_libraries(pathfinderDemo ${PROJECT_SOURCE_DIR}/../libPathFinder/libPathFinder.a)
