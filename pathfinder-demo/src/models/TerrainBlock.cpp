#include "TerrainBlock.h"

TerrainBlock::TerrainBlock(pathfinder::Node* node,
                           bool terrainIsAccessible,
                           float movementCostFactor,
                           Terrain terrain) : point(node->getX(), node->getY()){
    this->terrainIsAccessible = terrainIsAccessible;
    this->movementCostFactor = movementCostFactor;
    this->terrain = terrain;
    setTerrainPropertiesForNode(*node);
}

void TerrainBlock::setTerrainPropertiesForNode(pathfinder::Node& node) {
    node.setAccessible(terrainIsAccessible);
    node.setMovementCostFactor(movementCostFactor);
}

Terrain TerrainBlock::getTerrain() const {
    return terrain;
}

const Point& TerrainBlock::getPoint() const {
    return point;
}
