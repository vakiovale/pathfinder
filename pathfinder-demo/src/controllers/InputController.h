#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

#include "DemoConfigurations.h"
#include "GameWorld.h"
#include <SFML/Graphics.hpp>

class InputController {

    public:
        InputController(GameWorld* gameWorld);

        void pollEvent(sf::Event& event);

    private:
        GameWorld* gameWorld;

};

#endif
