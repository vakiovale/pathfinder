#include "ExtendedNodeGraphTest.h"

SCENARIO("ExtendedNodeGraphs initializes itself with a Graph",
         "[extendednodegraph][graph][extendednode]") {

    GIVEN("A simple 3x3 graph") {

        pathfinder::Graph graph;
        graph.create2DGridMap(3);

        WHEN("Initializing ExtendedNodeGraph with a simple graph") {

            pathfinder::ExtendedNodeGraph extGraph(&graph);

            THEN("Initializing works") {
                REQUIRE(true);
            }
        }
    }

}

SCENARIO("ExtendedNodeGraph has an ExtendedNode for every Node in the graph",
         "[extendednodegraph][graph][extendednode][node]") {

    GIVEN("2x2 ExtendedNodeGraph") {

        pathfinder::Graph graph;
        graph.create2DGridMap(2);
        pathfinder::ExtendedNodeGraph extGraph(&graph);

        WHEN("Getting ExtendedNode (0,0) from extended graph") {

            pathfinder::ExtendedNode& extendedNode =
                    extGraph.getExtendedNodeInPosition(0, 0);

            THEN("ExtendedNode holds a Node with position (0, 0)") {

                const pathfinder::Node& node = extendedNode.getNode();

                REQUIRE(node.getX() == 0);
                REQUIRE(node.getY() == 0);

            }

        }

        WHEN("Getting ExtendedNode (1,0) from extended graph") {

            pathfinder::ExtendedNode& extendedNode =
                    extGraph.getExtendedNodeInPosition(1, 0);

            THEN("ExtendedNode holds a Node with position (1, 0)") {

                const pathfinder::Node& node = extendedNode.getNode();

                REQUIRE(node.getX() == 1);
                REQUIRE(node.getY() == 0);

            }

        }

        WHEN("Getting ExtendedNode (1,1) from extended graph") {

            pathfinder::ExtendedNode& extendedNode =
                    extGraph.getExtendedNodeInPosition(1, 1);

            THEN("ExtendedNode holds a Node with position (1, 1)") {

                const pathfinder::Node& node = extendedNode.getNode();

                REQUIRE(node.getX() == 1);
                REQUIRE(node.getY() == 1);

            }

        }

        WHEN("Getting ExtendedNode (0,1) from extended graph") {

            pathfinder::ExtendedNode& extendedNode =
                    extGraph.getExtendedNodeInPosition(0, 1);

            THEN("ExtendedNode holds a Node with position (0, 1)") {

                const pathfinder::Node& node = extendedNode.getNode();

                REQUIRE(node.getX() == 0);
                REQUIRE(node.getY() == 1);

            }

        }
    }
}

SCENARIO("Modified node in the graph will have an effect to the Node inside"
         "ExtendedNode in the extended graph",
         "[extendednodegraph][extendednode][graph][node]") {

    GIVEN("2x2 ExtendedNodeGraph") {

        pathfinder::Graph graph;
        graph.create2DGridMap(2);
        pathfinder::ExtendedNodeGraph extGraph(&graph);

        WHEN("Changing Node's (0,1) movement cost factor inside graph to 2.0f") {

            pathfinder::Node* node = graph.getNodeFromPosition(0, 1);
            node->setMovementCostFactor(2.0f);

            THEN("Movement cost factor is changed inside extended graph") {

                const pathfinder::Node& innerNode =
                        extGraph.getExtendedNodeInPosition(0, 1).getNode();

                Approx approximation((double)
                                     innerNode.getMovementCostFactor());

                REQUIRE(approximation == 2.0f);

            }
        }
    }

}

SCENARIO("It's possible to get all the neighbour ExtendedNodes from a "
         "specific ExtendedNode", "[extendednodegraph][extendednode]") {

    GIVEN("5x5 ExtendedNodeGraph") {

        pathfinder::Graph graph;
        graph.create2DGridMap(5);
        pathfinder::ExtendedNodeGraph extGraph(&graph);

        WHEN("Getting neighbours of ExtendedNode (1, 1)") {

            pathfinder::ExtendedNode& extNode =
                    extGraph.getExtendedNodeInPosition(1, 1);

            std::vector<pathfinder::ExtendedNode*> neighbours =
                    extGraph.getNeighboursOfExtendedNode(extNode);

            THEN("Neighbours of ExtendedNode (1, 1) are "
                 "(1,0), (2,0), (2,1), (2,2), (1,2), (0,2), (0,1), (0,0) "
                 "in that order") {

                pathfinder::ExtendedNode* extendedNode = neighbours.back();
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

            }

        }

    }

}
