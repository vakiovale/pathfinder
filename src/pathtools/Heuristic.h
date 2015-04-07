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

        private:
            float nonDiagonalMovementCost;
            float diagonalMovementCost;

            int calculateDifference(int firstValue, int secondValue) const;

            float calculateNonDiagonalMovementCost(int firstDelta,
                                                   int secondDelta) const;
            float calculateDiagonalMovementSave() const;

            float calculateDiagonalDistanceEstimation(int firstDelta,
                                                      int secondDelta) const;

        public:
            Heuristic();
            float estimateDistance(Node start, Node end) const;
            void setDiagonalMovementCostFactor(float diagonalMovementCostFactor);
    };
}

#endif
