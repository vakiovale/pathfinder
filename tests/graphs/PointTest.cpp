#include "PointTest.h"

SCENARIO("Point has X and Y positions", "[point]") {

    GIVEN("x is 1 and y is 2") {

        int x = 1;
        int y = 2;

        WHEN("Initializing Point with x and y") {
            pathfinder::Point point(1, 2);

            THEN("Point's x coordinate is 1 and y coordinate is 2") {
                REQUIRE(point.getX() == 1);
                REQUIRE(point.getY() == 2);
            }
        }

    }

}
