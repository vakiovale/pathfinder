#include "ExtendedNodeTest.h"

SCENARIO("ExtendedNode has a pointer to Node", "[extendednode][node]") {

    GIVEN("ExtendedNode binded with node in position (2,8)") {

        pathfinder::Node node(2, 8);
        pathfinder::ExtendedNode extNode(&node);

        WHEN("Getting a reference to node inside ExtendedNode") {

            const pathfinder::Node referenceNode = extNode.getNode();

            THEN("Referenced node is the same as the binded node") {
                REQUIRE(referenceNode == node);
            }

        }

        WHEN("Changing binded node's inner value") {
            node.setMovementCostFactor(15187.581f);

            THEN("Node inside ExtendedNode should have it's inner value "
                 "changed as well") {

                const pathfinder::Node referenceNode = extNode.getNode();

                Approx approximationOfCostFactor(
                            (double)referenceNode.getMovementCostFactor());

                REQUIRE(approximationOfCostFactor == 15187.581f);

            }
        }

    }

}

SCENARIO("ExtendedNode has total cost value that can be changed") {

    GIVEN("ExtendedNode in position (4,7)") {

        pathfinder::Node innerNode(4, 7);
        pathfinder::ExtendedNode node(&innerNode);

        WHEN("Getting total cost from node") {

            float totalCost = node.getTotalCost();

            THEN("Total cost is -1") {

                Approx approximationTotalCost((double)totalCost);
                REQUIRE(approximationTotalCost == -1.0f);

            }

        }

        WHEN("Setting total cost to 24.5f") {

            node.setTotalCost(24.5f);

            THEN("Total cost is 24.5f") {

                float totalCost = node.getTotalCost();
                Approx approximation((double)totalCost);
                REQUIRE(approximation == 24.5f);

            }

        }

        WHEN("Setting total cost to 12.12f") {

            node.setTotalCost(12.12f);

            THEN("Total cost is 12.12f") {

                float totalCost = node.getTotalCost();
                Approx approximation((double)totalCost);
                REQUIRE(approximation == 12.12f);

            }

        }

        WHEN("Setting total cost to zero") {

            node.setTotalCost(0);

            THEN("Total cost is 0") {

                float totalCost = node.getTotalCost();
                Approx approximation((double)totalCost);
                REQUIRE(approximation == 0);

            }

        }

    }

}
