#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Graph.h>
#include <Node.h>

using namespace pathfinder;

const int NUMBER_OF_NODES_IN_A_ROW = 25;

const int NUMBER_OF_NODES_IN_A_COLUMN = NUMBER_OF_NODES_IN_A_ROW;

const int WINDOW_WIDTH = 800;

const int WINDOW_HEIGHT = 800;

const float BLOCK_WIDTH = WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW;

const float BLOCK_HEIGHT = WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pathfinder");

sf::Color gray(150, 150, 150);

Graph graph;

int main();

void draw();

#endif
