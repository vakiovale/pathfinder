#include "MovementCostCalculator.h"

namespace pathfinder {

    MovementCostCalculator::MovementCostCalculator() {
        diagonalMovementCostFactor = 1.4f;
    }

    float MovementCostCalculator::getCostBetweenNodes(const Node& node,
                                                      const Node& neighbour) {

        float movementCost = neighbour.getMovementCostFactor();
        if(nodesAreDiagonalToEachOther(node, neighbour)) {
            movementCost *= diagonalMovementCostFactor;
        }
        return movementCost;

    }

    bool MovementCostCalculator::nodesAreDiagonalToEachOther(
            const Node &firstNode, const Node &secondNode) {

        return firstNode.getX() != secondNode.getX() &&
                firstNode.getY() != secondNode.getY();
    }


}
