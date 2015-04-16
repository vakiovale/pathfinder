/**
 * @brief Heuristic class.
 *
 * Class for estimating distances between nodes
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <cstdlib>
#include "Node.h"

namespace pathfinder {

    class Heuristic {

        public:
            /**
             * @brief Heuristic
             *
             * Initializes Heuristic to be used in pathfinding.
             * Also initializes diagonal movement cost factor to 1.4f.
             *
             */
            Heuristic();

            /**
             * @brief Estimate distance between two nodes
             *
             * Estimates distance between two nodes calculating the
             * diagonal distance. Diagonal distance will be zero if the
             * starting node and end node is the same and greater than zero
             * if they are different.
             *
             * @param start node
             * @param end node
             * @return diagonal distance between two nodes
             */
            float estimateDistance(Node start, Node end) const;

            /**
             * @brief Set diagonal movement cost factor
             *
             * Diagonal movement cost factor indicates how much does it cost
             * when moving diagonally compared to moving non-diagonally.
             * If diagonal movement cost factor is set to 1.0f then it's as
             * expensive to move diagonally than non-diagonally.
             *
             * @param diagonalMovementCostFactor
             */
            void setDiagonalMovementCostFactor(float diagonalMovementCostFactor);

        private:
            float nonDiagonalMovementCost;
            float diagonalMovementCost;

            int calculateDifference(int firstValue, int secondValue) const;

            float calculateNonDiagonalMovementCost(int firstDelta,
                                                   int secondDelta) const;
            float calculateDiagonalMovementSave() const;

            float calculateDiagonalDistanceEstimation(int firstDelta,
                                                      int secondDelta) const;
    };
}

#endif
