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


    }

}
