#include "PointMover.h"

PointMover::PointMover(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
}

void PointMover::execute() {
    if(primaryActionExecutedFirstTime()) {
        movePoint();
    }
}

void PointMover::movePoint() {
    // do nothing here
}
