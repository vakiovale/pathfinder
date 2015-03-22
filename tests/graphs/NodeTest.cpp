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

bool checkIfNodeConstructorThrowsAnException(int x, int y) {

    bool exceptionHasBeenThrown = false;
    try {
        pathfinder::Node node(-2, -1);
    } catch (std::invalid_argument& exception) {
        exceptionHasBeenThrown = true;
    }
    return exceptionHasBeenThrown;

}
