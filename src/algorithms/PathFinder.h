#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "../graphs/Graph.h"

namespace pathfinder {

    class PathFinder {

        private:
            const Graph* const GRAPH;
        public:
            PathFinder(Graph* graph);
    };

}

#endif
