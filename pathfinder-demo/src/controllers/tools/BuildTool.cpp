#include "BuildTool.h"

BuildTool::BuildTool(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    terrainToUse = PLAIN;
}

void BuildTool::changeTerrainTool(Terrain terrain) {
    this->terrainToUse = terrain;
}
