#include "ToolController.h"

ToolController::ToolController(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    buildTool = new BuildTool(gameWorld);
    buildTool->changeTerrainTool(WALL);
}

ToolController::~ToolController() {
    delete buildTool;
}

void ToolController::update(const Point& point) {
    int x = point.getX();
    int y = point.getY();

    if(gameWorld->getBlockGraph()->nodeExistsInPosition(x, y)) {
        buildTool->moveTo(point);
    }
}
