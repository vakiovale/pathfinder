#include "StartPointMover.h"

StartPointMover::StartPointMover(GameWorld *gameWorld, const Point& currentPosition)
    : gameWorld(gameWorld) {
    lastPosition = currentPosition;
}

void StartPointMover::subExecute() {
    gameWorld->moveStartTo(this->lastPosition);
}

void StartPointMover::leftMouseAction() {

}

void StartPointMover::rightMouseAction() {

}
