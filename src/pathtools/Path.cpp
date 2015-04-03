#include "Path.h"

namespace pathfinder {

    Path::Path() {
        // do nothing yet
    }

    bool Path::pathExists() const {
        return !this->path.empty();
    }

    void Path::addNode(Node nodeToBeAddedToPath) {
        this->path.push_back(nodeToBeAddedToPath);
    }

}
