#ifndef PLAIN_BLOCK_H
#define PLAIN_BLOCK_H

#include "TerrainBlock.h"
#include "Terrain.h"
#include <Node.h>

class PlainBlock : public TerrainBlock {

    public:
        PlainBlock(pathfinder::Node* node);

};

#endif
