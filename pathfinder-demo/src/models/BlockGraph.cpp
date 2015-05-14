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
            rowOfBlocks.push_back(new TerrainBlock(
                                      this->getNodeFromPosition(j,i),
                                      true, 1.0f, PLAIN));
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

Terrain BlockGraph::getTerrainInPosition(const pathfinder::Point& position) const {
    return getTerrainInPosition(position.getX(), position.getY());
}

Terrain BlockGraph::getTerrainInPosition(int x, int y) const {
    return (blocks[y][x])->getTerrain();
}

void BlockGraph::changeBlockTerrainInPoint(const pathfinder::Point &position,
                                           Terrain terrain) {
    changeBlockTerrainInPoint(position.getX(), position.getY(), terrain);
}

void BlockGraph::changeBlockTerrainInPoint(int x, int y, Terrain terrain) {
    TerrainBlock* blockToBeChanged = getTerrainBlockInPosition(x, y);
    pathfinder::Node* nodeInBlock = getNodeFromPosition(x, y);

    switch (terrain) {
        case WALL:
            delete blockToBeChanged;
            blockToBeChanged = new WallBlock(nodeInBlock);
            break;
        case PLAIN:
            delete blockToBeChanged;
            blockToBeChanged = new PlainBlock(nodeInBlock);
            break;
        case GRASS:
            delete blockToBeChanged;
            blockToBeChanged = new GrassBlock(nodeInBlock);
            break;
        case WATER:
            delete blockToBeChanged;
            blockToBeChanged = new WaterBlock(nodeInBlock);
            break;
    }
}

TerrainBlock* BlockGraph::getTerrainBlockInPosition(int x, int y) {
    return (blocks[y][x]);
}
