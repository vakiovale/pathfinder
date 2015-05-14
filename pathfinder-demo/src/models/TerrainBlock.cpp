#include "TerrainBlock.h"

TerrainBlock::TerrainBlock(pathfinder::Node* node,
                           bool terrainIsAccessible,
                           float movementCostFactor,
                           Terrain terrain) : node(node){
    this->terrainIsAccessible = terrainIsAccessible;
    this->movementCostFactor = movementCostFactor;
    this->terrain = terrain;
    setTerrainPropertiesForNode(*this->node);
}

void TerrainBlock::setTerrainPropertiesForNode(pathfinder::Node& node) {
    node.setAccessible(terrainIsAccessible);
    node.setMovementCostFactor(movementCostFactor);
}

Terrain TerrainBlock::getTerrain() const {
    return terrain;
}
