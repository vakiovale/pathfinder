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
            Node* node = gameWorld->getBlockGraph()->getNodeFromPosition(j,i);
            int x = node->getX();
            int y = node->getY();

            sf::Color color;

            if(node->isAccessible()) {
                float factor = node->getMovementCostFactor();
                if(factor < 2.0f)
                    color = sf::Color::White;
                else if(factor < 10.0f)
                    color = grassColor;
                else
                    color = waterColor;
            }
            else {
                color = wallColor;
            }

            draw(x, y, color);
        }
    }

    const Path& path = gameWorld->getPath();
    for(int i = 1; i < path.getPathLength()-1; i++) {
        drawCircle(path[i].getX(),
             path[i].getY(),
             sf::Color(255, 255, 0, 255));
    }

    const Point& start = gameWorld->getStartPoint();
    const Point& end = gameWorld->getEndPoint();

    draw(start.getX(), start.getY(), sf::Color::Red);
    draw(end.getX(), end.getY(), sf::Color::Blue);
}

void GraphicsController::draw(int x, int y, sf::Color color) {
    sf::RectangleShape shape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
    shape.setOrigin(sf::Vector2f(-x*BLOCK_WIDTH, -y*BLOCK_HEIGHT));

    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(color);

    window->draw(shape);
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
