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


