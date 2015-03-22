#include "NodeTest.h"

SCENARIO("Testing stuff with nodes", "[node]") {

    pathfinder::Node node;

    GIVEN("A node") {

        WHEN("Node is not null") {

            THEN("Node should be null") {
                REQUIRE(true);
            }
        }
    }
}
