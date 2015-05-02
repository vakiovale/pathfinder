#include "AStarPathFinder.h"

namespace pathfinder {

    AStarPathFinder::AStarPathFinder(Graph* graph) : PathFinder(graph),
        extendedGraph(graph) {
        // do nothing at the moment
    }

    Path AStarPathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        pathfinder::Path path;

        // TODO: algorithm for shortest path
        // Returning dummy path
        path.addNode(startNode);
        path.addNode(endNode);

        return path;
    }
}
