#include "StartPointMover.h"

void StartPointMover::movePoint() {
    gameWorld->moveStartTo(this->lastPosition);
}
