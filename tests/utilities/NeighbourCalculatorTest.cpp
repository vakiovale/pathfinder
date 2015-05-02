#include "NeighbourCalculatorTest.h"

SCENARIO("Neighbour calculator calculates positions of nearby neighbours",
         "[neigbour][neighbourcalculator]") {

    GIVEN("NeighbourCalculator initialized with X position 3 and Y position 2") {

        pathfinder::NeighbourCalculator calc(3, 2);

        WHEN("Getting NORTH positions") {

            int x = calc.getNorthX();
            int y = calc.getNorthY();

            THEN("X position is 3 and Y position is 1") {
                REQUIRE(x == 3);
                REQUIRE(y == 1);
            }
        }

        WHEN("Getting SOUTH positions") {

            int x = calc.getSouthX();
            int y = calc.getSouthY();

            THEN("X position is 3 and Y position is 3") {
                REQUIRE(x == 3);
                REQUIRE(y == 3);
            }
        }

        WHEN("Getting EAST positions") {

            int x = calc.getEastX();
            int y = calc.getEastY();

            THEN("X position is 4 and Y position is 2") {
                REQUIRE(x == 4);
                REQUIRE(y == 2);
            }
        }

        WHEN("Getting WEST positions") {

            int x = calc.getWestX();
            int y = calc.getWestY();

            THEN("X position is 2 and Y position is 2") {
                REQUIRE(x == 2);
                REQUIRE(y == 2);
            }
        }

        WHEN("Getting NORTHWEST positions") {

            int x = calc.getNorthWestX();
            int y = calc.getNorthWestY();

            THEN("X position is 4 and Y position is 1") {
                REQUIRE(x == 4);
                REQUIRE(y == 1);
            }
        }

        WHEN("Getting SOUTHWEST positions") {

            int x = calc.getSouthWestX();
            int y = calc.getSouthWestY();

            THEN("X position is 2 and Y position is 3") {
                REQUIRE(x == 2);
                REQUIRE(y == 3);
            }
        }

        WHEN("Getting NORTHEAST positions") {

            int x = calc.getNorthEastX();
            int y = calc.getNorthEastY();

            THEN("X position is 4 and Y position is 1") {
                REQUIRE(x == 4);
                REQUIRE(y == 1);
            }
        }

        WHEN("Getting SOUTHEAST positions") {

            int x = calc.getSouthEastX();
            int y = calc.getSouthEastY();

            THEN("X position is 4 and Y position is 3") {
                REQUIRE(x == 4);
                REQUIRE(y == 3);
            }
        }

    }


}
