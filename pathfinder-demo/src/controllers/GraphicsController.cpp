#include "GraphicsController.h"

GraphicsController::GraphicsController(GameWorld* gameWorld,
                                       sf::RenderWindow* window) :
    gameWorld(gameWorld), window(window) {
    // do nothing yet
}

void GraphicsController::draw() {
    drawMainWindow();
}

void GraphicsController::drawMainWindow() {
    for(int i = 0; i < NUMBER_OF_NODES_IN_A_COLUMN; i++) {
        for(int j = 0; j < NUMBER_OF_NODES_IN_A_ROW; j++) {
            drawTerrainBlock(gameWorld->
                             getBlockGraph()->
                             getTerrainBlockInPosition(j,i));
        }
    }

    if(DISPLAY_PATH) drawPath();

    const Point& start = gameWorld->getStartPoint();
    const Point& end = gameWorld->getEndPoint();

    draw(start.getX(), start.getY(), sf::Color::Red);
    draw(end.getX(), end.getY(), sf::Color::Blue);
}

void GraphicsController::drawTerrainBlock(const TerrainBlock* terrainBlock) {
    int x = terrainBlock->getPoint().getX();
    int y = terrainBlock->getPoint().getY();
    Terrain terrain = terrainBlock->getTerrain();
    sf::Color color;

    switch(terrain) {
        case WALL:
            color = wallColor;
            break;
        case PLAIN:
            color = sf::Color::White;
            break;
        case GRASS:
            color = grassColor;
            break;
        case WATER:
            color = waterColor;
            break;
        default:
            color = sf::Color::White;
            break;
    }
    draw(x, y, color);
}

void GraphicsController::draw(int x, int y, sf::Color color) {
    sf::RectangleShape shape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
    shape.setOrigin(sf::Vector2f(-x*BLOCK_WIDTH, -y*BLOCK_HEIGHT));

    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(color);

    window->draw(shape);
}

void GraphicsController::drawPath() {
    const Path& path = gameWorld->getPath();
    for(int i = 1; i < path.getPathLength()-1; i++) {
        drawCircle(path[i].getX(),
             path[i].getY(),
             sf::Color(255, 255, 0, 255));
    }
}

void GraphicsController::drawCircle(int x, int y, sf::Color color) {
    sf::CircleShape shape(BLOCK_WIDTH/6);
    shape.setOrigin(sf::Vector2f(-x*BLOCK_WIDTH - BLOCK_WIDTH/4,
                                 -y*BLOCK_HEIGHT - BLOCK_HEIGHT/4));

    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(color);

    window->draw(shape);
}
