#include "OpenListTest.h"

SCENARIO("OpenList holds ExtendedNodes", "[openlist][extendednode]") {

    GIVEN("An empty OpenList") {

        pathfinder::OpenList openList;

        WHEN("Nothing is done") {

            THEN("OpenList is empty") {
                REQUIRE(openList.isEmpty());
            }

        }

    }

}
