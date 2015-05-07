file(GLOB_RECURSE SOURCES *.cpp)
file(GLOB_RECURSE HEADERS *.h)

set(SOURCES ${SOURCES})
message(STATUS "Found sources: " ${SOURCES})

set(HEADERS ${HEADERS})
message(STATUS "Found headers: " ${HEADERS})

include_directories("${PROJECT_SOURCE_DIR}/src/graphs/")
include_directories("${PROJECT_SOURCE_DIR}/src/algorithms/")
include_directories("${PROJECT_SOURCE_DIR}/src/algorithms/astar/")
include_directories("${PROJECT_SOURCE_DIR}/src/pathtools/")
include_directories("${PROJECT_SOURCE_DIR}/src/utilities/")
include_directories("${PROJECT_SOURCE_DIR}/include/")

add_library(PathFinder ${SOURCES})

install(TARGETS PathFinder DESTINATION "${PROJECT_BINARY_DIR}/libPathFinder")
install(FILES ${HEADERS} DESTINATION "${PROJECT_BINARY_DIR}/libPathFinder/include")
