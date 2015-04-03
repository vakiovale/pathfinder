#include "PathFinder.h"

namespace pathfinder {

    PathFinder::PathFinder(Graph* graph) : GRAPH(graph) {
        // nothing more to be done
    }

    int PathFinder::getNumberOfNodes() const {
        return GRAPH->getNumberOfNodes();
    }

    Path PathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        pathfinder::Path shortestPath;
        return shortestPath;
    }
}
