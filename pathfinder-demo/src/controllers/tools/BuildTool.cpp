#include "BuildTool.h"

BuildTool::BuildTool(GameWorld* gameWorld, const Point& currentPosition) {
    this->gameWorld = gameWorld;
    this->lastPosition = currentPosition;
    terrainToUse = PLAIN;
}

void BuildTool::subExecute() {
    if(eraseMode)
        erase();
    else
        paint();
}

void BuildTool::erase() {
    if(toolIsOnSameTerrainAsTerrainToUse()) {
        this->gameWorld->getBlockGraph()->
                changeBlockTerrainInPoint(this->lastPosition, PLAIN);
    }
}

bool BuildTool::toolIsOnSameTerrainAsTerrainToUse() {
    Terrain terrainToolIsOn = getTerrainToolIsOn();
    return terrainToolIsOn == this->terrainToUse;
}

void BuildTool::paint() {
    this->gameWorld->getBlockGraph()->
            changeBlockTerrainInPoint(this->lastPosition, this->terrainToUse);
}

void BuildTool::leftMouseAction() {
    if(!this->holdingLeftMouseButton) {
        checkEraseMode();
    }
}

void BuildTool::rightMouseAction() {
    // do nothing
}

void BuildTool::checkEraseMode() {
    Terrain terrain = getTerrainToolIsOn();
    if(this->terrainToUse == terrain) {
        eraseMode = true;
    }
    else {
        eraseMode = false;
    }
}

void BuildTool::changeTerrainTool(Terrain terrain) {
    this->reset();
    this->terrainToUse = terrain;
}

Terrain BuildTool::getTerrainToolIsOn() const {
    BlockGraph* blockGraph = this->gameWorld->getBlockGraph();
    blockGraph->nodeExistsInPosition(this->lastPosition.getX(), this->lastPosition.getY());
    return blockGraph->getTerrainInPosition(this->lastPosition);
}
