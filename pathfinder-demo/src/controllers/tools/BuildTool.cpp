#include "BuildTool.h"

BuildTool::BuildTool(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
    terrainToUse = PLAIN;
}

void BuildTool::execute() {
    if(primaryActionExecutedFirstTime()) {
        if(eraseMode)
            erase();
        else
            paint();
    }
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

void BuildTool::clickLeftMouseButton() {
    if(!this->holdingLeftMouseButton) {
        checkEraseMode();
    }
    Tool::clickLeftMouseButton();
}

void BuildTool::clickRightMouseButton() {
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
    return blockGraph->getTerrainInPosition(this->lastPosition);
}
