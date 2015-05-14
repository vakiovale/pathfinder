#include "WallBlock.h"

WallBlock::WallBlock(pathfinder::Node* node) :
    TerrainBlock(node, false, 1.0f, WALL) {
}
