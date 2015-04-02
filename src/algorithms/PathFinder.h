#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "../graphs/Graph.h"

namespace pathfinder {

    class PathFinder {

        private:
            const Graph* const GRAPH; /*< graph to be used in path finding */

        public:
            /**
             * @brief PathFinder
             * @param graph to be used in path finding
             */
            PathFinder(Graph* graph);

            /**
             * @brief Return number of nodes in the graph
             * @return number of nodes
             */
            int getNumberOfNodes() const;

    };

}

#endif
