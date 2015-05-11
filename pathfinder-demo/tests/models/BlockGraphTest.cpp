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

    GIVEN("A BlockGraph sized 3x3") {

        BlockGraph graph(2);

        THEN("Graph has plain terrain in each of it's nodes") {
            REQUIRE(graph.getTerrainInPosition(0,0) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(1,0) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(0,1) == PLAIN);
            REQUIRE(graph.getTerrainInPosition(1,1) == PLAIN);
        }
    }

}
