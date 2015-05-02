#include "MovementCostCalculatorTest.h"

SCENARIO("MovementCostCalculator calculates movement cost from one Node to"
         "other neighbouring Node", "[movement][node]") {

    GIVEN("MovementCostCalculator") {

        pathfinder::MovementCostCalculator calc;

        WHEN("Calculating movement cost from Node (1,1) to Node (2,1)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(2,1);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.0f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.0f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (1,0)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(1,0);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.0f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.0f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (1,2)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(1,2);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.0f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.0f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (0,1)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(0,1);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.0f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.0f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (2,0)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(2,0);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.4f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.4f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (2,2)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(2,2);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.4f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.4f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (0,2)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(0,2);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.4f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.4f);
            }
        }

        WHEN("Calculating movement cost from Node (1,1) to Node (0,0)") {

            pathfinder::Node start(1,1);
            pathfinder::Node end(0,0);

            float cost = calc.getCostBetweenNodes(start, end);

            THEN("Cost is 1.4f") {
                Approx approximation((double) cost);
                REQUIRE(approximation == 1.4f);
            }
        }

    }

    GIVEN("Nodes with different movement cost factors "
          "and MovementCostCalculator") {

        pathfinder::Node middle(1,2);

        pathfinder::Node north(1,1);
        north.setMovementCostFactor(1.0f);

        pathfinder::Node northEast(2,1);
        northEast.setMovementCostFactor(1.5f);

        pathfinder::Node east(2,2);
        east.setMovementCostFactor(2.5f);

        pathfinder::Node southEast(2,3);
        southEast.setMovementCostFactor(3.0f);

        pathfinder::Node south(1,3);
        south.setMovementCostFactor(2.2f);

        pathfinder::Node southWest(0,3);
        southWest.setMovementCostFactor(1.2f);

        pathfinder::Node west(0,2);
        west.setMovementCostFactor(1.8f);

        pathfinder::Node northWest(0,1);
        northWest.setMovementCostFactor(2.0f);

        pathfinder::MovementCostCalculator calc;

        WHEN("Moving north (factor 1.0f)") {
            float cost = calc.getCostBetweenNodes(middle, north);
            Approx approximation((double) cost);

            THEN("Cost is 1.0") {
                REQUIRE(approximation == 1.0f);
            }
        }

        WHEN("Moving north east (factor 1.5f)") {
            float cost = calc.getCostBetweenNodes(middle, northEast);
            Approx approximation((double) cost);

            THEN("Cost is 2.1") {
                REQUIRE(approximation == 2.1f);
            }
        }

        WHEN("Moving east (factor 2.5f)") {
            float cost = calc.getCostBetweenNodes(middle, east);
            Approx approximation((double) cost);

            THEN("Cost is 2.5") {
                REQUIRE(approximation == 2.5f);
            }
        }

        WHEN("Moving south east (factor 3.0f)") {
            float cost = calc.getCostBetweenNodes(middle, southEast);
            Approx approximation((double) cost);

            THEN("Cost is 4.2") {
                REQUIRE(approximation == 4.2f);
            }
        }

        WHEN("Moving south (factor 2.2f)") {
            float cost = calc.getCostBetweenNodes(middle, south);
            Approx approximation((double) cost);

            THEN("Cost is 2.2") {
                REQUIRE(approximation == 2.2f);
            }
        }

        WHEN("Moving south west (factor 1.2f)") {
            float cost = calc.getCostBetweenNodes(middle, southWest);
            Approx approximation((double) cost);

            THEN("Cost is 1.68f") {
                REQUIRE(approximation == 1.68f);
            }
        }

        WHEN("Moving west (factor 1.8f)")  {
            float cost = calc.getCostBetweenNodes(middle, west);
            Approx approximation((double) cost);

            THEN("Cost is 1.8") {
                REQUIRE(approximation == 1.8f);
            }
        }

        WHEN("Moving north west (factor 2.0f)") {
            float cost = calc.getCostBetweenNodes(middle, northWest);
            Approx approximation((double) cost);

            THEN("Cost is 2.8") {
                REQUIRE(approximation == 2.8f);
            }
        }



    }

}
