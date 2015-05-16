#include "BuildTool.h"

BuildTool::BuildTool() {
    terrainToUse = PLAIN;
}

void BuildTool::changeTerrainTool(Terrain terrain) {
    this->terrainToUse = terrain;
}

void BuildTool::hold(){}
void BuildTool::click(){}
void BuildTool::release(){}
void BuildTool::execute() {}
