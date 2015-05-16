#include "InputController.h"

InputController::InputController(GameWorld *gameWorld) :
    gameWorld(gameWorld) {



}

void InputController::pollEvent(sf::Event& event) {
    if(event.type == sf::Event::MouseMoved) {
        int x = event.mouseMove.x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
        int y = event.mouseMove.y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);

        std::cout << "mouse moved to x: " << x << " y: " << y << std::endl;

        if(gameWorld->getBlockGraph()->nodeExistsInPosition(x, y)) {
            TerrainBlock* terrainBlock =
                    gameWorld->getBlockGraph()->getTerrainBlockInPosition(x, y);
            toolController.update(terrainBlock);
        }
    }
}
