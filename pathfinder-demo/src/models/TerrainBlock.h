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

#include <Point.h>
#include <Node.h>
#include "Terrain.h"

using namespace pathfinder;

class TerrainBlock {

    public:
        /**
         * @brief Initialize TerrainBlock with a specific Node
         */
        TerrainBlock(pathfinder::Node* node, bool terrainIsAccessible,
                     float movementCostFactor, Terrain terrain);

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

        /**
         * @brief Get point where TerrainBlock is
         * @return position of TerrainBlock
         */
        const Point& getPoint() const;

    protected:
        const pathfinder::Point point;
        Terrain terrain;
        bool terrainIsAccessible;
        float movementCostFactor;

};

#endif
