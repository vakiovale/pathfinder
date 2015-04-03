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

SCENARIO("Two nodes are same if their position is same", "[node]") {

    GIVEN("Two nodes at the same positions (10, 10)") {

        pathfinder::Node firstNode(10, 10);
        pathfinder::Node secondNode(10, 10);

        WHEN("Nothing is changed in these nodes") {

            THEN("Two nodes equals as same") {
                REQUIRE(firstNode == secondNode);
            }
        }

        WHEN("Other node's movement cost factor is changed") {
            firstNode.setMovementCostFactor(2.0f);

            THEN("Two nodes still equals as same") {
                REQUIRE(firstNode == secondNode);
            }
        }

    }

    GIVEN("Two nodes at the same positions (2, 18)") {

        pathfinder::Node firstNode(2, 18);
        pathfinder::Node secondNode(2, 18);

        WHEN("Nothing is changed in these nodes") {

            THEN("Two nodes equals as same") {
                REQUIRE(firstNode == secondNode);
            }
        }

        WHEN("Other node's movement cost factor is changed") {
            secondNode.setMovementCostFactor(22.0f);

            THEN("Two nodes still equals as same") {
                REQUIRE(firstNode == secondNode);
            }
        }

        WHEN("Other node is changed to a different position") {

            secondNode = pathfinder::Node(12, 19);

            THEN("Two nodes should not be the same") {
                REQUIRE(secondNode != firstNode);
            }
        }

    }

    GIVEN("Two nodes at different positions") {

        pathfinder::Node firstNode(0, 0);
        pathfinder::Node secondNode(1, 2);

        WHEN("Nothing is changed in these nodes") {

            THEN("Two nodes should not be the same") {
                REQUIRE(firstNode != secondNode);
            }
        }

        WHEN("Other node's movement cost factor is changed") {
            firstNode.setMovementCostFactor(18.0f);

            THEN("Two nodes should still not be the same") {
                REQUIRE(firstNode != secondNode);
            }
        }

        WHEN("First node will be initialized again to the same position"
             "as the second node") {

            firstNode = pathfinder::Node(1, 2);

            THEN("Two nodes should be the same") {
                REQUIRE(firstNode == secondNode);
            }
        }
    }

    GIVEN("Two nodes that share the same x or y position") {

        WHEN("X position is same, but y position is different") {

            pathfinder::Node firstNode(8, 7);
            pathfinder::Node secondNode(8, 6);

            THEN("Nodes should not be the same") {
                REQUIRE(firstNode != secondNode);
            }
        }

        WHEN("X position is different, but y position is same") {

            pathfinder::Node firstNode(10, 11);
            pathfinder::Node secondNode(12, 11);

            THEN("Nodes should not be the same") {
                REQUIRE(firstNode != secondNode);
            }
        }
    }
}
