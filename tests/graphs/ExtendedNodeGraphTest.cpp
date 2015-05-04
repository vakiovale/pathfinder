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

    GIVEN("An empty graph") {

        pathfinder::Graph graph;

        WHEN("Initializing ExtendedNodeGraph with an empty graph") {

            pathfinder::ExtendedNodeGraph extGraph(&graph);

            THEN("Initializing works "
                 "(although there's not much use for an empty graph)") {
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
                    extGraph.getAccessibleNeighboursOfExtendedNode(extNode);

            THEN("Neighbours of ExtendedNode (1, 1) are "
                 "(1,0), (2,1), (1,2), (0,1), (2,0), (2,2), (0,2), (0,0) "
                 "in that order") {

                REQUIRE(neighbours.size() == 8);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[5];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[6];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[7];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 0);

            }

        }

        WHEN("Getting neighbours of ExtendedNode (0, 1)") {

            pathfinder::ExtendedNode& extNode =
                    extGraph.getExtendedNodeInPosition(0, 1);

            std::vector<pathfinder::ExtendedNode*> neighbours =
                    extGraph.getAccessibleNeighboursOfExtendedNode(extNode);

            THEN("Neighbours of ExtendedNode (0, 1) are "
                 "(0,0), (1,1), (0,2), (1,0), (1,2)"
                 "in that order") {

                REQUIRE(neighbours.size() == 5);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 2);

            }
        }
    }
}

SCENARIO("Unaccessible nodes restrict movement", "[extendednodegraph]"
                                                 "[extendednode][node]") {

    GIVEN("3x3 ExtendedNodeGraph") {

        pathfinder::Graph graph;
        graph.create2DGridMap(3);
        pathfinder::ExtendedNodeGraph extGraph(&graph);

        pathfinder::ExtendedNode& middleNode =
                extGraph.getExtendedNodeInPosition(1, 1);

        WHEN("Node (0,0) is unaccessible") {

            graph.getNodeFromPosition(0,0)->setAccessible(false);

            THEN("Neighbours of ExtendedNode (1, 1) are "
                 "(1,0), (2,1), (1,2), (0,1), (2,0), (2,2), (0,2) "
                 "in that order") {

                std::vector<pathfinder::ExtendedNode*> neighbours =
                        extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                REQUIRE(neighbours.size() == 7);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[5];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[6];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 2);

            }
        }

        WHEN("Node (1,0) is unaccessible") {

            graph.getNodeFromPosition(1,0)->setAccessible(false);

            THEN("Neighbours of (1,1) are "
                 "(2,1), (1,2), (0,1), (2,2) and (0,2)"
                 "in that order") {

                std::vector<pathfinder::ExtendedNode*> neighbours =
                        extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                REQUIRE(neighbours.size() == 5);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 2);

            }
        }

        WHEN("Node (1,2) is unaccessible") {

            graph.getNodeFromPosition(1,2)->setAccessible(false);

            THEN("Neighbours of (1,1) are "
                 "(1,0), (2,1), (0,1), (2,0) and (0,0)"
                 "in that order") {

                std::vector<pathfinder::ExtendedNode*> neighbours =
                        extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                REQUIRE(neighbours.size() == 5);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 0);

            }
        }

        WHEN("Node (0,1) is unaccessible") {

            graph.getNodeFromPosition(0,1)->setAccessible(false);

            THEN("Neighbours of (1,1) are "
                 "(1,0), (2,1), (1,2), (2,0) and (2,2)"
                 "in that order") {

                std::vector<pathfinder::ExtendedNode*> neighbours =
                        extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                REQUIRE(neighbours.size() == 5);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 2);
                REQUIRE(extendedNode->getNode().getY() == 2);

            }

            AND_WHEN("Node (2,1) is unaccessible") {

                graph.getNodeFromPosition(2,1)->setAccessible(false);

                THEN("Neighbours of (1,1) are (1,0) and (1,2)"
                     "in that order") {

                    std::vector<pathfinder::ExtendedNode*> neighbours =
                            extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                    REQUIRE(neighbours.size() == 2);

                    pathfinder::ExtendedNode* extendedNode = neighbours[0];
                    REQUIRE(extendedNode->getNode().getX() == 1);
                    REQUIRE(extendedNode->getNode().getY() == 0);

                    extendedNode = neighbours[1];
                    REQUIRE(extendedNode->getNode().getX() == 1);
                    REQUIRE(extendedNode->getNode().getY() == 2);
                }

            }

            AND_WHEN("Node (2,2) is unaccessible") {

                graph.getNodeFromPosition(2,2)->setAccessible(false);

                THEN("Neighbours of (1,1) are (1,0), (2,1), (1,2) and (2,0)"
                     "in that order") {

                    std::vector<pathfinder::ExtendedNode*> neighbours =
                            extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                    REQUIRE(neighbours.size() == 4);

                    pathfinder::ExtendedNode* extendedNode = neighbours[0];
                    REQUIRE(extendedNode->getNode().getX() == 1);
                    REQUIRE(extendedNode->getNode().getY() == 0);

                    extendedNode = neighbours[1];
                    REQUIRE(extendedNode->getNode().getX() == 2);
                    REQUIRE(extendedNode->getNode().getY() == 1);

                    extendedNode = neighbours[2];
                    REQUIRE(extendedNode->getNode().getX() == 1);
                    REQUIRE(extendedNode->getNode().getY() == 2);

                    extendedNode = neighbours[3];
                    REQUIRE(extendedNode->getNode().getX() == 2);
                    REQUIRE(extendedNode->getNode().getY() == 0);
                }

            }
        }

        WHEN("Node (2,1) is unaccessible") {

            graph.getNodeFromPosition(2,1)->setAccessible(false);

            THEN("Neighbours of (1,1) are "
                 "(1,0), (1,2), (0,1), (0,2) and (0,0)"
                 "in that order") {

                std::vector<pathfinder::ExtendedNode*> neighbours =
                        extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                REQUIRE(neighbours.size() == 5);

                pathfinder::ExtendedNode* extendedNode = neighbours[0];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 0);

                extendedNode = neighbours[1];
                REQUIRE(extendedNode->getNode().getX() == 1);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[2];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 1);

                extendedNode = neighbours[3];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 2);

                extendedNode = neighbours[4];
                REQUIRE(extendedNode->getNode().getX() == 0);
                REQUIRE(extendedNode->getNode().getY() == 0);

            }

            AND_WHEN("Node (0,2) is unaccessible") {

                graph.getNodeFromPosition(0,2)->setAccessible(false);

                THEN("Neighbours of (1,1) are "
                     "(1,0), (1,2), (0,1) and (0,0)"
                     "in that order") {

                    std::vector<pathfinder::ExtendedNode*> neighbours =
                            extGraph.getAccessibleNeighboursOfExtendedNode(middleNode);

                    REQUIRE(neighbours.size() == 4);

                    pathfinder::ExtendedNode* extendedNode = neighbours[0];
                    REQUIRE(extendedNode->getNode().getX() == 1);
                    REQUIRE(extendedNode->getNode().getY() == 0);

                    extendedNode = neighbours[1];
                    REQUIRE(extendedNode->getNode().getX() == 1);
                    REQUIRE(extendedNode->getNode().getY() == 2);

                    extendedNode = neighbours[2];
                    REQUIRE(extendedNode->getNode().getX() == 0);
                    REQUIRE(extendedNode->getNode().getY() == 1);

                    extendedNode = neighbours[3];
                    REQUIRE(extendedNode->getNode().getX() == 0);
                    REQUIRE(extendedNode->getNode().getY() == 0);

                }

            }
        }
    }
}
