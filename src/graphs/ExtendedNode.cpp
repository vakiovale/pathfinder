#include "ExtendedNode.h"

namespace pathfinder {

    ExtendedNode::ExtendedNode(const Node* node) : node(node){
        // do nothing at the moment
    }

    const Node& ExtendedNode::getNode() {
        return *(this->node);
    }

}
