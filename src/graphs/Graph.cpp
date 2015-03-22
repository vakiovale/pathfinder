#include "Graph.h"

namespace pathfinder {

    Graph::Graph() {
        // do nothing for now
    }

    void Graph::create2DGridMap(int lengthOfSide) {
        for(int i = 0; i < lengthOfSide; i++) {
            std::vector<Node> rowOfVectors;
            for(int j = 0; j < lengthOfSide; j++) {
                rowOfVectors.push_back(Node(j, i));
            }
            nodes.push_back(rowOfVectors);
        }
    }

    std::vector<std::vector<Node>> Graph::getAllNodes() const {
        return nodes;
    }

    const Node* Graph::getNodeFromPosition(int x, int y) {

        return &(nodes[y][x]);
    }

    int Graph::getNumberOfNodes() const {
        int numberOfNodes = 0;
        for(std::vector<Node> innerVector : nodes) {
            for(Node node : innerVector) {
                ++numberOfNodes;
            }
        }
        return numberOfNodes;
    }

    bool Graph::nodeExistsInPosition(int x, int y) const {
        if(nodes.size() <= y) {
            if((nodes[y]).size() <= x) {
                return true;
            }
        }
        return false;
    }


}
