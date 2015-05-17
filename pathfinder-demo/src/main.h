#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.hpp>

#include "DemoConfigurations.h"

#include "GameWorld.h"
#include "GraphicsController.h"
#include "InputController.h"

#include "GameTimer.h"

using namespace pathfinder;

GameWorld* gameWorld;
GraphicsController* graphicsController;
InputController* inputController;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                        "Pathfinder");

int main();

#endif
