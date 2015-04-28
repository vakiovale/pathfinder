#include "ExtendedNodePointerTest.h"

SCENARIO("ExtendedNodePointer holds pointer to ExtendedNode",
         "[extendednode][node]") {

    GIVEN("ExtendedNodePointer with ExtendedNode in position (1,0)") {

        pathfinder::Node node(1,0);

        // Setting movement cost factor so that it can be changed
        // later and compared if the change has been done to the
        // node inside ExtendedNodePointer
        node.setMovementCostFactor(1.0f);

        pathfinder::ExtendedNode extNode(&node);
        pathfinder::ExtendedNodePointer extNodePointer(&extNode);

        WHEN("Getting reference to ExtendedNode from ExtendedNodePointer") {

            pathfinder::ExtendedNode referenceToExtendedNode =
                    extNodePointer.getExtendedNode();

            AND_WHEN("Changing inner Node's movement cost factor to 100") {

                node.setMovementCostFactor(100.0f);

                THEN("ExtendedNodePointer's Node should have its movement"
                     "cost factor changed as well") {

                    const pathfinder::Node retrievedNode =
                            referenceToExtendedNode.getNode();

                    float retrievedMovementCostFactor =
                            retrievedNode.getMovementCostFactor();

                    Approx approximation((double)retrievedMovementCostFactor);

                    REQUIRE(approximation == 100.0f);

                }

            }
        }
    }
}

SCENARIO("ExtendedNodePointers can be compared using less than operator",
         "[extendedenode][node]") {

    GIVEN("Two ExtendedNodePointers") {

        pathfinder::Node node1(1,0);
        pathfinder::Node node2(2,0);

        pathfinder::ExtendedNode extendedNode1(&node1);
        pathfinder::ExtendedNode extendedNode2(&node2);

        pathfinder::ExtendedNodePointer extNodePointer1(&extendedNode1);
        pathfinder::ExtendedNodePointer extNodePointer2(&extendedNode2);

        WHEN("ExtendedNodes have total costs 11 and 10") {

            extendedNode1.setTotalCost(11);
            extendedNode2.setTotalCost(10);

            THEN("First pointer < second pointer") {
                REQUIRE(extNodePointer1 < extNodePointer2);
            }

        }




    }

}
