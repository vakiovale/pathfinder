#include "Node.h"

namespace pathfinder {

    Node::Node(int x, int y) : movementCostFactor(1.0f), position(x, y) {
        if(x < 0 || y < 0) {
            throw std::invalid_argument("Negative coordinates not allowed.");
        }
        this->accessible = true;
    }

    int Node::getX() const {
        return position.getX();
    }

    int Node::getY() const {
        return position.getY();
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
        return lhs.position == rhs.position;
    }

    bool operator!=(const Node& lhs, const Node& rhs) {
        return lhs.position != rhs.position;
    }

    bool Node::isAccessible() const {
        return accessible;
    }

    void Node::setAccessible(bool isNodeAccessible) {
        this->accessible = isNodeAccessible;
    }

}
