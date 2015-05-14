#ifndef GRAPHICS_CONTROLLER_H
#define GRAPHICS_CONTROLLER_H

#include "DemoConfigurations.h"
#include "GameWorld.h"
#include <SFML/Graphics.hpp>

class GraphicsController {

    public:
        GraphicsController(GameWorld* gameWorld,
                           sf::RenderWindow* window);

        void draw();

    private:
        GameWorld* gameWorld;

        sf::RenderWindow* window;

        void draw(int x, int y, sf::Color color);

        void drawCircle(int x, int y, sf::Color color);

        sf::Color gray;
};

#endif
