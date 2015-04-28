include_directories("${PROJECT_SOURCE_DIR}/src/graphs/")
include_directories("${PROJECT_SOURCE_DIR}/src/algorithms/")
include_directories("${PROJECT_SOURCE_DIR}/src/algorithms/astar/")
include_directories("${PROJECT_SOURCE_DIR}/src/pathtools/")
include_directories("${PROJECT_SOURCE_DIR}/src/utilities/")
include_directories("${PROJECT_SOURCE_DIR}/include/")

file(GLOB_RECURSE TEST_SOURCES *.cpp *.h)
set(TEST_SOURCES ${TEST_SOURCES})
message(STATUS "Found other sources: " ${TEST_SOURCES})

add_executable(TestAll ${TEST_SOURCES})
target_link_libraries(TestAll PathFinder)



