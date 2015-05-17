#include "GameWorld.h"

GameWorld::GameWorld(int graphSize) {
    if(graphSize < 1) {
        graphSize = 35;
    }
    graph = new BlockGraph(graphSize);

    height = graphSize;
    width = graphSize;

    start = Point(0,0);
    end = Point(width-1, height-1);

    finalPath = new Path();
    pathFinder = new AStarPathFinder(graph);
    movingEnabled = false;
}

GameWorld::~GameWorld() {
    delete finalPath;
    delete pathFinder;
    delete graph;
}

void GameWorld::update() {
    if(graph->nodeExistsInPosition(start.getX(), start.getY()) &&
       graph->nodeExistsInPosition(end.getX(), end.getY())) {

        findShortestPath();

        if(movingEnabled && finalPath->getPathLength() > 1) {
            int x = (*finalPath)[1].getX();
            int y = (*finalPath)[1].getY();
            const Node* node = graph->getNodeFromPosition(x, y);
            if(node->isAccessible())
                start = Point(node->getX(), node->getY());
        }
    }
}

void GameWorld::findShortestPath() {
    delete finalPath;
    Node startNode(start.getX(), start.getY());
    Node endNode(end.getX(), end.getY());
    finalPath = new Path(pathFinder->findAndGetShortestPath(startNode, endNode));
}

void GameWorld::useAStarAlgorithm() {
    delete pathFinder;
    pathFinder = new AStarPathFinder(graph);
}

int GameWorld::getWidth() const {
    return width;
}

int GameWorld::getHeight() const {
    return height;
}

void GameWorld::createRandomWalls() {

    int numberOfNodes = graph->getNumberOfNodes();
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());
    std::uniform_int_distribution<int> uniform_dist(0, width-1);

    for(int i = 0; i < numberOfNodes / 3; i++) {
        int x = uniform_dist(randomEngine);
        int y = uniform_dist(randomEngine);

        if(graph->nodeExistsInPosition(x, y))
            graph->changeBlockTerrainInPoint(Point(x, y), WALL);
    }
}

BlockGraph* GameWorld::getBlockGraph() {
    return graph;
}

void GameWorld::toggleMoving() {
    movingEnabled = !movingEnabled;
}

const Point& GameWorld::getStartPoint() const {
    return start;
}

const Point& GameWorld::getEndPoint() const {
    return end;
}

void GameWorld::moveStartTo(const Point& point) {
    start = point;
}

void GameWorld::moveEndTo(const Point& point) {
    end = point;
}

const Path& GameWorld::getPath() const {
    return *finalPath;
}
