/**
 * @brief Node class.
 *
 * Node is a basic unit to use in a graph.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef NODE_H
#define NODE_H

#include <stdexcept>

namespace pathfinder {

    class Node {

        private:
            int x;
            int y;

        public:
            /**
             * @brief Node
             *
             * Construct Node with x and y coordinates. Coordinates can't be
             * negative numbers or invalid_argument exception will be thrown.
             *
             * @param x coordinate
             * @param y coordinate
             */
            Node(int x, int y);

            /**
             * @brief Get x coordinate
             * @return x coordinate
             */
            int getX() const;

            /**
             * @brief Get y coordinate
             * @return y coordinate
             */
            int getY() const;

    };

}

#endif
