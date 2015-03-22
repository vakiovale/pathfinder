/**
 * @brief Graph which contains a set of nodes.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Node.h"

namespace pathfinder {

    class Graph {
        private:
            std::vector<std::vector<Node>> nodes;
        public:
            Graph();
            void create2DGridMap(int lengthOfSide);
            std::vector<std::vector<Node>> getAllNodes() const;
            const Node* getNodeFromPosition(int x, int y);
            bool nodeExistsInPosition(int x, int y) const;
            int getNumberOfNodes() const;
            void printNodes() const;
    };

}

#endif
