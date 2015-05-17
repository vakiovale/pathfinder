#ifndef GAME_TIMER_H
#define GAME_TIMER_H

#include <SFML/System/Clock.hpp>
#include <chrono>
#include <thread>

class GameTimer {

    public:
        GameTimer();

        int getDeltaTime();

        void sleep();

    private:
        sf::Clock clock;
        sf::Time lastTime;

};

#endif
