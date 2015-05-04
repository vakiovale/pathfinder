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

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);

                REQUIRE(shortestPath.getPathLength() == 4);
                REQUIRE(shortestPath[0] == start);
                REQUIRE(shortestPath[1] == pathfinder::Node(1,0));
                REQUIRE(shortestPath[2] == pathfinder::Node(2,0));
                REQUIRE(shortestPath[3] == end);

            }
        }

        WHEN("Path starting point is (2,2) and ending point is (2,2)") {

            pathfinder::Node start(2,2);
            pathfinder::Node end(2,2);

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);

                REQUIRE(shortestPath.getPathLength() == 1);
                REQUIRE(shortestPath[0] == pathfinder::Node(2,2));

            }
        }

        WHEN("Path starting point is (2,4) and ending point is (1,3)") {

            pathfinder::Node start(2,4);
            pathfinder::Node end(1,3);

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);

                REQUIRE(shortestPath.getPathLength() == 2);
                REQUIRE(shortestPath[0] == pathfinder::Node(2,4));
                REQUIRE(shortestPath[1] == pathfinder::Node(1,3));

            }
        }

        WHEN("Path starting point is (3,1) and ending point is (0,3)") {

            pathfinder::Node start(3,1);
            pathfinder::Node end(0,3);

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);

                REQUIRE(shortestPath.getPathLength() == 4);
                REQUIRE(shortestPath[0] == start);
                REQUIRE(shortestPath[1] == pathfinder::Node(2,1));
                REQUIRE(shortestPath[2] == pathfinder::Node(1,2));
                REQUIRE(shortestPath[3] == end);

            }
        }

        WHEN("Path starting point is (0,1) and ending point is (4,3)") {

            pathfinder::Node start(0,1);
            pathfinder::Node end(4,3);

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);

                REQUIRE(shortestPath.getPathLength() == 5);
                REQUIRE(shortestPath[0] == start);
                REQUIRE(shortestPath[1] == pathfinder::Node(1,1));
                REQUIRE(shortestPath[2] == pathfinder::Node(2,2));
                REQUIRE(shortestPath[3] == pathfinder::Node(3,2));
                REQUIRE(shortestPath[4] == end);

            }
        }
    }

    GIVEN("A AStarPathfinder initialized with empty 1000x1000 2D grid map") {

        pathfinder::Graph graph;
        graph.create2DGridMap(1000);
        pathfinder::AStarPathFinder pathFinder(&graph);

        WHEN("Path starting point is (0,0) and ending point is (999,999)") {

            pathfinder::Node start(0,0);
            pathfinder::Node end(999,999);

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath =
                        pathFinder.findAndGetShortestPath(start, end);

                REQUIRE(shortestPath.getPathLength() == 1000);
                REQUIRE(shortestPath[0] == start);

                for(int i = 1; i < 999; i++) {
                    REQUIRE(shortestPath[i] == pathfinder::Node(i, i));
                }

                REQUIRE(shortestPath[999] == end);

            }
        }
    }
}

SCENARIO("Pathfinder finds shortest when used multiple times", "[pathfinder][astar]") {

    GIVEN("A AStarPathfinder initialized with empty 5x5 2D grid map") {

        pathfinder::Graph graph;
        graph.create2DGridMap(5);
        pathfinder::AStarPathFinder pathFinder(&graph);

        WHEN("Path starting point is (0,0) and ending point is (3,0)") {

            pathfinder::Node start1(0,0);
            pathfinder::Node end1(3,0);

            THEN("Pathfinder returns a shortest path") {

                pathfinder::Path shortestPath1 =
                        pathFinder.findAndGetShortestPath(start1, end1);

                REQUIRE(shortestPath1.getPathLength() == 4);
                REQUIRE(shortestPath1[0] == start1);
                REQUIRE(shortestPath1[1] == pathfinder::Node(1,0));
                REQUIRE(shortestPath1[2] == pathfinder::Node(2,0));
                REQUIRE(shortestPath1[3] == end1);

                AND_WHEN("Path starting point is (0,1) and ending point is (4,3)") {

                    pathfinder::Node start2(0,1);
                    pathfinder::Node end2(4,3);

                    THEN("Pathfinder returns a shortest path") {

                        pathfinder::Path shortestPath2 =
                                pathFinder.findAndGetShortestPath(start2, end2);

                        REQUIRE(shortestPath2.getPathLength() == 5);
                        REQUIRE(shortestPath2[0] == start2);
                        REQUIRE(shortestPath2[1] == pathfinder::Node(1,1));
                        REQUIRE(shortestPath2[2] == pathfinder::Node(2,2));
                        REQUIRE(shortestPath2[3] == pathfinder::Node(3,2));
                        REQUIRE(shortestPath2[4] == end2);

                        AND_WHEN("Path starting point is (3,0) and ending point is (0,0)") {

                            pathfinder::Node start3(3,0);
                            pathfinder::Node end3(0,0);

                            THEN("Pathfinder returns a shortest path") {

                                pathfinder::Path shortestPath3 =
                                        pathFinder.findAndGetShortestPath(start3, end3);

                                REQUIRE(shortestPath3.getPathLength() == 4);
                                REQUIRE(shortestPath3[0] == start3);
                                REQUIRE(shortestPath3[1] == pathfinder::Node(2,0));
                                REQUIRE(shortestPath3[2] == pathfinder::Node(1,0));
                                REQUIRE(shortestPath3[3] == end3);

                            }
                        }
                    }
                }
            }           
        }
    }
}


SCENARIO("After path finding all ExtendedNodes should be reset",
         "[pathfinder][astar]") {

    GIVEN("A AStarPathfinder initialized with empty 5x5 2D grid map") {

        pathfinder::Graph graph;
        graph.create2DGridMap(5);
        pathfinder::AStarPathFinder pathFinder(&graph);

        WHEN("Finding shortest path between (0,0) and (4,4)") {

            pathFinder.findAndGetShortestPath(pathfinder::Node(0,0),
                                              pathfinder::Node(4,4));

            THEN("All ExtendedNodes in the AStar's ExtendedGraph should"
                 "be reset so that current cost is maximum (float limit)") {

                pathfinder::ExtendedNodeGraph& extendedGraph =
                        pathFinder.getAllExtendedNodes();


                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {
                        pathfinder::ExtendedNode& extendedNode =
                                extendedGraph.getExtendedNodeInPosition(j,i);

                        Approx approximation((double)
                                             extendedNode.getCurrentCost());

                        REQUIRE(approximation ==
                                std::numeric_limits<float>::max());
                    }
                }

                AND_WHEN("Finding shortest path between (0,4) and (4,0)") {

                    pathFinder.findAndGetShortestPath(pathfinder::Node(0,4),
                                                      pathfinder::Node(4,0));

                    THEN("All ExtendedNodes in the AStar's ExtendedGraph should"
                         "be reset so that current cost is maximum (float limit)") {

                        pathfinder::ExtendedNodeGraph& extendedGraph2 =
                                pathFinder.getAllExtendedNodes();


                        for(int i = 0; i < 5; i++) {
                            for(int j = 0; j < 5; j++) {
                                pathfinder::ExtendedNode& extendedNode =
                                        extendedGraph2.getExtendedNodeInPosition(j,i);

                                Approx approximation((double)
                                                     extendedNode.getCurrentCost());

                                REQUIRE(approximation ==
                                        std::numeric_limits<float>::max());
                            }
                        }
                    }
                }
            }
        }
    }
}
