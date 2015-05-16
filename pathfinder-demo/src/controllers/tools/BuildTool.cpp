#include "BuildTool.h"

BuildTool::BuildTool(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    terrainToUse = PLAIN;
}

void BuildTool::execute() {
    if(primaryActionHasNotBeenExecuted()) {
        executedPrimaryActionOnce = true;

        if(eraseMode)
            erase();
        else
            paint();

    }
}

bool BuildTool::primaryActionHasNotBeenExecuted() {
    return this->holdingLeftMouseButton && !executedPrimaryActionOnce;
}

void BuildTool::erase() {
    this->gameWorld->getBlockGraph()->
            changeBlockTerrainInPoint(this->lastPosition, PLAIN);
}

void BuildTool::paint() {
    this->gameWorld->getBlockGraph()->
            changeBlockTerrainInPoint(this->lastPosition, this->terrainToUse);
}

void BuildTool::clickLeftMouseButton() {
    if(!this->holdingLeftMouseButton) {
        checkEraseMode();
    }
    Tool::clickLeftMouseButton();
}

void BuildTool::clickRightMouseButton() {
    if(!this->holdingRightMouseButton) {
        checkEraseMode();
    }
    Tool::clickRightMouseButton();
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
    this->terrainToUse = terrain;
}

Terrain BuildTool::getTerrainToolIsOn() const {
    BlockGraph* blockGraph = this->gameWorld->getBlockGraph();
    return blockGraph->getTerrainInPosition(this->lastPosition);
}
