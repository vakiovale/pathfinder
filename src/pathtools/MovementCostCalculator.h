/**
 * @brief MovementCostCalculator
 *
 * MovementCostCalculator calculates cost between two neighbouring Nodes
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef MOVEMENT_COST_CALCULATOR_H
#define MOVEMENT_COST_CALCULATOR_H

#include "Node.h"

namespace pathfinder {

    class MovementCostCalculator {

        public:
            /**
             * @brief MovementCostCalculator
             *
             * Initializes MovementCostCalculator.
             * Diagonal movement cost factor will be considered 1.4 by default.
             */
            MovementCostCalculator();

            /**
             * @brief Calculate movement cost from node to neighbour node
             *
             * Using two Nodes that aren't neighbours will end in undefined
             * movement cost to be returned. This function will NOT check if
             * two Nodes are neighbours or not.
             *
             * @param node where movement is starting
             * @param neighbour node where movement is ending
             * @return movement cost between two nodes
             */
            float getCostBetweenNodes(const Node& node, const Node& neighbour);

        private:
            float diagonalMovementCostFactor;

            /**
             * @brief Check if two Nodes are diagonally aligned with each other.
             * @param firstNode
             * @param secondNode
             * @return true if Nodes are diagonally aligned
             */
            bool nodesAreDiagonalToEachOther(const Node& firstNode,
                                             const Node& secondNode);
    };

}

#endif
