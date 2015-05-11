/**
 * @brief TerrainBlock class
 *
 * TerrainBlock is used for different kind of terrains. Nodes can be modified
 * by using TerrainBlocks.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef TERRAIN_BLOCK_H
#define TERRAIN_BLOCK_H

#include <Node.h>
#include "Terrain.h"

class TerrainBlock {

    public:
        /**
         * @brief Initialize TerrainBlock with a specific Node
         */
        TerrainBlock(pathfinder::Node* node);

        /**
         * @brief Set terrain properties for the specific node
         * @param node to be changed to use new properties
         */
        void setTerrainPropertiesForNode(pathfinder::Node& node);

        /**
         * @brief Get terrain of this class
         * @return terrain
         */
        Terrain getTerrain() const;

    protected:
        pathfinder::Node* const node;
        Terrain terrain;
        bool terrainIsAccessible;
        float movementCostFactor;

};

#endif
