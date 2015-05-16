#include "Tool.h"

void Tool::moveTo(const TerrainBlock* newPosition) {

    justMovedToNewBlock = false;

    if(lastPosition) {
        if(lastPosition->getPoint() != newPosition->getPoint()) {
            justMovedToNewBlock = true;
        }
        else {
            execute();
        }
    }

    lastPosition = newPosition;
}

void Tool::hold() {}

void Tool::click() {}

void Tool::release() {}

void Tool::execute() {}
