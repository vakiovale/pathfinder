#include "AStarPathFinder.h"

namespace pathfinder {

    AStarPathFinder::AStarPathFinder(Graph* graph) : PathFinder(graph) {
        // nothing more to be done
    }

    Path AStarPathFinder::findAndGetShortestPath(Node startNode, Node endNode) {
        pathfinder::Path path;
        // TODO: algorithm for shortest path
        // Returning dummy path
        path.addNode(Node(0,0));
        return path;
    }
}
