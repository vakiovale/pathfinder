#include "StartPointMover.h"

StartPointMover::StartPointMover(GameWorld *gameWorld) : PointMover(gameWorld) {
    // do nothing
}

void StartPointMover::movePoint() {
    gameWorld->moveStartTo(this->lastPosition);
}
