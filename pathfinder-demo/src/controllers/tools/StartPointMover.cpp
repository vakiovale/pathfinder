#include "StartPointMover.h"

StartPointMover::StartPointMover(GameWorld *gameWorld) : gameWorld(gameWorld) {
    // do nothing
}

void StartPointMover::subExecute() {
    gameWorld->moveStartTo(this->lastPosition);
}

void StartPointMover::leftMouseAction() {

}

void StartPointMover::rightMouseAction() {

}
