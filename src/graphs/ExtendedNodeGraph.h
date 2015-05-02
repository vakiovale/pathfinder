/**
 * @brief ExtendedNodeGraph
 *
 * ExtendedNodeGraph wraps a Graph inside and creates
 * ExtendedNodes from Graph's Nodes.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef EXTENDED_NODE_GRAPH_H
#define EXTENDED_NODE_GRAPH_H

#include <iostream>
#include <vector>
#include "Graph.h"
#include "ExtendedNode.h"

namespace pathfinder {

    class ExtendedNodeGraph {

        public:
            /**
             * @brief ExtendedNodeGraph
             *
             * Initialize ExtendedNodeGraph with existing graph
             *
             * @param graph to be binded to the ExtendedNodeGraph
             */
            ExtendedNodeGraph(Graph* graph);

            /**
             * @brief Get ExtendedNode from the graph
             * @param x position of the node
             * @param y position of the node
             * @return reference to ExtendedNode in position (x, y)
             */
            ExtendedNode& getExtendedNodeInPosition(int x, int y);

            /**
             * @brief Get all the neighbours of a specific ExtendedNode
             *
             * Number of neighbours will be between 0 and 9 depending
             * on the position of the ExtendedNode and the size of the graph
             *
             * @param extendedNode
             * @return vector of ExtendedNodes
             */
            std::vector<ExtendedNode*> getNeighboursOfExtendedNode(
                    const ExtendedNode& extendedNode);

        private:
            Graph* graph;
            std::vector<std::vector<ExtendedNode>> extendedNodes;
            void initializeExtendedGraph();

    };

}

#endif
