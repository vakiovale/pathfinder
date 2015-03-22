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
            AND_THEN("Node should not throw an invalid_argument exception") {
                bool exceptionHasBeenThrown =
                        checkIfNodeConstructorThrowsAnException(0, 0);

                REQUIRE(!exceptionHasBeenThrown);
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

        WHEN("Coordinates are 8, 11") {

            bool exceptionHasBeenThrown =
                    checkIfNodeConstructorThrowsAnException(8, 11);

            THEN("Node should not throw an invalid_argument exception") {
                REQUIRE(!exceptionHasBeenThrown);
            }
        }
    }

    GIVEN("A node with negative coordinates") {

        WHEN("Both coordinates are negative -2, -1") {

            bool exceptionHasBeenThrown =
                    checkIfNodeConstructorThrowsAnException(-2, -1);

            THEN("There should be an invalid argument exception") {
                REQUIRE(exceptionHasBeenThrown);
            }
        }

        WHEN("X coordinate is negative -1, 2") {

            bool exceptionHasBeenThrown =
                    checkIfNodeConstructorThrowsAnException(-1, 2);

            THEN("There should be an invalid argument exception") {
                REQUIRE(exceptionHasBeenThrown);
            }
        }

        WHEN("Y coordinate is negative 2, -1") {

            bool exceptionHasBeenThrown =
                    checkIfNodeConstructorThrowsAnException(2, -1);

            THEN("There should be an invalid argument exception") {
                REQUIRE(exceptionHasBeenThrown);
            }
        }

    }
}

/**
 * Creates a Node with parameters x and y which will be used
 * in a Node's constructor. Exception will be catched if
 * Node throws it.
 */
bool checkIfNodeConstructorThrowsAnException(int x, int y) {
    try {
        pathfinder::Node node(x, y);
    } catch (std::invalid_argument& exception) {
        return true;
    }
    return false;
}
