include_directories("${PROJECT_SOURCE_DIR}/../libPathFinder/include")
include_directories("${PROJECT_SOURCE_DIR}/../include")
include_directories("${PROJECT_SOURCE_DIR}/src/controllers")
include_directories("${PROJECT_SOURCE_DIR}/src/models")
include_directories("${PROJECT_SOURCE_DIR}/src/models/terrainblocks")

file(GLOB_RECURSE TEST_SOURCES *.cpp *.h)
set(TEST_SOURCES ${TEST_SOURCES})
message(STATUS "Found sources: " ${TEST_SOURCES})

add_executable(TestDemoAll ${TEST_SOURCES})
target_link_libraries(TestDemoAll PathFinderDemo)
target_link_libraries(TestDemoAll ${PROJECT_SOURCE_DIR}/../libPathFinder/libPathFinder.a)
