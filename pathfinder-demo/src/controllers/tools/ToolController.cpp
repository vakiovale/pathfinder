#include "ToolController.h"

ToolController::ToolController(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    tool = new BuildTool(gameWorld);

    BuildTool* buildTool = dynamic_cast<BuildTool*>(tool);
    buildTool->changeTerrainTool(WALL);
}

ToolController::~ToolController() {
    delete tool;
}

void ToolController::update() {
    tool->execute();
}

void ToolController::changeBuildTool(Terrain terrain) {
    BuildTool* buildTool = dynamic_cast<BuildTool*>(tool);
    buildTool->changeTerrainTool(terrain);
}

void ToolController::mouseMoved(const Point& point) {
    int x = point.getX();
    int y = point.getY();

    if(gameWorld->getBlockGraph()->nodeExistsInPosition(x, y)) {
        tool->moveTo(point);
    }
}

void ToolController::leftMouseButtonPressed() {
    BuildTool* buildTool = dynamic_cast<BuildTool*>(tool);
    if(buildTool) {
        buildTool->clickLeftMouseButton();
    }
    else {
        tool->clickLeftMouseButton();
    }
}

void ToolController::rightMouseButtonPressed() {
    BuildTool* buildTool = dynamic_cast<BuildTool*>(tool);
    if(buildTool) {
        buildTool->clickRightMouseButton();
    }
    else {
        tool->clickRightMouseButton();
    }
}

void ToolController::leftMouseButtonReleased() {
    tool->releaseLeftMouseButton();
}

void ToolController::rightMouseButtonReleased() {
    tool->releaseRightMouseButton();
}
