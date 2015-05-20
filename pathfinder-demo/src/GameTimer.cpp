#include "GameTimer.h"

GameTimer::GameTimer() {
    lastTime = clock.restart();
}

int GameTimer::getAndUpdateDeltaTime() {
    lastTime = clock.restart();
    return lastTime.asMilliseconds();
}

long GameTimer::getDeltaTimeMicroSeconds() const {
    return lastTime.asMicroseconds();
}

void GameTimer::sleep() {
    int timeSinceLastFrame = getAndUpdateDeltaTime();
    if(timeSinceLastFrame < 30) {
        int deltaTime = 30 - timeSinceLastFrame;
        std::this_thread::sleep_for(std::chrono::milliseconds(deltaTime));
    }
}
