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

        void drawMainWindow();

        void draw(int x, int y, sf::Color color);

        void drawCircle(int x, int y, sf::Color color);

        sf::Color wallColor = sf::Color(150, 150, 150);

        sf::Color grassColor = sf::Color(100, 150, 100);

        sf::Color waterColor = sf::Color(0, 191, 255);
};

#endif
