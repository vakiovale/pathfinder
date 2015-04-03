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
            unsigned int numberOfNodesInPath;

        public:
            Path();

            /**
             * @brief Checks if path exists
             * @return true if there is a path
             */
            bool pathExists() const;

            /**
             * @brief Get path's length
             *
             * Length of the path is the same as number of nodes in the path
             *
             * @return length of path
             */
            int getPathLength() const;

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

            /**
             * @brief Removes last existing node from the path
             */
            void removeLastNode();

            /**
             * @brief Get node from path
             *
             * @param index 0 is the first node in the path and
             * getPathLength()-1 is the end point in the path
             *
             * @return Node in a specific position in path
             */
            const Node& operator[](std::size_t index) const;

    };

}

#endif
