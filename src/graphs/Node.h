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

        public:
            /**
             * @brief Node
             *
             * Construct Node with x and y coordinates. Movement cost factor
             * will be set to 1.0f. Coordinates can't be negative numbers or
             * invalid_argument exception will be thrown.
             *
             * @param x coordinate
             * @param y coordinate
             * @throws invalid_argument
             */
            Node(int x, int y);

            /**
             * @brief Compare two Nodes
             *
             * Nodes will be equal if both positions are the same.
             *
             * @param lhs
             * @param rhs
             * @return true if both Nodes have the same position
             */
            friend bool operator==(const Node& lhs, const Node& rhs);

            /**
             * @brief Compare two Nodes
             *
             * Nodes will not be equal if both positions are different.
             *
             * @param lhs
             * @param rhs
             * @return true if both Nodes have different positions
             */
            friend bool operator!=(const Node& lhs, const Node& rhs);

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

            /**
             * @brief Get node's movement cost factor
             * @return movement cost factor
             */
            float getMovementCostFactor() const;

            /**
             * @brief Set movement cost factor to new value
             *
             * Movement cost factor cannot be lower than 0.0f. If negative
             * value is used as a parameter, the function will throw an
             * invalid_argument exception.
             *
             * @param newMovementCostFactor new value for movement cost factor
             * @throws invalid_argument
             */
            void setMovementCostFactor(float newMovementCostFactor);

        private:
            int x; /*< x coordinate */
            int y; /*< y coordinate */
            float movementCostFactor; /*< how expensive is visiting this node */
    };

}

#endif
