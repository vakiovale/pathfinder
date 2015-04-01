/**
 * @brief AStarPathFinder class.
 *
 * Class for finding the shortest path with using A* algorithm.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef A_STAR_PATH_FINDER_H
#define A_STAR_PATH_FINDER_H

#include "../../graphs/Graph.h"
#include "../PathFinder.h"

namespace pathfinder {

    class AStarPathFinder : public PathFinder {
        public:
            AStarPathFinder(Graph* graph);
            ~AStarPathFinder();
    };

}

#endif
