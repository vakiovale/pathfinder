#include "main.h"

int main() {
    gameWorld = new GameWorld(NUMBER_OF_NODES_IN_A_ROW);
    graphicsController = new GraphicsController(gameWorld, &window);
    inputController = new InputController(gameWorld);

    if(RANDOM_WALLS) {
        gameWorld->createRandomWalls();
    }

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            else
                inputController->pollEvent(event);
        }

        gameWorld->update();

        window.clear();

        graphicsController->draw();

        window.display();
    }

    delete inputController;
    delete graphicsController;
    delete gameWorld;

    return 0;
}
