#include "Tool.h"

void Tool::execute() {
    if(primaryActionExecutedFirstTime()) {
        subExecute();
    }
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
    leftMouseAction();
    holdingLeftMouseButton = true;
}

void Tool::releaseLeftMouseButton() {
    holdingLeftMouseButton = false;
    executedPrimaryActionOnce = false;
}

void Tool::clickRightMouseButton() {
    rightMouseAction();
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

bool Tool::primaryActionExecutedFirstTime() {
    if(holdingLeftMouseButton) {
        if(!executedPrimaryActionOnce) {
            executedPrimaryActionOnce = true;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
