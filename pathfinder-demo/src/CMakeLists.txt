file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(SOURCES ${SOURCES})
message(STATUS "Found demo sources: " ${SOURCES})

set(HEADERS ${HEADERS})
message(STATUS "Found demo headers: " ${HEADERS})

include_directories("${PROJECT_SOURCE_DIR}/SFML/include/")
include_directories("${PROJECT_SOURCE_DIR}/../libPathFinder/include")
include_directories("${PROJECT_SOURCE_DIR}/src/controllers")
include_directories("${PROJECT_SOURCE_DIR}/src/models")

add_library(PathFinderDemo ${SOURCES} ${HEADERS})
add_executable(pathfinderDemo main.cpp)
target_link_libraries(pathfinderDemo PathFinderDemo)
target_link_libraries(pathfinderDemo
    ${PROJECT_SOURCE_DIR}/../libPathFinder/libPathFinder.a
    ${PROJECT_SOURCE_DIR}/SFML/lib/libsfml-graphics.so
    ${PROJECT_SOURCE_DIR}/SFML/lib/libsfml-window.so
    ${PROJECT_SOURCE_DIR}/SFML/lib/libsfml-system.so)
