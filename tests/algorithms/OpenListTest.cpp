#include "OpenListTest.h"

SCENARIO("OpenList can be empty", "[openlist][extendednode]") {

    GIVEN("An empty OpenList") {

        pathfinder::OpenList openList;

        WHEN("Nothing is done") {

            THEN("OpenList is empty") {
                REQUIRE(openList.isEmpty());
            }

        }
    }
}

SCENARIO("ExtendedNodes can be added/removed to/from OpenList",
         "[openlist][extendednode]") {

    GIVEN("An empty OpenList") {

        pathfinder::OpenList openList;

        WHEN("Adding two ExtendedNodes with total costs 3 and 2 to open list") {

            pathfinder::Node node(1,0);
            pathfinder::ExtendedNode extNode1(&node);
            pathfinder::ExtendedNode extNode2(&node);

            extNode1.setTotalCost(3);
            extNode2.setTotalCost(2);

            openList.add(extNode1);
            openList.add(extNode2);

            THEN("Best node in the open list has total cost 2") {

                pathfinder::ExtendedNode bestNode = openList.getBestNode();

                Approx approximation((double)
                                     bestNode.getTotalCost());

                REQUIRE(approximation == 2);

            }

            AND_WHEN("Adding ExtendedNode with total cost 5") {

                pathfinder::ExtendedNode extNode3(&node);
                extNode3.setTotalCost(5);
                openList.add(extNode3);

                THEN("Best node in the open list has total cost 2") {

                    pathfinder::ExtendedNode bestNode = openList.getBestNode();

                    Approx approximation((double)
                                         bestNode.getTotalCost());

                    REQUIRE(approximation == 2);

                }

                AND_WHEN("Removing best node from the open list") {

                    openList.removeBestNode();

                    THEN("Best node in the open list has total cost 3") {

                        pathfinder::ExtendedNode bestNode = openList.getBestNode();

                        Approx approximation((double)
                                             bestNode.getTotalCost());

                        REQUIRE(approximation == 3);

                    }

                    AND_WHEN("Adding ExtendedNode with total cost 1") {

                        pathfinder::ExtendedNode extNode4(&node);
                        extNode4.setTotalCost(1);
                        openList.add(extNode4);

                        THEN("Best node in the open list has total cost 1") {

                            pathfinder::ExtendedNode bestNode = openList.getBestNode();

                            Approx approximation((double)
                                                 bestNode.getTotalCost());

                            REQUIRE(approximation == 1);

                        }
                    }

                }
            }
        }
    }
}

SCENARIO("ExtendedNodes can be checked if they are in the OpenList",
         "[openlist][extendednode]") {

    GIVEN("OpenList with two ExtendedNodes in positions (2,1) and (2,2)") {

        pathfinder::Node node1(2, 1);
        pathfinder::Node node2(2, 2);

        pathfinder::ExtendedNode extNode1(&node1);
        pathfinder::ExtendedNode extNode2(&node2);

        pathfinder::OpenList openList;
        openList.add(extNode1);
        openList.add(extNode2);

        WHEN("Checking if there is ExtendedNode (2,1) in the open list") {

            bool isInOpenList = openList.contains(extNode1);

            THEN("Open list contains ExtendedNode (2, 1)") {
                REQUIRE(isInOpenList);
            }

        }

        WHEN("Checking if there is ExtendedNode (2, 2) in the open list") {

            bool isInOpenList = openList.contains(extNode2);

            THEN("Open list contains ExtendedNode (2, 2)") {
                REQUIRE(isInOpenList);
            }

        }

        WHEN("Checking if there is ExtendedNode (1, 0) in the open list") {

            pathfinder::Node node3(1, 0);
            pathfinder::ExtendedNode extNode3(&node3);
            openList.add(extNode3);

            bool isInOpenList = openList.contains(extNode3);

            THEN("Open list does not contain ExtendedNode (1, 0)") {
                REQUIRE_FALSE(isInOpenList);
            }

        }

    }

}
