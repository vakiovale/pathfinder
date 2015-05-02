#include "AStarPathFinder.h"

namespace pathfinder {

    AStarPathFinder::AStarPathFinder(Graph* graph) : PathFinder(graph) {
        initializeExtendedNodes();
    }

    void AStarPathFinder::initializeExtendedNodes() {
        std::vector<std::vector<pathfinder::Node>> nodes =
                this->GRAPH->getAllNodes();

        for(std::vector<pathfinder::Node> innerVector : nodes) {

            std::vector<ExtendedNode> rowOfExtendedNodes;

            for(Node& node : innerVector) {
                ExtendedNode extendedNode(&node);
                rowOfExtendedNodes.push_back(extendedNode);
            }
            extendedNodes.push_back(rowOfExtendedNodes);
        }
    }

    Path AStarPathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        setExtendedNodesOpenListFlagsToFalse();

        pathfinder::Path path;

        // TODO: algorithm for shortest path
        // Returning dummy path
        path.addNode(startNode);
        path.addNode(endNode);

        return path;
    }

    void AStarPathFinder::setExtendedNodesOpenListFlagsToFalse() {
        for(std::vector<ExtendedNode> innerVector : extendedNodes) {
            for(ExtendedNode& extendedNode : innerVector) {
                extendedNode.setNodeRemovedFromOpenList();
            }
        }
    }
}
