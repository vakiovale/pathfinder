#ifndef GRASS_BLOCK_H
#define GRASS_BLOCK_H

#include "TerrainBlock.h"
#include "Terrain.h"
#include <Node.h>

class GrassBlock : public TerrainBlock {

    public:
        GrassBlock(pathfinder::Node* node);

};

#endif
