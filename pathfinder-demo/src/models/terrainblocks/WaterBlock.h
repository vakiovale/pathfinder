#ifndef WATER_BLOCK_H
#define WATER_BLOCK_H

#include "TerrainBlock.h"
#include "Terrain.h"
#include <Node.h>

class WaterBlock : public TerrainBlock {

    public:
        WaterBlock(pathfinder::Node* node);

};

#endif
