#include "EndPointMover.h"

void EndPointMover::movePoint() {
    gameWorld->moveEndTo(this->lastPosition);
}
