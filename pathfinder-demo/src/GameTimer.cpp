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
    if(timeSinceLastFrame < 30) {
        int deltaTime = 30 - timeSinceLastFrame;
        std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime));
    }
}
