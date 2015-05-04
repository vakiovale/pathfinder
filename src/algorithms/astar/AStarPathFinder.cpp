#include "AStarPathFinder.h"

namespace pathfinder {

    AStarPathFinder::AStarPathFinder(Graph* graph) : PathFinder(graph),
        extendedGraph(graph) {
        // do nothing at the moment
    }

    Path AStarPathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        pathfinder::Path path;

        initializeStartAndEndNodes(startNode, endNode);

        OpenList openList;

        openList.add(*start);

        while(!openList.isEmpty()) {
            ExtendedNode& current = openList.getBestNode();
            openList.removeBestNode();
            current.setNodeToClosedList();

            path.addNode(current.getNode());
            if(current == *end)
                break;

            std::vector<ExtendedNode*> neighbours =
                    extendedGraph.getAccessibleNeighboursOfExtendedNode(current);

            for(ExtendedNode* neighbour : neighbours) {
                const Node& first = current.getNode();
                const Node& second = neighbour->getNode();
                float cost = current.getCurrentCost() +
                        movementCalculator.getCostBetweenNodes(first, second);

                if(openList.contains(*neighbour) && cost < neighbour->getCurrentCost()) {
                   neighbour->setCurrentCost(cost);
                   neighbour->setTotalCost(cost+heuristic.estimateDistance(neighbour->getNode(), endNode));
                   openList.fixOpenList();
                }
                else if(!neighbour->isInClosedList()) {
                    neighbour->setCurrentCost(cost);
                    neighbour->setTotalCost(cost+heuristic.estimateDistance(neighbour->getNode(), endNode));
                    openList.add(*neighbour);
                }
            }
        }

        return path;
    }

    void AStarPathFinder::initializeStartAndEndNodes(const Node& start,
                                                     const Node& end) {
        initializeEndNode(end);
        initializeStartNode(start);
    }

    void AStarPathFinder::initializeEndNode(const Node &endNode) {
        int endX = endNode.getX();
        int endY = endNode.getY();
        end = &extendedGraph.getExtendedNodeInPosition(endX, endY);
    }

    void AStarPathFinder::initializeStartNode(const Node &startNode) {
        int startX = startNode.getX();
        int startY = startNode.getY();
        start = &extendedGraph.getExtendedNodeInPosition(startX, startY);
        start->setCurrentCost(0);
        start->setTotalCost(heuristic.estimateDistance(startNode,
                                                       end->getNode()));
    }


}
