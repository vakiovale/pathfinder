#include "NodeTest.h"

SCENARIO("Nodes have a certain position", "[node]") {

    GIVEN("A node with positive coordinates") {

        WHEN("Coordinates are 0,0") {

            pathfinder::Node node(0, 0);

            THEN("Node should be in a position where x is 0 and y is 0") {
                int xPosition = node.getX();
                int yPosition = node.getY();
                REQUIRE(xPosition == 0);
                REQUIRE(yPosition == 0);
            }
        }

        WHEN("Coordinates are 5,7") {

            pathfinder::Node node(5, 7);

            THEN("Node should be in a position where x is 5 and y is 7") {
                int xPosition = node.getX();
                int yPosition = node.getY();
                REQUIRE(xPosition == 5);
                REQUIRE(yPosition == 7);
            }
        }
    }

    GIVEN("A node with negative coordinates") {

        WHEN("Coordinates are -2,-1") {

            bool exceptionHasBeenThrown = false;
            try {
                pathfinder::Node node(-2, -1);
            } catch (std::invalid_argument& exception) {
                exceptionHasBeenThrown = true;
            }

            THEN("There should be an invalid argument exception") {
                REQUIRE(exceptionHasBeenThrown);
            }
        }

        WHEN("Coordinates are -1,2") {

            bool exceptionHasBeenThrown = false;
            try {
                pathfinder::Node node(-1, 2);
            } catch (std::invalid_argument& exception) {
                exceptionHasBeenThrown = true;
            }

            THEN("There should be an invalid argument exception") {
                REQUIRE(exceptionHasBeenThrown);
            }
        }

        WHEN("Coordinates are 2,-1") {

            bool exceptionHasBeenThrown = false;
            try {
                pathfinder::Node node(2, -1);
            } catch (std::invalid_argument& exception) {
                exceptionHasBeenThrown = true;
            }

            THEN("There should be an invalid argument exception") {
                REQUIRE(exceptionHasBeenThrown);
            }
        }

    }
}
