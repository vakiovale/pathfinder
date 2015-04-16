#include "AStarPathFinder.h"

namespace pathfinder {

    AStarPathFinder::AStarPathFinder(Graph* graph) : PathFinder(graph) {
        initializeTotalCosts();
    }

    void AStarPathFinder::initializeTotalCosts() {
        std::vector<std::vector<pathfinder::Node>> nodes = this->GRAPH->getAllNodes();

        for(std::vector<pathfinder::Node> innerVector : nodes) {
            std::vector<float> rowOfFloats;
            for(Node& node : innerVector) {
                rowOfFloats.push_back(0.0f);
            }
            totalCosts.push_back(rowOfFloats);
        }
    }

    Path AStarPathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        setTotalCostsToZero();

        pathfinder::Path path;

        // TODO: algorithm for shortest path
        // Returning dummy path
        path.addNode(startNode);
        path.addNode(endNode);

        return path;
    }

    void AStarPathFinder::setTotalCostsToZero() {
        for(std::vector<float> innerVector : totalCosts) {
            for(float& totalCost : innerVector) {
                totalCost = 0.0f;
            }
        }
    }
}
