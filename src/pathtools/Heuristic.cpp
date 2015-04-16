#include "Heuristic.h"

namespace pathfinder {

    Heuristic::Heuristic() {
        this->nonDiagonalMovementCost = 1.0f;
        this->diagonalMovementCost = 1.4f;
    }

    float Heuristic::estimateDistance(Node start, Node end) const {
        int deltaX = calculateDifference(start.getX(), end.getX());
        int deltaY = calculateDifference(start.getY(), end.getY());

        float estimation = calculateDiagonalDistanceEstimation(deltaX, deltaY);
        return estimation;
    }

    int Heuristic::calculateDifference(int firstValue, int secondValue) const {
        return std::abs(firstValue - secondValue);
    }

    float Heuristic::calculateDiagonalDistanceEstimation(int firstDelta,
                                              int secondDelta) const {
        float nonDiagonalMovementCost =
                calculateNonDiagonalMovementCost(firstDelta, secondDelta);

        float diagonalMovementSave = calculateDiagonalMovementSave();
        float smallerDelta = std::min(firstDelta, secondDelta);

        return nonDiagonalMovementCost + diagonalMovementSave * smallerDelta;
    }

    float Heuristic::calculateNonDiagonalMovementCost(int firstDelta,
                                                      int secondDelta) const {
        return nonDiagonalMovementCost * (firstDelta + secondDelta);
    }

    float Heuristic::calculateDiagonalMovementSave() const {
        return diagonalMovementCost - 2 * nonDiagonalMovementCost;
    }

    void Heuristic::setDiagonalMovementCostFactor(
            float diagonalMovementCostFactor) {
        this->nonDiagonalMovementCost = 1.0f;
        this->diagonalMovementCost =
                nonDiagonalMovementCost * diagonalMovementCostFactor;
    }
}
