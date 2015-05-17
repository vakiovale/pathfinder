#include "EndPointMover.h"

EndPointMover::EndPointMover(GameWorld *gameWorld, const Point& currentPosition)
    : gameWorld(gameWorld) {
    lastPosition = currentPosition;
}

void EndPointMover::subExecute() {
    gameWorld->moveEndTo(this->lastPosition);
}

void EndPointMover::leftMouseAction() {

}

void EndPointMover::rightMouseAction() {

}
