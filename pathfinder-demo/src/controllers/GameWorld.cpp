#include "GameWorld.h"

GameWorld::GameWorld(int graphSize) {
    if(graphSize < 1) {
        graphSize = 35;
    }
    graph.create2DGridMap(graphSize);

    height = graphSize;
    width = graphSize;

    pathFinder = new AStarPathFinder(&graph);
}

GameWorld::~GameWorld() {
    if(pathFinder) {
        delete pathFinder;
    }
}

void GameWorld::update() {
    // update
}

void GameWorld::useAStarAlgorithm() {
    if(pathFinder) {
        delete pathFinder;
    }
    pathFinder = new AStarPathFinder(&graph);
}

int GameWorld::getWidth() const {
    return width;
}

int GameWorld::getHeight() const {
    return height;
}
