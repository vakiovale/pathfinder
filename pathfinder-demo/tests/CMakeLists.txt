include_directories("${PROJECT_SOURCE_DIR}/../include/")

file(GLOB_RECURSE TEST_SOURCES *.cpp *.h)
set(TEST_SOURCES ${TEST_SOURCES})

add_executable(TestDemoAll ${TEST_SOURCES})
target_link_libraries(TestDemoAll PathFinderDemo)
