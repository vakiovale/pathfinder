#include "BlockGraph.h"

BlockGraph::BlockGraph(int graphSize) {
    initializeGraph(graphSize);
    initializeBlocks();
}

void BlockGraph::initializeGraph(int graphSize) {
    if(graphSize < 1) {
        graphSize = 35;
    }
    this->create2DGridMap(graphSize);
    width = graphSize;
    height = graphSize;
}

BlockGraph::~BlockGraph() {
    for(std::vector<TerrainBlock*>& innerVec : blocks) {
        for(int i = innerVec.size()-1; i >= 0; i--) {
            delete innerVec[i];
        }
    }
}

void BlockGraph::initializeBlocks() {
    for(int i = 0; i < height; i++) {
        std::vector<TerrainBlock*> rowOfBlocks;
        for(int j = 0; j < width; j++) {
            TerrainBlock* newTerrainBlock = new PlainBlock(this->getNodeFromPosition(j,i));
            rowOfBlocks.push_back(newTerrainBlock);
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
            delete (blocks[y][x]);
            (blocks[y][x]) = new WallBlock(nodeInBlock);
            break;
        case PLAIN:
            delete (blocks[y][x]);
            (blocks[y][x]) = new PlainBlock(nodeInBlock);
            break;
        case GRASS:
            delete (blocks[y][x]);
            (blocks[y][x]) = new GrassBlock(nodeInBlock);
            break;
        case WATER:
            delete (blocks[y][x]);
            (blocks[y][x]) = new WaterBlock(nodeInBlock);
            break;
    }
}

TerrainBlock* BlockGraph::getTerrainBlockInPosition(int x, int y) {
    TerrainBlock* block = (blocks[y][x]);
    return block;
}

void BlockGraph::printTerrainBlockPositions() const {
    std::cout<< "printing blocks" << std::endl;
    for(std::vector<TerrainBlock*> rowOfBlocks : this->blocks) {
        for(TerrainBlock* block : rowOfBlocks) {
            std::cout << "X:" << block->getPoint().getX() << "Y:" << block->getPoint().getY() << "\t";
        }
        std::cout << std::endl;
    }
}
