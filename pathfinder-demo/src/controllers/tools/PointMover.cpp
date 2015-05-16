#include "PointMover.h"

PointMover::PointMover(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
}

void PointMover::execute() {
    if(primaryActionHasNotBeenExecuted()) {
        executedPrimaryActionOnce = true;
        movePoint();
    }
}

void PointMover::movePoint() {
    // do nothing here
}
