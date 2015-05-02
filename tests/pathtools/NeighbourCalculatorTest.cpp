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

            THEN("X position is 2 and Y position is 1") {
                REQUIRE(x == 2);
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

    GIVEN("NeighbourCalculator initialized with X position 0 and Y position 0") {

        pathfinder::NeighbourCalculator calc(0,0);

        WHEN("Getting NORTH positions") {

            int x = calc.getNorthX();
            int y = calc.getNorthY();

            THEN("X position is 0 and Y position is -1") {
                REQUIRE(x == 0);
                REQUIRE(y == -1);
            }
        }

        WHEN("Getting SOUTH positions") {

            int x = calc.getSouthX();
            int y = calc.getSouthY();

            THEN("X position is 0 and Y position is 1") {
                REQUIRE(x == 0);
                REQUIRE(y == 1);
            }
        }

        WHEN("Getting EAST positions") {

            int x = calc.getEastX();
            int y = calc.getEastY();

            THEN("X position is 1 and Y position is 0") {
                REQUIRE(x == 1);
                REQUIRE(y == 0);
            }
        }

        WHEN("Getting WEST positions") {

            int x = calc.getWestX();
            int y = calc.getWestY();

            THEN("X position is -1 and Y position is 0") {
                REQUIRE(x == -1);
                REQUIRE(y == 0);
            }
        }

        WHEN("Getting NORTHWEST positions") {

            int x = calc.getNorthWestX();
            int y = calc.getNorthWestY();

            THEN("X position is -1 and Y position is -1") {
                REQUIRE(x == -1);
                REQUIRE(y == -1);
            }
        }

        WHEN("Getting SOUTHWEST positions") {

            int x = calc.getSouthWestX();
            int y = calc.getSouthWestY();

            THEN("X position is -1 and Y position is 1") {
                REQUIRE(x == -1);
                REQUIRE(y == 1);
            }
        }

        WHEN("Getting NORTHEAST positions") {

            int x = calc.getNorthEastX();
            int y = calc.getNorthEastY();

            THEN("X position is 1 and Y position is -1") {
                REQUIRE(x == 1);
                REQUIRE(y == -1);
            }
        }

        WHEN("Getting SOUTHEAST positions") {

            int x = calc.getSouthEastX();
            int y = calc.getSouthEastY();

            THEN("X position is 1 and Y position is 1") {
                REQUIRE(x == 1);
                REQUIRE(y == 1);
            }
        }

    }
}

SCENARIO("All the neighbour Points can be recieved as a vector",
         "[neighbour][neighbourcalculator][point]") {

    GIVEN("NeighbourCalculator initialized with position (2, 4)") {

        pathfinder::NeighbourCalculator calc(2, 4);

        WHEN("Getting a vector of Points from the initialized calculator") {
            std::vector<pathfinder::Point> neighbourPoints =
                    calc.getNeighbourPoints();

            THEN("Neighbouring Points are (2,3), (3,3), (3,4),"
                 "(3,5), (2,5), (1,5), (1,4) and (1,3) in that order") {

                pathfinder::Point north(2,3);
                pathfinder::Point northEast(3,3);
                pathfinder::Point east(3,4);
                pathfinder::Point southEast(3,5);

                pathfinder::Point south(2,5);
                pathfinder::Point southWest(1,5);
                pathfinder::Point west(1,4);
                pathfinder::Point northWest(1,3);

                REQUIRE(neighbourPoints[0] == north);
                REQUIRE(neighbourPoints[1] == northEast);
                REQUIRE(neighbourPoints[2] == east);
                REQUIRE(neighbourPoints[3] == southEast);

                REQUIRE(neighbourPoints[4] == south);
                REQUIRE(neighbourPoints[5] == southWest);
                REQUIRE(neighbourPoints[6] == west);
                REQUIRE(neighbourPoints[7] == northWest);

            }
        }

    }

    GIVEN("NeighbourCalculator initialized with position (7, 7)") {

        pathfinder::NeighbourCalculator calc(7, 7);

        WHEN("Getting a vector of Points from the initialized calculator") {
            std::vector<pathfinder::Point> neighbourPoints =
                    calc.getNeighbourPoints();

            THEN("Neighbouring Points are (7,6), (8,6), (8,7),"
                 "(8,8), (7,8), (6,8), (6,7) and (6,6) in that order") {

                pathfinder::Point north(7,6);
                pathfinder::Point northEast(8,6);
                pathfinder::Point east(8,7);
                pathfinder::Point southEast(8,8);

                pathfinder::Point south(7,8);
                pathfinder::Point southWest(6,8);
                pathfinder::Point west(6,7);
                pathfinder::Point northWest(6,6);

                REQUIRE(neighbourPoints[0] == north);
                REQUIRE(neighbourPoints[1] == northEast);
                REQUIRE(neighbourPoints[2] == east);
                REQUIRE(neighbourPoints[3] == southEast);

                REQUIRE(neighbourPoints[4] == south);
                REQUIRE(neighbourPoints[5] == southWest);
                REQUIRE(neighbourPoints[6] == west);
                REQUIRE(neighbourPoints[7] == northWest);

            }
        }

    }

}
