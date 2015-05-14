#ifndef WALL_BLOCK_H
#define WALL_BLOCK_H

#include "TerrainBlock.h"
#include "Terrain.h"
#include <Node.h>

class WallBlock : public TerrainBlock {

    public:
        WallBlock(pathfinder::Node* node);

};

#endif
