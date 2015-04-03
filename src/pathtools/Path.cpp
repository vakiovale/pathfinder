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

    void Path::removeLastNode() {
        this->path.pop_back();
    }

    const Node& Path::operator[](std::size_t index) const {
        return (this->path)[index];
    }

}
