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

    if(event.type == sf::Event::KeyPressed) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            toolController.changeBuildTool(WALL);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            toolController.changeBuildTool(GRASS);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            toolController.changeBuildTool(WATER);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            gameWorld->toggleMoving();
        }
    }

    toolController.update();
}

void InputController::mouseMoved(int x, int y) {
    int xBlock = x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
    int yBlock = y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);
    toolController.mouseMoved(Point(xBlock, yBlock));
}

void InputController::leftMouseButtonPressed() {
    toolController.leftMouseButtonPressed();
}

void InputController::rightMouseButtonPressed() {
    // right mouse button pressed
}

void InputController::leftMouseButtonReleased() {
    toolController.leftMouseButtonReleased();
}

void InputController::rightMouseButtonReleased() {
    // right mouse button released
}
