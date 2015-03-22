#include "Node.h"

namespace pathfinder {

    Node::Node(int x, int y) {
        if(x < 0 || y < 0) {
            throw std::invalid_argument("Negative coordinates not allowed.");
        }
        this->x = x;
        this->y = y;
    }

    Node::~Node() {
        // do nothing special
    }

    int Node::getX() const {
        return x;
    }

    int Node::getY() const {
        return y;
    }

}
