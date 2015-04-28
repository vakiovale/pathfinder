#include "ExtendedNodePointer.h"

namespace pathfinder {

    ExtendedNodePointer::ExtendedNodePointer(const ExtendedNode *extendedNode)
        : extendedNode(extendedNode){
        // nothing more to do
    }

    const ExtendedNode& ExtendedNodePointer::getExtendedNode() const {
        return *(this->extendedNode);
    }

    bool ExtendedNodePointer::operator<(
            const ExtendedNodePointer& extendedNodePointer) const {
        return *(this->extendedNode) < *(extendedNodePointer.extendedNode);
    }

}
