#include "GameTimer.h"

GameTimer::GameTimer() {
    lastTime = clock.restart();
}

int GameTimer::getDeltaTime() {
    lastTime = clock.restart();
    return lastTime.asMilliseconds();
}

void GameTimer::sleep() {
    int timeSinceLastFrame = getDeltaTime();
    if(timeSinceLastFrame < 60) {
        int deltaTime = 60 - timeSinceLastFrame;
        std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime));
    }
}
