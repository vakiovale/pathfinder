/**
 * @brief AStarPathFinder class.
 *
 * Class for finding the shortest path with using A* algorithm.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef A_STAR_PATH_FINDER_H
#define A_STAR_PATH_FINDER_H

#include <vector>
#include "Graph.h"
#include "Path.h"
#include "PathFinder.h"
#include "ExtendedNode.h"
#include "ExtendedNodeGraph.h"

namespace pathfinder {

    class AStarPathFinder : public PathFinder {

        public:
            /**
             * @brief AStarPathFinder
             * @param graph to be used in path finding
             */
            AStarPathFinder(Graph* graph);

            /**
             * @brief Finds a shortest path
             *
             * Finds a shortest path between two nodes and returns the path.
             *
             * @param startNode
             * @param endNode
             * @return shortest path from start to end
             */
            Path findAndGetShortestPath(Node startNode, Node endNode);

       private:
            ExtendedNodeGraph extendedGraph;

    };

}

#endif
