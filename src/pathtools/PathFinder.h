/**
 * @brief PathFinder class.
 *
 * Abstract class for finding shortest paths.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "Graph.h"
#include "Node.h"
#include "Path.h"

namespace pathfinder {

    class PathFinder {

        public:
            /**
             * @brief PathFinder
             * @param graph to be used in path finding
             */
            PathFinder(Graph* graph);

            /**
             * @brief Find a shortest path between two Nodes and returns the
             * path to the user.
             *
             * @param startNode
             * @param endNode
             * @return shortest Path between two nodes
             */
            virtual Path findAndGetShortestPath(Node startNode, Node endNode) = 0;

            /**
             * @brief Return number of nodes in the graph
             * @return number of nodes
             */
            int getNumberOfNodes() const;

        private:
            const Graph* const GRAPH; /*< graph to be used in path finding */

    };

}

#endif
