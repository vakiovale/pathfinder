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

            THEN("There should be an invalid argument exception") {
                REQUIRE_THROWS_AS(pathfinder::Node node(-2, -1),
                                  std::invalid_argument);
            }
        }

        WHEN("X coordinate is negative -1, 2") {

            THEN("There should be an invalid argument exception") {
                REQUIRE_THROWS_AS(pathfinder::Node node(-1, 2),
                                  std::invalid_argument);
            }
        }

        WHEN("Y coordinate is negative 2, -1") {

            THEN("There should be an invalid argument exception") {
                REQUIRE_THROWS_AS(pathfinder::Node node(2, -1),
                                  std::invalid_argument);
            }
        }

    }
}

SCENARIO("Nodes have a movement cost factor", "[node]") {

    GIVEN("A new node") {

        pathfinder::Node node(1.0f, 1.0f);

        WHEN("Movement cost factor is not changed") {

            THEN("Movement cost factor is 1.0f as default") {
               // REQUIRE(node.getMovementFactor == 1.0f, 0.01f);
            }

        }

    }
}
