#include "ExtendedNode.h"

namespace pathfinder {

    ExtendedNode::ExtendedNode(const Node* node) : node(node){
        this->totalCost = -1.0f;
        this->nodeIsInOpenList = false;
    }

    const Node& ExtendedNode::getNode() const {
        return *(this->node);
    }

    bool operator==(const ExtendedNode& lhs, const ExtendedNode& rhs) {
        return lhs.getNode() == rhs.getNode();
    }

    bool operator!=(const ExtendedNode& lhs, const ExtendedNode& rhs) {
        return !(lhs == rhs);
    }

    bool ExtendedNode::operator<(const ExtendedNode& node) const {
        return this->totalCost > node.getTotalCost();
    }

    float ExtendedNode::getTotalCost() const {
        return this->totalCost;
    }

    void ExtendedNode::setTotalCost(float totalCost) {
        this->totalCost = totalCost;
    }

    bool ExtendedNode::isInOpenList() const {
        return nodeIsInOpenList;
    }

    void ExtendedNode::setNodeToOpenList() {
        nodeIsInOpenList = true;
    }

    void ExtendedNode::setNodeRemovedFromOpenList() {
        nodeIsInOpenList = false;
    }

}
