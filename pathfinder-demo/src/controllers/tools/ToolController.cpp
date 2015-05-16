#include "ToolController.h"

ToolController::ToolController(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    buildTool = new BuildTool(gameWorld);
    buildTool->changeTerrainTool(WALL);
}

ToolController::~ToolController() {
    delete buildTool;
}

void ToolController::update() {
    buildTool->execute();
}

void ToolController::changeBuildTool(Terrain terrain) {
    buildTool->changeTerrainTool(terrain);
}

void ToolController::mouseMoved(const Point& point) {
    int x = point.getX();
    int y = point.getY();

    if(gameWorld->getBlockGraph()->nodeExistsInPosition(x, y)) {
        buildTool->moveTo(point);
    }
}

void ToolController::leftMouseButtonPressed() {
    buildTool->clickLeftMouseButton();
}

void ToolController::rightMouseButtonPressed() {
    buildTool->clickRightMouseButton();
}

void ToolController::leftMouseButtonReleased() {
    buildTool->releaseLeftMouseButton();
}

void ToolController::rightMouseButtonReleased() {
    buildTool->releaseRightMouseButton();
}
