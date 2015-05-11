#include "BlockGraph.h"

BlockGraph::BlockGraph(int graphSize) {
    initializeGraph(graphSize);
    initializeBlocks();
}

BlockGraph::~BlockGraph() {
    for(std::vector<TerrainBlock*> rowOfBlocks : blocks) {
        for(TerrainBlock* block : rowOfBlocks) {
            delete block;
        }
    }
}

void BlockGraph::initializeGraph(int graphSize) {
    if(graphSize < 1) {
        graphSize = 35;
    }
    this->create2DGridMap(graphSize);
    width = graphSize;
    height = graphSize;
}

void BlockGraph::initializeBlocks() {
    std::vector<std::vector<pathfinder::Node>> nodes = this->getAllNodes();
    for(int i = 0; i < height; i++) {
        std::vector<TerrainBlock*> rowOfBlocks;
        for(int j = 0; j < width; j++) {
            rowOfBlocks.push_back(new TerrainBlock(this->getNodeFromPosition(j,i)));
        }
        blocks.push_back(rowOfBlocks);
    }
}

int BlockGraph::getWidth() const {
    return width;
}

int BlockGraph::getHeight() const {
    return height;
}

Terrain BlockGraph::getTerrainInPosition(int x, int y) const {
    return (blocks[y][x])->getTerrain();
}
