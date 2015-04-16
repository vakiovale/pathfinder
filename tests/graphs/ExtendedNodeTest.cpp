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
