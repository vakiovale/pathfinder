#include "OpenList.h"

namespace pathfinder {

    OpenList::OpenList() {
        // nothing to do yet
    }

    void OpenList::add(const ExtendedNode& node) {
        ExtendedNodePointer extendedNodePointer(&node);
        openList.push(extendedNodePointer);
    }

    void OpenList::removeBestNode() {
        openList.pop();
    }

    const ExtendedNode& OpenList::getBestNode() const {
        return openList.top().getExtendedNode();
    }

    bool OpenList::isEmpty() const {
        return openList.isEmpty();
    }

}
