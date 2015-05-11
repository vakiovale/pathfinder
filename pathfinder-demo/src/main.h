#ifndef MAIN_H
#define MAIN_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>

#include <Graph.h>
#include <Node.h>
#include <Point.h>
#include <PathFinder.h>
#include <AStarPathFinder.h>
#include <Path.h>

using namespace pathfinder;

const int NUMBER_OF_NODES_IN_A_ROW = 35;

const int NUMBER_OF_NODES_IN_A_COLUMN = NUMBER_OF_NODES_IN_A_ROW;

const int WINDOW_WIDTH = 600;

const int WINDOW_HEIGHT = 600;

const float BLOCK_WIDTH = WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW;

const float BLOCK_HEIGHT = WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pathfinder");

sf::Color gray(150, 150, 150);

Graph graph;

PathFinder* pathFinder;

Node* start;

Node* end;

Path* finalPath;

int main();

void createRandomWalls();

void pollEvents(sf::Event& event);

void draw();

void draw(int x, int y, sf::Color color);

void drawCircle(int x, int y, sf::Color color);

#endif
