#include "GrassBlock.h"

GrassBlock::GrassBlock(pathfinder::Node* node) :
    TerrainBlock(node, true, 2.0f, GRASS) {
}
