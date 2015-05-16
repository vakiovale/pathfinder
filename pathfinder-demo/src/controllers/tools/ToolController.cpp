#include "ToolController.h"

ToolController::ToolController() {
    buildTool = new BuildTool();
    buildTool->changeTerrainTool(WALL);
}

ToolController::~ToolController() {
    delete buildTool;
}

void ToolController::update(const TerrainBlock* terrainBlock) {
    buildTool->moveTo(terrainBlock);
}
