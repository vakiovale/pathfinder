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
                REQUIRE(cost == 1.0f);
            }


        }

    }

}
