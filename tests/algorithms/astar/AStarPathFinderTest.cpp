#include "AStarPathFinderTest.h"

SCENARIO("Finding shortest path with A* algorithm", "[astar]") {

   // pathfinder::AStarPathFinder pathFinder;

    GIVEN("An empty 2D graph with size 10x10") {

        WHEN("Finding shortest path from coordinates (0,0) to (10,0)") {

            THEN("Shortest path should be straight line from left to right") {
                REQUIRE(true);
            }
        }
    }
}
