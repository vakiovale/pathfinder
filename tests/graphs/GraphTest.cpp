#include "GraphTest.h"

SCENARIO("Graph can be initialized and contain number of nodes", "[graph]") {

    GIVEN("An empty graph with nothing in it") {

        pathfinder::Graph graph;

        WHEN("Trying to get nodes from the graph") {

            std::vector<std::vector<pathfinder::Node>> nodes =
                    graph.getAllNodes();

            THEN("The vector with nodes should be empty") {
                REQUIRE(nodes.empty());
            }
            AND_THEN("There should be zero nodes in the graph") {
                REQUIRE(graph.getNumberOfNodes() == 0);
            }
        }

        WHEN("Initializing the graph to a 2D grid map with side length of 0") {

            graph.create2DGridMap(0);

            THEN("There should be zero nodes in the graph") {
                REQUIRE(graph.getNumberOfNodes() == 0);
            }
        }

        WHEN("Initializing the graph with a negative side length and getting"
             "nodes from the graph") {

            graph.create2DGridMap(-3);
            std::vector<std::vector<pathfinder::Node>> nodes =
                    graph.getAllNodes();

            THEN("There should be zero nodes in the graph") {
                REQUIRE(graph.getNumberOfNodes() == 0);
            }
            AND_THEN("The vector of nodes should be empty") {
                REQUIRE(nodes.empty());
            }
        }

        WHEN("Initializing the graph to a 2D "
             "grid map with 10x10 nodes") {

            graph.create2DGridMap(10);
            std::vector<std::vector<pathfinder::Node>> nodes =
                    graph.getAllNodes();

            THEN("The vector with nodes should have a size of 10") {
                REQUIRE(nodes.size() == 10);
            }
            AND_THEN("There should be 100 nodes in the graph") {
                REQUIRE(graph.getNumberOfNodes() == 100);
            }
        }

        WHEN("Initializing the graph to a 2D "
             "grid map with 6x6 nodes") {

            graph.create2DGridMap(6);
            std::vector<std::vector<pathfinder::Node>> nodes =
                    graph.getAllNodes();

            THEN("The vector with nodes should have a size of 6") {
                REQUIRE(nodes.size() == 6);
            }
            AND_THEN("There should be 36 nodes in the graph") {
                REQUIRE(graph.getNumberOfNodes() == 36);
            }
        }
    }
}

SCENARIO("Nodes can be retrieved from graphs", "[graph][node]") {

    GIVEN("A graph initialized to 8x8 2D grid map") {

        pathfinder::Graph graph;
        graph.create2DGridMap(8);

        WHEN("Initializing graph again to 3x3 2D grid map") {

            graph.create2DGridMap(3);
            std::vector<std::vector<pathfinder::Node>> nodes =
                    graph.getAllNodes();

            THEN("The vector with nodes should have a size of 3") {
                REQUIRE(nodes.size() == 3);
            }
            AND_THEN("There should be 9 nodes in the graph") {
                REQUIRE(graph.getNumberOfNodes() == 9);
            }
        }

        WHEN("Getting a single node from position (2, 3)") {

            pathfinder::Node* node = graph.getNodeFromPosition(2, 3);

            THEN("The requested node should be the same as other"
                 "node in a position (2, 3)") {
                pathfinder::Node otherNode(2, 3);
                REQUIRE(*node == otherNode);
            }
            AND_THEN("The requested node should have a position (2, 3)") {
                REQUIRE(node->getX() == 2);
                REQUIRE(node->getY() == 3);
            }

        }

        WHEN("Getting a single node from position (0, 0)") {

            const pathfinder::Node* node = graph.getNodeFromPosition(0, 0);

            THEN("The requested node should be the same as other"
                 "node in a position (0, 0)") {
                pathfinder::Node otherNode(0, 0);
                REQUIRE(*node == otherNode);
            }
            AND_THEN("The requested node should have a position (0, 0)") {
                REQUIRE(node->getX() == 0);
                REQUIRE(node->getY() == 0);
            }
        }

        WHEN("Getting a single node from position (7, 7)") {

            const pathfinder::Node* node = graph.getNodeFromPosition(7, 7);

            THEN("The requested node should have a position (7, 7)") {
                REQUIRE(node->getX() == 7);
                REQUIRE(node->getY() == 7);
            }

        }

        WHEN("Checking if there is a node in position (4, 5)") {

            bool nodeExists = graph.nodeExistsInPosition(4, 5);

            THEN("There should be a node in that position") {
                REQUIRE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (0, 0)") {

            bool nodeExists = graph.nodeExistsInPosition(0, 0);

            THEN("There should be a node in that position") {
                REQUIRE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (1, 7)") {

            bool nodeExists = graph.nodeExistsInPosition(1, 7);

            THEN("There should be a node in that position") {
                REQUIRE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (7, 7)") {

            bool nodeExists = graph.nodeExistsInPosition(7, 7);

            THEN("There should be a node in that position") {
                REQUIRE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (8, 8)") {

            bool nodeExists = graph.nodeExistsInPosition(8, 8);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (9, 2)") {

            bool nodeExists = graph.nodeExistsInPosition(9, 2);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (2, 9)") {

            bool nodeExists = graph.nodeExistsInPosition(2, 9);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (-1, 0)") {

            bool nodeExists = graph.nodeExistsInPosition(-1, 0);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (0, -1)") {

            bool nodeExists = graph.nodeExistsInPosition(0, -1);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (-1, 8)") {

            bool nodeExists = graph.nodeExistsInPosition(-1, 8);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }

        WHEN("Checking if there is a node in position (-9, -9)") {

            bool nodeExists = graph.nodeExistsInPosition(-9, -9);

            THEN("There should not be a node in that position") {
                REQUIRE_FALSE(nodeExists);
            }
        }
    }
}
