#include "EndPointMover.h"

EndPointMover::EndPointMover(GameWorld *gameWorld) : PointMover(gameWorld) {
    // do nothing
}

void EndPointMover::movePoint() {
    gameWorld->moveEndTo(this->lastPosition);
}
