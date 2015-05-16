#include "GameWorld.h"

GameWorld::GameWorld(int graphSize) {
    if(graphSize < 1) {
        graphSize = 35;
    }
    graph.create2DGridMap(graphSize);

    createRandomWalls();

    start = graph.getNodeFromPosition(0, 0);
    end = graph.getNodeFromPosition(1, 1);

    height = graphSize;
    width = graphSize;

    pathFinder = new AStarPathFinder(&graph);
}

GameWorld::~GameWorld() {
    if(finalPath) {
        delete finalPath;
    }
    if(pathFinder) {
        delete pathFinder;
    }
}

void GameWorld::update() {
    if(finalPath) {
        delete finalPath;
    }
    finalPath = new Path(pathFinder->findAndGetShortestPath(*start, *end));
    if(finalPath->getPathLength() > 1) {
        int x = (*finalPath)[1].getX();
        int y = (*finalPath)[1].getY();
        start = graph.getNodeFromPosition(x, y);
    }
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

void GameWorld::createRandomWalls() {

    int numberOfNodes = graph.getNumberOfNodes();
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::uniform_int_distribution<int> uniform_dist(0, width-1);

    for(int i = 0; i < numberOfNodes / 3; i++) {
        int x = uniform_dist(randomEngine);
        int y = uniform_dist(randomEngine);
        if(graph.nodeExistsInPosition(x, y))
            graph.changeBlockTerrainInPoint(Point(x, y), WALL);
    }
}

BlockGraph* GameWorld::getBlockGraph() {
    return &graph;
}
