#include "AStarPathFinder.h"

namespace pathfinder {

    AStarPathFinder::AStarPathFinder(Graph* graph) : PathFinder(graph),
        extendedGraph(graph) {
        // do nothing at the moment
    }

    Path AStarPathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        pathfinder::Path path;

        MovementCostCalculator movementCalculator;
        Heuristic heuristic;

        OpenList openList;

        int startX = startNode.getX();
        int startY = startNode.getY();

        int endX = endNode.getX();
        int endY = endNode.getY();

        ExtendedNode& end = extendedGraph.getExtendedNodeInPosition(endX, endY);
        ExtendedNode& start = extendedGraph.getExtendedNodeInPosition(startX, startY);

        start.setCurrentCost(0);
        start.setTotalCost(heuristic.estimateDistance(startNode, endNode));

        openList.add(start);

        while(!openList.isEmpty()) {
            ExtendedNode& current = openList.getBestNode();
            openList.removeBestNode();
            current.setNodeToClosedList();

            path.addNode(current.getNode());
            if(current == end)
                break;

            std::vector<ExtendedNode*> neighbours =
                    extendedGraph.getNeighboursOfExtendedNode(current);

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
}
