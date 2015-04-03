#include "PathTest.h"

SCENARIO("Path holds nodes which belong to a specific path") {

    GIVEN("An empty path") {

        pathfinder::Path path;

        WHEN("Checking if a path exists") {

            bool pathExists = path.pathExists();

            THEN("There should not be a path") {
                REQUIRE_FALSE(pathExists);
            }
        }

    }

}
