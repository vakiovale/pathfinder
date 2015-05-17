#include "ToolController.h"

ToolController::ToolController(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    tool = new StartPointMover(gameWorld, Point(0,0));
    tool->reset();
}

ToolController::~ToolController() {
    delete tool;
}

void ToolController::update() {
    tool->execute();
}

void ToolController::changeBuildTool(Terrain terrain,
                                     const Point& currentPosition) {
    delete tool;
    tool = new BuildTool(gameWorld, currentPosition);
    BuildTool* buildTool;
    buildTool = dynamic_cast<BuildTool*>(tool);
    buildTool->changeTerrainTool(terrain);
}

void ToolController::changeStartPointMoverTool(const Point& currentPosition) {
    delete tool;
    tool = new StartPointMover(gameWorld, currentPosition);
}

void ToolController::changeEndPointMoverTool(const Point& currentPosition) {
    delete tool;
    tool = new EndPointMover(gameWorld, currentPosition);
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
