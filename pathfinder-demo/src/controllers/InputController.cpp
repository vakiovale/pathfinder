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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
            toolController.changeBuildTool(WALL, lastMousePosition);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
            toolController.changeBuildTool(GRASS, lastMousePosition);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            moveEndPointUp();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            moveEndPointDown();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            moveEndPointLeft();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            moveEndPointRight();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
            toolController.makeBuildActionToPosition(gameWorld->getEndPoint());
        }
    }

    if(event.type == sf::Event::KeyReleased) {
        if(event.key.code == sf::Keyboard::Add ||
           event.key.code == sf::Keyboard::PageUp) {
            gameWorld->increaseMovementSpeed();
        }
        if(event.key.code == sf::Keyboard::Subtract ||
           event.key.code == sf::Keyboard::PageDown ||
           event.key.code == sf::Keyboard::Dash) {
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

void InputController::moveEndPointUp() {
    const Point& point = gameWorld->getEndPoint();
    int newX = point.getX();
    int newY = point.getY()-1;
    Point newPoint(newX, newY);
    moveToPointIfAccessible(newPoint);
}

void InputController::moveEndPointDown() {
    const Point& point = gameWorld->getEndPoint();
    int newX = point.getX();
    int newY = point.getY()+1;
    Point newPoint(newX, newY);
    moveToPointIfAccessible(newPoint);
}

void InputController::moveEndPointLeft() {
    const Point& point = gameWorld->getEndPoint();
    int newX = point.getX()-1;
    int newY = point.getY();
    Point newPoint(newX, newY);
    moveToPointIfAccessible(newPoint);
}

void InputController::moveEndPointRight() {
    const Point& point = gameWorld->getEndPoint();
    int newX = point.getX()+1;
    int newY = point.getY();
    Point newPoint(newX, newY);
    moveToPointIfAccessible(newPoint);
}

void InputController::moveToPointIfAccessible(Point& newPoint) {
    int newX = newPoint.getX();
    int newY = newPoint.getY();
    if(gameWorld->getBlockGraph()->nodeExistsInPosition(newX, newY)) {
        if(gameWorld->getBlockGraph()->getNodeFromPosition(newX, newY)->isAccessible()) {
            gameWorld->moveEndTo(Point(newX, newY));
        }
    }
}
