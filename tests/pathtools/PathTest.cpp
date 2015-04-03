#include "PathTest.h"

SCENARIO("Nodes can be added and removed from a path") {

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

        WHEN("Adding one node and removing the last node from the path") {

            path.addNode(pathfinder::Node(3,6));
            path.removeLastNode();

            THEN("There should not be a path") {
                REQUIRE_FALSE(path.pathExists());
            }

        }

        WHEN("Adding two nodes and removing the last node from the path") {

            path.addNode(pathfinder::Node(1,2));
            path.addNode(pathfinder::Node(5,9));
            path.removeLastNode();

            THEN("THere should still be a path") {
                REQUIRE(path.pathExists());
            }
        }

        WHEN("Adding two nodes and removing two nodes") {

            path.addNode(pathfinder::Node(0,0));
            path.addNode(pathfinder::Node(0,1));
            path.removeLastNode();
            path.removeLastNode();

            THEN("There should not be a path") {
                REQUIRE_FALSE(path.pathExists());
            }
        }

        WHEN("Removing a node from empty path") {

            path.removeLastNode();

            THEN("Nothing should happen") {
                REQUIRE(true);
            }

        }
    }

}

SCENARIO("Nodes can be accessed from path") {

    GIVEN("A simple path") {

        pathfinder::Path path;
        path.addNode(pathfinder::Node(0,0));
        path.addNode(pathfinder::Node(1,0));
        path.addNode(pathfinder::Node(2,0));

        WHEN("Accessing first Node from the path") {

            pathfinder::Node node = path[0];

            THEN("The node should be in position (0,0)") {
                REQUIRE(node == pathfinder::Node(0,0));
            }

        }

        WHEN("Accessing second Node from the path") {

            pathfinder::Node node = path[1];

            THEN("The node should be in position (1,0)") {
                REQUIRE(node == pathfinder::Node(1,0));
            }

        }

        WHEN("Accessing last Node from the path") {

            pathfinder::Node node = path[2];

            THEN("The node should be in position (2,0)") {
                REQUIRE(node == pathfinder::Node(2,0));
            }

        }

        WHEN("Removing last node and adding a new node") {

            path.removeLastNode();
            path.addNode(pathfinder::Node(1,1));

            THEN("The third Node should be in position (1,1)") {

                pathfinder::Node node = path[2];
                REQUIRE(node == pathfinder::Node(1,1));
            }
        }
    }

}
