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

SCENARIO("Nodes have a changable movement cost factor", "[node]") {

    GIVEN("A new node with position (1, 1)") {

        pathfinder::Node node(1, 1);

        WHEN("Movement cost factor is not changed") {

            Approx approximationOfCostFactor(
                        (double)node.getMovementCostFactor());

            THEN("Movement cost factor is 1.0f as default") {
                REQUIRE(1.0 == approximationOfCostFactor);
            }

        }

        WHEN("Movement cost factor is changed to 1.5f") {

            node.setMovementCostFactor(1.5f);

            Approx approximationOfCostFactor(
                        (double)node.getMovementCostFactor());

            THEN("Movement cost factor is 1.5f") {
                REQUIRE(1.5 == approximationOfCostFactor);
            }

        }

        WHEN("Movement cost factor is changed to 0.0f") {

            node.setMovementCostFactor(0.0f);

            Approx approximationOfCostFactor(
                        (double)node.getMovementCostFactor());

            THEN("Movement cost factor is 0.0f") {
                REQUIRE(0 == approximationOfCostFactor);
            }

        }

        WHEN("Movement cost factor is changed to negative value -1.0f") {

            THEN("There should be an invalid_argument exception") {
                REQUIRE_THROWS_AS(node.setMovementCostFactor(-1.0f),
                                  std::invalid_argument);
            }

        }

        WHEN("Movement cost factor is changed to negative "
             "value close to 0.0f") {

            THEN("There should be an invalid_argument_exception") {
                REQUIRE_THROWS_AS(node.setMovementCostFactor(-0.001f),
                                  std::invalid_argument);
            }
        }

    }
}
