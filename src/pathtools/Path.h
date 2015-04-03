/**
 * @brief Path class
 *
 * Stores a path from Nodes
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef PATH_H
#define PATH_H

#include <deque>
#include "Node.h"

namespace pathfinder {

    class Path {

        private:
            std::deque<Node> path;

        public:
            Path();

            /**
             * @brief Checks if path exists
             * @return true if there is a path
             */
            bool pathExists() const;

            /**
             * @brief Add next node to the path
             *
             * Order matters when using this function. Calling this function
             * for the first time adds a starting point of the path. Every time
             * calling this function will add a next step in the path.
             *
             * @param nodeToBeAddedToPath
             */
            void addNode(Node nodeToBeAddedToPath);

    };

}

#endif
