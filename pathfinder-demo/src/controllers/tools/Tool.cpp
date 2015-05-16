#include "Tool.h"

void Tool::execute() {
    // do nothing with this tool
}

void Tool::moveTo(const Point newPosition) {
    if(lastPosition != newPosition) {
       justMovedToNewBlock = true;
       executedPrimaryActionOnce = false;
       executedSecondaryActionOnce = false;
    }
    else {
        justMovedToNewBlock = false;
    }
    lastPosition = newPosition;
}

void Tool::clickLeftMouseButton() {
    holdingLeftMouseButton = true;
}

void Tool::releaseLeftMouseButton() {
    holdingLeftMouseButton = false;
    executedPrimaryActionOnce = false;
}

void Tool::clickRightMouseButton() {
    holdingRightMouseButton = true;
}

void Tool::releaseRightMouseButton() {
    holdingRightMouseButton = false;
    executedSecondaryActionOnce = false;
}

void Tool::reset() {
    justMovedToNewBlock = false;
    holdingLeftMouseButton = false;
    holdingRightMouseButton = false;
    executedPrimaryActionOnce = false;
    executedSecondaryActionOnce = false;
}