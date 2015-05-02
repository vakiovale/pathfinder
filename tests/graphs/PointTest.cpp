#include "PointTest.h"

SCENARIO("Point has X and Y positions", "[point]") {

    GIVEN("x is 1 and y is 2") {

        int x = 1;
        int y = 2;

        WHEN("Initializing Point with x and y") {
            pathfinder::Point point(x, y);

            THEN("Point's x coordinate is 1 and y coordinate is 2") {
                REQUIRE(point.getX() == 1);
                REQUIRE(point.getY() == 2);
            }
        }

    }

    GIVEN("x is 0 and y is 0") {

        int x = 0;
        int y = 0;

        WHEN("Initializing Point with x and y") {
            pathfinder::Point point(x, y);

            THEN("Point's x coordinate is 0 and y coordinate is 0") {
                REQUIRE(point.getX() == 0);
                REQUIRE(point.getY() == 0);
            }
        }
    }

    GIVEN("x is -1 and y is 2") {

        int x = -1;
        int y = 2;

        WHEN("Initializing Point with x and y") {
            pathfinder::Point point(x, y);

            THEN("Point's x coordinate is -1 and y coordinate is 2") {
                REQUIRE(point.getX() == -1);
                REQUIRE(point.getY() == 2);
            }
        }
    }

    GIVEN("x is 3 and y is -4") {

        int x = 3;
        int y = -4;

        WHEN("Initializing Point with x and y") {
            pathfinder::Point point(x, y);

            THEN("Point's x coordinate is 3 and y coordinate is -4") {
                REQUIRE(point.getX() == 3);
                REQUIRE(point.getY() == -4);
            }
        }
    }

    GIVEN("x is -1 and y is -5") {

        int x = -1;
        int y = -5;

        WHEN("Initializing Point with x and y") {
            pathfinder::Point point(x, y);

            THEN("Point's x coordinate is -1 and y coordinate is -5") {
                REQUIRE(point.getX() == -1);
                REQUIRE(point.getY() == -5);
            }
        }
    }

}

SCENARIO("Points can be compared", "[point]") {

    GIVEN("Point (1, 0)") {

        pathfinder::Point point(1,0);

        WHEN("Other point is (1,0)") {
            pathfinder::Point otherPoint(1,0);

            THEN("Point == other Point") {
                REQUIRE(point == otherPoint);
                REQUIRE_FALSE(point != otherPoint);
            }
        }

        WHEN("Other point is (1,1)") {
            pathfinder::Point otherPoint(1,1);

            THEN("Point != other Point") {
                REQUIRE(point != otherPoint);
                REQUIRE_FALSE(point == otherPoint);
            }
        }

        WHEN("Other point is (0,1)") {
            pathfinder::Point otherPoint(0,1);

            THEN("Point != other Point") {
                REQUIRE(point != otherPoint);
                REQUIRE_FALSE(point == otherPoint);
            }
        }

        WHEN("Other point is (2,2)") {
            pathfinder::Point otherPoint(2,2);

            THEN("Point != other Point") {
                REQUIRE(point != otherPoint);
                REQUIRE_FALSE(point == otherPoint);
            }
        }

    }

}
