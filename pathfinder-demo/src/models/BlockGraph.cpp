#include "BlockGraph.h"

BlockGraph::BlockGraph(int graphSize) {
    if(graphSize < 1) {
        graphSize = 35;
    }
    this->create2DGridMap(graphSize);
    width = graphSize;
    height = graphSize;
}

int BlockGraph::getWidth() const {
    return width;
}

int BlockGraph::getHeight() const {
    return height;
}
