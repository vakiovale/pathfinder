#include "Tool.h"

void Tool::moveTo(const Point newPosition) {

    justMovedToNewBlock = false;

    if(lastPosition != newPosition) {
       justMovedToNewBlock = true;
    }
    else {
        execute();
    }

    lastPosition = newPosition;
}

void Tool::hold() {}

void Tool::click() {}

void Tool::release() {}

void Tool::execute() {}
