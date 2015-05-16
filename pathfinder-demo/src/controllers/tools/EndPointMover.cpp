#include "EndPointMover.h"

EndPointMover::EndPointMover(GameWorld *gameWorld) : gameWorld(gameWorld) {
    // do nothing
}

void EndPointMover::subExecute() {
    gameWorld->moveEndTo(this->lastPosition);
}

void EndPointMover::leftMouseAction() {

}

void EndPointMover::rightMouseAction() {

}
