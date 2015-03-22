#include "Node.h"

namespace pathfinder {

    Node::Node(int x, int y) : movementCostFactor(1.0f) {
        if(x < 0 || y < 0) {
            throw std::invalid_argument("Negative coordinates not allowed.");
        }
        this->x = x;
        this->y = y;
    }

    int Node::getX() const {
        return x;
    }

    int Node::getY() const {
        return y;
    }

    float Node::getMovementCostFactor() const {
        return movementCostFactor;
    }

    void Node::setMovementCostFactor(float newMovementCostFactor) {
        if(newMovementCostFactor < 0.0f) {
            throw std::invalid_argument("Negative cost factor is not allowed.");
        }
        movementCostFactor = newMovementCostFactor;
    }

    bool operator==(const Node& lhs, const Node& rhs) {
        return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
    }

    bool operator!=(const Node& lhs, const Node& rhs) {
        return !(lhs == rhs);
    }

}
