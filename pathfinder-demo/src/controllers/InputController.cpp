#include "InputController.h"

InputController::InputController(GameWorld *gameWorld) :
    gameWorld(gameWorld), toolController(gameWorld) {
    // nothing to do yet
}

void InputController::pollEvent(sf::Event& event) {
    if(event.type == sf::Event::MouseMoved) {
        mouseMoved(event.mouseMove.x, event.mouseMove.y);
    }

    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            leftMouseButtonPressed();
        }
        if(event.mouseButton.button == sf::Mouse::Right) {
            rightMouseButtonPressed();
        }
    }

    if(event.type == sf::Event::MouseButtonReleased) {
        if(event.mouseButton.button == sf::Mouse::Left) {
            leftMouseButtonReleased();
        }
        if(event.mouseButton.button == sf::Mouse::Right) {
            rightMouseButtonReleased();
        }
    }
}

void InputController::mouseMoved(int x, int y) {
    int xBlock = x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
    int yBlock = y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);

    std::cout << "mouse moved to x: " << xBlock << " y: " << yBlock << std::endl;

    toolController.update(Point(x,y));
}

void InputController::leftMouseButtonPressed() {
    std::cout << "LMB pressed" << std::endl;
}

void InputController::rightMouseButtonPressed() {
    std::cout << "RMB pressed" << std::endl;
}

void InputController::leftMouseButtonReleased() {
    std::cout << "LMB released" << std::endl;
}

void InputController::rightMouseButtonReleased() {
    std::cout << "RMB released" << std::endl;
}
