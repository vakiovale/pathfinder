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

SCENARIO("ExtendedNode has total cost value that can be changed", "[extendednode][node][astar]") {

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

SCENARIO("ExtendedNode has current cost value that can be changed",
         "[extendednode][node][astar]") {

    GIVEN("ExtendedNode in position (0,0)") {

        pathfinder::Node innerNode(0, 0);
        pathfinder::ExtendedNode node(&innerNode);

        WHEN("Getting current cost from node") {

            float currentCost = node.getCurrentCost();

            THEN("Current cost is 0") {

                Approx approximationCurrentCost((double)currentCost);
                REQUIRE(approximationCurrentCost == 0.0f);

            }
        }

        WHEN("Setting current cost to 1.5f") {

            node.setCurrentCost(1.5f);

            THEN("Current cost is 1.5f") {

                float currentCost = node.getCurrentCost();
                Approx approximation((double)currentCost);
                REQUIRE(approximation == 1.5f);

            }
        }

        WHEN("Setting current cost to 1.68f") {

            node.setCurrentCost(1.68f);

            THEN("Total cost is 1.68f") {

                float currentCost = node.getCurrentCost();
                Approx approximation((double)currentCost);
                REQUIRE(approximation == 1.68f);

            }
        }

        WHEN("Setting current cost to zero") {

            node.setCurrentCost(0);

            THEN("Current cost is 0") {

                float currentCost = node.getCurrentCost();
                Approx approximation((double)currentCost);
                REQUIRE(approximation == 0);

            }

        }
    }
}

SCENARIO("ExtendedNodes can be compared by total cost", "[extendednode][node]") {

    GIVEN("First ExtendedNode with position (2,4) and total cost 15.0 "
          "AND second ExtendedNode with position (1,0)") {

        pathfinder::Node innerNode(2,4);
        pathfinder::ExtendedNode first(&innerNode);
        first.setTotalCost(15.0f);

        pathfinder::Node otherInnerNode(1,0);
        pathfinder::ExtendedNode second(&otherInnerNode);

        WHEN("Second node's total cost is set to 1.0") {

            second.setTotalCost(1.0f);

            THEN("first < second") {
                REQUIRE(first < second);
            }

        }

        WHEN("Second node's total cost is set to 16.5") {

            second.setTotalCost(16.5);

            THEN("first !< second") {
                REQUIRE_FALSE(first < second);
            }
        }

        WHEN("Second node's total cost is set to 15.00001") {

            second.setTotalCost(15.00001);

            THEN("second < first") {
                REQUIRE(second < first);
            }

        }

        WHEN("Second node's total cost is set to 14.99991") {

            second.setTotalCost(14.99991);

            THEN("first < second") {
                REQUIRE(first < second);
            }
        }

        WHEN("Second node's total cost is also 15.0") {

            second.setTotalCost(15.0f);

            THEN("Result is undefined and will return true or false") {
                bool alwaysTrue = first < second ? true : true;
                REQUIRE(alwaysTrue);
            }
        }
    }

    GIVEN("Two ExtendedNodes with same inner Node)") {

        pathfinder::Node innerNode(1,1);
        pathfinder::ExtendedNode first(&innerNode);
        pathfinder::ExtendedNode second(&innerNode);

        WHEN("First total cost is set to 0 and second is set to 1") {

            first.setTotalCost(0);
            second.setTotalCost(1);

            THEN("second < first") {
                REQUIRE(second < first);
            }
        }

        WHEN("First total cost is set to 1 and second is set to 0") {

            first.setTotalCost(1);
            second.setTotalCost(0);

            THEN("first > second") {
                REQUIRE(first < second);
            }
        }

        WHEN("First total cost is set to -1 and second is set to 1") {

            first.setTotalCost(-1);
            second.setTotalCost(1);

            THEN("second < first") {
                REQUIRE(second < first);
            }
        }

        WHEN("First total cost is set to -2.2259 and second is set to -2.2260") {

            first.setTotalCost(-2.2259);
            second.setTotalCost(-2.2260);

            THEN("first < second") {
                REQUIRE(first < second);
            }
        }
    }
}

SCENARIO("ExtendedNodes are considered same if their inner Nodes are same",
         "[extendednode][node]") {

    GIVEN("ExtendedNode in position (1,0)") {

        pathfinder::Node node(1,0);
        pathfinder::ExtendedNode extendedNode(&node);

        WHEN("Other ExtendedNode is in position (1,1)") {

            pathfinder::Node otherNode(1,1);
            pathfinder::ExtendedNode otherExtNode(&otherNode);

            THEN("First ExtendedNode != other ExtendedNode") {
                REQUIRE(extendedNode != otherExtNode);
                REQUIRE_FALSE(extendedNode == otherExtNode);
            }
        }

        WHEN("Other ExtendedNode is in position (1,0)") {

            pathfinder::Node otherNode(1,0);
            pathfinder::ExtendedNode otherExtNode(&otherNode);

            THEN("First ExtendedNode == other ExtendedNode") {
                REQUIRE(extendedNode == otherExtNode);
                REQUIRE_FALSE(extendedNode != otherExtNode);
            }

        }
    }
}

SCENARIO("ExtendedNode can be set to be in open list", "[extendednode]") {

    GIVEN("ExtendedNode in position (1,0)") {

        pathfinder::Node node(1,0);
        pathfinder::ExtendedNode extNode(&node);

        WHEN("Nothing has been done") {

            THEN("ExtendedNode should not be in open list") {
                REQUIRE_FALSE(extNode.isInOpenList());
            }
        }

        WHEN("ExtendedNode is set to be in open list") {

            extNode.setNodeToOpenList();

            THEN("ExtendedNode should be in open list") {
                REQUIRE(extNode.isInOpenList());
            }

            AND_WHEN("ExtendedNode is set NOT to be in open list") {

                extNode.setNodeRemovedFromOpenList();

                THEN("ExtendedNode should not be in open list") {
                    REQUIRE_FALSE(extNode.isInOpenList());
                }
            }

        }

        WHEN("ExtendedNode is set NOT to be in open list") {

            extNode.setNodeRemovedFromOpenList();

            THEN("ExtendedNode should not be in open list") {
                REQUIRE_FALSE(extNode.isInOpenList());
            }
        }

    }

}
