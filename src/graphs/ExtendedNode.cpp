#include "ExtendedNode.h"

namespace pathfinder {

    ExtendedNode::ExtendedNode(const Node* node) : node(node){
        this->totalCost = -1.0f;
    }

    const Node& ExtendedNode::getNode() {
        return *(this->node);
    }

    float ExtendedNode::getTotalCost() const {
        return this->totalCost;
    }

    void ExtendedNode::setTotalCost(float totalCost) {
        this->totalCost = totalCost;
    }

}
