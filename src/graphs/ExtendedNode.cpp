#include "ExtendedNode.h"

namespace pathfinder {

    ExtendedNode::ExtendedNode(const Node* node) : node(node){
        this->totalCost = -1.0f;
        this->currentCost = std::numeric_limits<float>::max();
        this->nodeIsInOpenList = false;
        this->nodeIsInClosedList = false;
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

    float ExtendedNode::getCurrentCost() const {
        return this->currentCost;
    }

    void ExtendedNode::setCurrentCost(float currentCost) {
        this->currentCost = currentCost;
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

    bool ExtendedNode::isInClosedList() const {
        return nodeIsInClosedList;
    }

    void ExtendedNode::setNodeToClosedList() {
        nodeIsInClosedList = true;
    }

    void ExtendedNode::setNodeRemovedFromClosedList() {
        nodeIsInClosedList = false;
    }

}
