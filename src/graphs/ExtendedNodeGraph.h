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
#include "CompassPosition.h"

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
             * of pointers to ExtendedNodes.
             *
             * @param extendedNode
             * @return vector of pointers to ExtendedNodes
             */
            std::vector<ExtendedNode*> getAccessibleNeighboursOfExtendedNode(
                    const ExtendedNode& extendedNode);

        private:
            Graph* graph;

            std::vector<std::vector<ExtendedNode>> extendedNodes;

            /**
             * @brief Initializes ExtendedGraph by binding all the Nodes
             * to ExtendedNodes
             *
             */
            void initializeExtendedGraph();

            /**
             * @brief Get neighbouring Points from single Node
             * @param node to visit neighbours from
             * @return vector of neighbouring Points
             */
            std::vector<Point> getNeighbourPoints(const Node& node);

            /**
             * @brief Check if Point exists in graph
             * @param point to check
             * @return true if Point exists in graph area
             */
            bool pointExistsInGraph(const Point& point) const;

            /**
             * @brief Get reference to ExtendedNode in extended graph
             * @param point where ExtendedNode is retrieved from
             * @return reference to ExtendedNode
             */
            ExtendedNode& getExtendedNodeFromPoint(const Point& point);

            /**
             * @brief Check if ExtendedNode is accessible
             *
             * @param extendedNode to be checked
             * @param position indicates the direction to move to get into
             * this neighbour
             * @param indicates if non-diagonal nodes are accessible
             * @return
             */
            bool extendedNodeIsAccessible(const ExtendedNode& extendedNode,
                                          CompassPosition position,
                                          std::vector<bool>& accessibleNonDiagonalNodes);

    };

}

#endif
