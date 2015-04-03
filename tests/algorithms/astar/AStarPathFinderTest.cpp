#include "AStarPathFinderTest.h"

SCENARIO("Pathfinder can be initialized with a graph", "[pathfinder][astar]") {

    GIVEN("A 5x5 graph") {

        pathfinder::Graph graph;
        graph.create2DGridMap(5);

        WHEN("Initializing AStarPathFinder with graph") {

            pathfinder::AStarPathFinder pathFinder(&graph);

            THEN("PathFinder has 25 nodes in its graph") {
                REQUIRE(pathFinder.getNumberOfNodes() == 25);
            }

        }

    }

    GIVEN("AStarPathFinder initialized with an empty graph") {

        pathfinder::Graph graph;
        pathfinder::AStarPathFinder pathFinder(&graph);

        WHEN("Nothing is done to the graph") {

            THEN("Pathfinder has 0 nodes in its graph") {
                REQUIRE(pathFinder.getNumberOfNodes() == 0);
            }

        }

        WHEN("Initializing graph to 3x3 graph") {

            graph.create2DGridMap(3);

            THEN("Pathfinder has 9 nodes in its graph") {
                REQUIRE(pathFinder.getNumberOfNodes() == 9);
            }
        }
    }
}

SCENARIO("Pathfinder finds shortest paths", "[pathfinder][astar]") {

    GIVEN("A AStarPathfinder initialized with empty 5x5 2D grid map") {

        pathfinder::Graph graph;
        graph.create2DGridMap(5);
        pathfinder::AStarPathFinder pathFinder(&graph);

        WHEN("Path starting point is (0,0) and ending point is (3,0)") {

            pathfinder::Node start(0,0);
            pathfinder::Node end(3,0);

            THEN("Pathfinder returns a path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);
                REQUIRE(shortestPath.pathExists());

            }

        }

    }

}
