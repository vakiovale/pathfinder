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

        WHEN("Adding a node to the path") {

            pathfinder::Node node(2,7);
            path.addNode(node);

            THEN("There should be a path (although it's very short)") {
                REQUIRE(path.pathExists());
            }

        }

    }

}
