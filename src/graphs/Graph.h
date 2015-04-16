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

        public:
            Graph();

            /**
             * @brief Graph will initialize 2D Grid Map
             *
             * Graph will get a 2D grid map with a specific side length.
             *
             * @param lengthOfSide
             */
            void create2DGridMap(int lengthOfSide);

            /**
             * @brief Returns all the nodes from the graph
             *
             * @return vector of nodes
             */
            std::vector<std::vector<Node>> getAllNodes() const;

            /**
             * @brief Return a pointer to a node from a specific location
             *
             * @param x position
             * @param y position
             * @return pointer to Node
             */
            Node* getNodeFromPosition(int x, int y);

            /**
             * @brief Check if Node exists in a specific position
             *
             * @param x position
             * @param y position
             * @return true if Node exists in a graph
             */
            bool nodeExistsInPosition(int x, int y) const;

            /**
             * @brief Return number of nodes in the graph
             *
             * @return number of nodes
             */
            int getNumberOfNodes() const;

        private:
            std::vector<std::vector<Node>> nodes;

    };

}

#endif
