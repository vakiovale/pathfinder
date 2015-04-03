#include "Path.h"

namespace pathfinder {

    Path::Path() {
        numberOfNodesInPath = 0;
    }

    bool Path::pathExists() const {
        return !this->path.empty();
    }

    int Path::getPathLength() const {
        return numberOfNodesInPath;
    }

    void Path::addNode(Node nodeToBeAddedToPath) {
        this->path.push_back(nodeToBeAddedToPath);
        numberOfNodesInPath++;
    }

    void Path::removeLastNode() {
        if(pathExists()) {
            this->path.pop_back();
            numberOfNodesInPath--;
        }
    }

    const Node& Path::operator[](std::size_t index) const {
        return (this->path)[index];
    }

}
