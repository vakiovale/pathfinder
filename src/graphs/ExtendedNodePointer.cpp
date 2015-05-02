#include "ExtendedNodePointer.h"

namespace pathfinder {

    ExtendedNodePointer::ExtendedNodePointer(ExtendedNode *extendedNode)
        : extendedNode(extendedNode){
        // nothing more to do
    }

    ExtendedNode& ExtendedNodePointer::getExtendedNode() const {
        return *(this->extendedNode);
    }

    bool ExtendedNodePointer::operator<(
            const ExtendedNodePointer& extendedNodePointer) const {
        return *(this->extendedNode) < *(extendedNodePointer.extendedNode);
    }

}
