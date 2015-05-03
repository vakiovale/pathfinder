#include "ExtendedNodeGraph.h"

namespace pathfinder {

    ExtendedNodeGraph::ExtendedNodeGraph(Graph* graph) {
        this->graph = graph;
        initializeExtendedGraph();
    }

    void ExtendedNodeGraph::initializeExtendedGraph() {
        std::vector<std::vector<pathfinder::Node>> nodes =
                graph->getAllNodes();

        int numberOfRows = nodes.size();
        for(int i = 0; i < numberOfRows; i++) {

            std::vector<ExtendedNode> rowOfVectors;
            int numberOfColumns = (nodes[i]).size();

            for(int j = 0; j < numberOfColumns; j++) {
                rowOfVectors.push_back(
                            ExtendedNode(
                                graph->getNodeFromPosition(j,i)));
            }
            extendedNodes.push_back(rowOfVectors);
        }
    }

    ExtendedNode& ExtendedNodeGraph::getExtendedNodeInPosition(int x, int y) {
        return extendedNodes[y][x];
    }

    std::vector<ExtendedNode*> ExtendedNodeGraph::getNeighboursOfExtendedNode(
            const ExtendedNode& extendedNode) {

        std::vector<ExtendedNode*> neighbours;
        std::vector<Point> neighbourPoints =
                getNeighbourPoints(extendedNode.getNode());

        for(Point neighbourPoint : neighbourPoints) {
            if(!pointExistsInGraph(neighbourPoint)) {
                continue;
            }

            ExtendedNode& neighbour = getExtendedNodeFromPoint(neighbourPoint);
            if(extendedNodeIsAccessible(neighbour)) {
                neighbours.push_back(&neighbour);
            }
        }

        return neighbours;
    }

    std::vector<Point> ExtendedNodeGraph::getNeighbourPoints(const Node& node) {
        int x = node.getX();
        int y = node.getY();
        NeighbourCalculator calculator(x, y);
        return calculator.getNeighbourPoints();
    }

    bool ExtendedNodeGraph::pointExistsInGraph(const Point& point) const {
        int x = point.getX();
        int y = point.getY();
        return graph->nodeExistsInPosition(x, y);
    }

    ExtendedNode& ExtendedNodeGraph::getExtendedNodeFromPoint(
            const Point& point) {

        int x = point.getX();
        int y = point.getY();
        return getExtendedNodeInPosition(x,y);
    }

    bool ExtendedNodeGraph::extendedNodeIsAccessible(
            const ExtendedNode& extendedNode) const {
        const Node& node = extendedNode.getNode();
        return node.isAccessible();
    }

}
