#include "HeuristicTest.h"

SCENARIO("Estimates distance between two Nodes") {

    GIVEN("Heuristic with diagonal movement cost factor 1.4") {

        pathfinder::Heuristic heuristic;
        heuristic.setDiagonalMovementCostFactor(1.4f);

        WHEN("Nodes are in positions (0,0) and (3,2)") {
            pathfinder::Node startNode(0,0);
            pathfinder::Node endNode(3,2);

            THEN("Estimated distance is 3.8") {
                Approx expected(3.8);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (6,0) and (6,5)") {
            pathfinder::Node startNode(6,0);
            pathfinder::Node endNode(6,5);

            THEN("Estimated distance is 5") {
                Approx expected(5);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (1,4) and (5,2)") {
            pathfinder::Node startNode(1,5);
            pathfinder::Node endNode(5,2);

            THEN("Estimated distance is 5.2") {
                Approx expected(5.2);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (4,5) and (4,0)") {
            pathfinder::Node startNode(4,5);
            pathfinder::Node endNode(4,0);

            THEN("Estimated distance is 5") {
                Approx expected(5);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (5,4) and (2,1)") {
            pathfinder::Node startNode(5,4);
            pathfinder::Node endNode(2,1);

            THEN("Estimated distance is 4.2") {
                Approx expected(4.2);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (6,1) and (1,1)") {
            pathfinder::Node startNode(6,1);
            pathfinder::Node endNode(1,1);

            THEN("Estimated distance is 5") {
                Approx expected(5);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (1,5) and (5,0)") {
            pathfinder::Node startNode(1,5);
            pathfinder::Node endNode(5,0);

            THEN("Estimated distance is 6.6") {
                Approx expected(6.6);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (3,3) and (3,3)") {
            pathfinder::Node startNode(3,3);
            pathfinder::Node endNode(3,3);

            THEN("Estimated distance is 0") {
                Approx expected(0);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }

        WHEN("Nodes are in positions (1,6) and (1,6)") {
            pathfinder::Node startNode(1,6);
            pathfinder::Node endNode(1,6);

            THEN("Estimated distance is 0") {
                Approx expected(0);
                double estimatedDistance =
                        heuristic.estimateDistance(startNode, endNode);

                REQUIRE(estimatedDistance == expected);
            }

        }


    }

}
