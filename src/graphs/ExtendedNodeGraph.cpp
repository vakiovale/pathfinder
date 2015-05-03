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


        NeighbourCalculator calculator(extendedNode.getNode().getX(),
                                       extendedNode.getNode().getY());
        std::vector<ExtendedNode*> neighbours;
        std::vector<Point> neighbourPoints = calculator.getNeighbourPoints();

        for(Point neighbourPoint : neighbourPoints) {
            if(!(graph->nodeExistsInPosition(neighbourPoint.getX(), neighbourPoint.getY()))) {
                continue;
            }
            int x = neighbourPoint.getX();
            int y = neighbourPoint.getY();

            ExtendedNode& neighbour = getExtendedNodeInPosition(x,y);

            const Node& node = neighbour.getNode();
            if(node.isAccessible()) {
                neighbours.push_back(&neighbour);
            }
        }

        return neighbours;
    }


}
