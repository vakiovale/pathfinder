#include "InputController.h"

InputController::InputController(GameWorld *gameWorld) :
    gameWorld(gameWorld), toolController(gameWorld) {
    // nothing to do yet
}

void InputController::pollEvent(sf::Event& event) {
    toolController.update();

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

    if(event.type == sf::Event::MouseWheelScrolled) {
        if(event.mouseWheelScroll.delta < 0) {
            gameWorld->decreaseMovementSpeed();
        }
        if(event.mouseWheelScroll.delta > 0) {
            gameWorld->increaseMovementSpeed();
        }
    }

    if(event.type == sf::Event::KeyPressed) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            toolController.changeBuildTool(WALL, lastMousePosition);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            toolController.changeBuildTool(GRASS, lastMousePosition);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            toolController.changeBuildTool(WATER, lastMousePosition);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            gameWorld->toggleMoving();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            toolController.changeStartPointMoverTool(lastMousePosition);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            toolController.changeEndPointMoverTool(lastMousePosition);
        }
    }

    if(event.type == sf::Event::KeyReleased) {
        if(event.key.code == sf::Keyboard::Add) {
            gameWorld->increaseMovementSpeed();
        }
        if(event.key.code == sf::Keyboard::Subtract) {
            gameWorld->decreaseMovementSpeed();
        }
    }
}

void InputController::mouseMoved(int x, int y) {
    lastMousePosition = getCurrentPointMouseIsOnTheMap(x, y);
    toolController.mouseMoved(lastMousePosition);
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

const Point InputController::getCurrentPointMouseIsOnTheMap(int xMousePosition,
                                                            int yMousePosition) const {
    int xBlock = xMousePosition / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
    int yBlock = yMousePosition / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);
    Point point(xBlock, yBlock);
    return point;
}
