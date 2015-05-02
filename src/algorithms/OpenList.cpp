#include "OpenList.h"

namespace pathfinder {

    OpenList::OpenList() {
        // nothing to do yet
    }

    void OpenList::add(ExtendedNode& node) {
        node.setNodeToOpenList();
        ExtendedNodePointer extendedNodePointer(&node);
        openList.push(extendedNodePointer);
    }

    void OpenList::removeBestNode() {
        const ExtendedNodePointer& bestNodePointer = openList.top();
        ExtendedNode& bestNode = bestNodePointer.getExtendedNode();
        bestNode.setNodeRemovedFromOpenList();
        openList.pop();
    }

    const ExtendedNode& OpenList::getBestNode() const {
        return openList.top().getExtendedNode();
    }

    bool OpenList::isEmpty() const {
        return openList.isEmpty();
    }

    bool OpenList::contains(const ExtendedNode& extendedNode) const {
        return extendedNode.isInOpenList();
    }

}
