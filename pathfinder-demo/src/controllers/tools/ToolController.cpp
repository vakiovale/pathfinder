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
    delete tool;
    tool = new BuildTool(gameWorld);
    BuildTool* buildTool;
    buildTool = dynamic_cast<BuildTool*>(tool);
    buildTool->changeTerrainTool(terrain);
}

void ToolController::changeStartPointMoverTool() {
    delete tool;
    tool = new StartPointMover(gameWorld);
}

void ToolController::changeEndPointMoverTool() {
    delete tool;
    tool = new EndPointMover(gameWorld);
}

void ToolController::mouseMoved(const Point& point) {
    int x = point.getX();
    int y = point.getY();

    if(gameWorld->getBlockGraph()->nodeExistsInPosition(x, y)) {
        tool->moveTo(point);
    }
}

void ToolController::leftMouseButtonPressed() {
    tool->clickLeftMouseButton();
}

void ToolController::rightMouseButtonPressed() {
    tool->clickRightMouseButton();
}

void ToolController::leftMouseButtonReleased() {
    tool->releaseLeftMouseButton();
}

void ToolController::rightMouseButtonReleased() {
    tool->releaseRightMouseButton();
}
