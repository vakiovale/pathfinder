#include "TerrainBlock.h"

TerrainBlock::TerrainBlock() {
    terrainIsAccessible = true;
    movementCostFactor = 1.0f;
}

void TerrainBlock::setTerrainPropertiesForNode(pathfinder::Node& node) {
    node.setAccessible(terrainIsAccessible);
    node.setMovementCostFactor(movementCostFactor);
}

Terrain TerrainBlock::getTerrain() const {
    return terrain;
}
