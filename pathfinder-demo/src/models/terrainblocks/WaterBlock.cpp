#include "WaterBlock.h"

WaterBlock::WaterBlock(pathfinder::Node* node) :
    TerrainBlock(node, true, 10.0f, WATER) {
}
