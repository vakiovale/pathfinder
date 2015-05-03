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
#include "Point.h"
#include "NeighbourCalculator.h"
#include "Node.h"

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
             * @brief Get all the accessible neighbours
             * of a specific ExtendedNode
             *
             * Number of neighbours will be between 0 and 8 depending
             * on the position of the ExtendedNode and the size of the graph.
             * Nodes that are not accessible will not be added to vector
             * of ExtendedNodes.
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
