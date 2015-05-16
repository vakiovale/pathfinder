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
    deleteGraph();
}

void BlockGraph::deleteGraph() {
    for(std::vector<TerrainBlock*>& innerVec : blocks) {
        for(int i = innerVec.size()-1; i >= 0; i--) {
            delete innerVec[i];
        }
    }
}

void BlockGraph::initializeBlocks() {
    cleanBlockGraph();
    for(int i = 0; i < height; i++) {
        std::vector<TerrainBlock*> rowOfBlocks;
        for(int j = 0; j < width; j++) {
            TerrainBlock* newTerrainBlock = new PlainBlock(this->getNodeFromPosition(j,i));
            rowOfBlocks.push_back(newTerrainBlock);
        }
        blocks.push_back(rowOfBlocks);
    }
}

void BlockGraph::cleanBlockGraph() {
    if(blocks.size() > 0) {
        deleteGraph();
        blocks.clear();
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
    delete getTerrainBlockInPosition(x, y);
    pathfinder::Node* node = getNodeFromPosition(x, y);

    switch (terrain) {
        case WALL:
            blocks[y][x] = new WallBlock(node);
            break;
        case PLAIN:
            blocks[y][x] = new PlainBlock(node);
            break;
        case GRASS:
            blocks[y][x] = new GrassBlock(node);
            break;
        case WATER:
            blocks[y][x] = new WaterBlock(node);
            break;
    }
}

TerrainBlock* BlockGraph::getTerrainBlockInPosition(int x, int y) {
    return blocks[y][x];
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
