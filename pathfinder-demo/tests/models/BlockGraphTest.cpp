#include "BlockGraphTest.h"

SCENARIO("BlockGraph creates a graph with specific size", "[blockgraph][graph]") {

    GIVEN("Size 40") {

        int size = 40;
        WHEN("Initializing BlockGraph with size 40") {

            BlockGraph graph(40);

            THEN("BlockGraph has width and height 40") {
                REQUIRE(graph.getWidth() == 40);
                REQUIRE(graph.getHeight() == 40);
            }
        }
    }

    GIVEN("No size") {

        WHEN("Initializing BlockGraph without parameters") {

            BlockGraph graph;

            THEN("BlockGraph has width and height 35") {
                REQUIRE(graph.getWidth() == 35);
                REQUIRE(graph.getHeight() == 35);
            }
        }
    }
}

SCENARIO("BlockGraph holds different terrain for each node in the graph",
         "[terrain][node][blockgraph]") {

    GIVEN("A BlockGraph sized 2x2") {

        BlockGraph graph(2);

        THEN("Graph has plain terrain in each of it's nodes "
             "(checked with x and y)") {
            REQUIRE(graph.getTerrainInPosition(0,0) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(1,0) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(0,1) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(1,1) == PLAIN);
        }

        THEN("Graph has plain terrain in each of it's nodes "
             "(checked with Points)") {
            REQUIRE(graph.getTerrainInPosition(Point(0, 0)) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(Point(1, 0)) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(Point(0, 1)) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(Point(1, 1)) == PLAIN);
        }

        WHEN("Changing terrain in blocks (1,0) and (1,1) to GRASS") {

            graph.changeBlockTerrainInPoint(Point(1,0), GRASS);
            graph.changeBlockTerrainInPoint(Point(1,1), GRASS);

            THEN("Graph has PLAIN terrain in blocks (0,0) and (0,1)"
                 "and GRASS terrain in blocks (1,0) and (1,1)") {
                REQUIRE(graph.getTerrainInPosition(Point(0, 0)) == PLAIN);
                REQUIRE(graph.getTerrainInPosition(Point(1, 0)) == GRASS);
                REQUIRE(graph.getTerrainInPosition(Point(0, 1)) == PLAIN);
                REQUIRE(graph.getTerrainInPosition(Point(1, 1)) == GRASS);
            }

        }

        WHEN("Changing terrain in blocks (0,0) to WALL and (1,0) to GRASS") {

            graph.changeBlockTerrainInPoint(Point(0,0), WALL);
            graph.changeBlockTerrainInPoint(Point(1,0), GRASS);

            THEN("Graph has PLAIN terrain in blocks (0,1) and (1,1)"
                 "and GRASS terrain in block (1,0) "
                 "and WALL terrain in block (0,0)") {
                REQUIRE(graph.getTerrainInPosition(Point(0, 0)) == WALL);
                REQUIRE(graph.getTerrainInPosition(Point(1, 0)) == GRASS);
                REQUIRE(graph.getTerrainInPosition(Point(0, 1)) == PLAIN);
                REQUIRE(graph.getTerrainInPosition(Point(1, 1)) == PLAIN);
            }

            AND_WHEN("Changing terrain in blocks (0,0) to PLAIN "
                     "and (0,1) to WALL") {

                graph.changeBlockTerrainInPoint(Point(0,0), PLAIN);
                graph.changeBlockTerrainInPoint(Point(0,1), WALL);

                THEN("Graph has PLAIN terrain in blocks (0,0) and (1,1)"
                     "and GRASS terrain in block (1,0) "
                     "and WALL terrain in block (0,1)") {
                    REQUIRE(graph.getTerrainInPosition(Point(0, 0)) == PLAIN);
                    REQUIRE(graph.getTerrainInPosition(Point(1, 0)) == GRASS);
                    REQUIRE(graph.getTerrainInPosition(Point(0, 1)) == WALL);
                    REQUIRE(graph.getTerrainInPosition(Point(1, 1)) == PLAIN);
                }
             }
        }

        WHEN("Changing terrain in blocks (0,0) and (1,1) to WATER") {

            graph.changeBlockTerrainInPoint(Point(0,0), WATER);
            graph.changeBlockTerrainInPoint(Point(1,1), WATER);

            THEN("Graph has PLAIN terrain in blocks (1,0) and (0,1)"
                 "and WATER terrain in blocks (0,0) and (1,1)") {
                REQUIRE(graph.getTerrainInPosition(Point(0, 0)) == WATER);
                REQUIRE(graph.getTerrainInPosition(Point(1, 0)) == PLAIN);
                REQUIRE(graph.getTerrainInPosition(Point(0, 1)) == PLAIN);
                REQUIRE(graph.getTerrainInPosition(Point(1, 1)) == WATER);
            }

        }
    }
}

SCENARIO("BlockGraph holds Point in the same position as the Node it is "
         "initialized with","[node][point][blockgraph]") {

    GIVEN("A BlockGraph sized 2x2") {

        BlockGraph graph(2);



    }
}
