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

        ExtendedNode* node = &(getExtendedNodeInPosition(extendedNode.getNode().getX(),
                                                       extendedNode.getNode().getY()-1));
        neighbours.push_back(node);
        return neighbours;
    }


}
