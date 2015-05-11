#include "TerrainBlock.h"

TerrainBlock::TerrainBlock(pathfinder::Node* node) : node(node){
    terrainIsAccessible = true;
    movementCostFactor = 1.0f;
    terrain = PLAIN;
    setTerrainPropertiesForNode(*this->node);
}

void TerrainBlock::setTerrainPropertiesForNode(pathfinder::Node& node) {
    node.setAccessible(terrainIsAccessible);
    node.setMovementCostFactor(movementCostFactor);
}

Terrain TerrainBlock::getTerrain() const {
    return terrain;
}
