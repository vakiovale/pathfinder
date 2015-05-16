#include "PointMover.h"

PointMover::PointMover(GameWorld* gameWorld) {
    this->gameWorld = gameWorld;
}

void PointMover::subExecute() {
    movePoint();
}
