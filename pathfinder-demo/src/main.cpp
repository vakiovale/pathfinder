#include "main.h"

int main() {
    gameWorld = new GameWorld(35);

    graph.create2DGridMap(NUMBER_OF_NODES_IN_A_ROW);

    createRandomWalls();

    start = graph.getNodeFromPosition(0, 0);
    end = graph.getNodeFromPosition(1, 1);

    pathFinder = new AStarPathFinder(&graph);

    long counter = 0;
    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            pollEvents(event);
        }

        finalPath = new Path(pathFinder->findAndGetShortestPath(*start, *end));

        counter++;
        if(counter > 5 && finalPath->getPathLength() > 1) {
            counter = 0;
            int x = (*finalPath)[1].getX();
            int y = (*finalPath)[1].getY();
            start = graph.getNodeFromPosition(x, y);
        }

        window.clear();

        draw();

        window.display();

        delete finalPath;

    }
    
    delete pathFinder;
    delete gameWorld;

    return 0;
}

void createRandomWalls() {

    int numberOfNodes = graph.getNumberOfNodes();

    std::random_device randomDevice;

    std::default_random_engine randomEngine(randomDevice());

    std::uniform_int_distribution<int> uniform_dist(0,
                                                    NUMBER_OF_NODES_IN_A_ROW-1);

    for(int i = 0; i < numberOfNodes / 3; i++) {
        int x = uniform_dist(randomEngine);
        int y = uniform_dist(randomEngine);
        if(graph.nodeExistsInPosition(x, y))
            graph.getNodeFromPosition(x, y)->setAccessible(false);
        else
            std::cout << x << " " << y << std::endl;
    }
}

void pollEvents(sf::Event& event) {
    if(event.type == sf::Event::Closed)
        window.close();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        if(event.type == sf::Event::MouseButtonReleased) {
            int x = event.mouseButton.x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
            int y = event.mouseButton.y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);

            if (event.mouseButton.button == sf::Mouse::Left){
                Node* node = graph.getNodeFromPosition(x, y);
                node->setAccessible(!node->isAccessible());
            }
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
        if(event.type == sf::Event::MouseButtonReleased) {
            int x = event.mouseButton.x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
            int y = event.mouseButton.y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);

            if (event.mouseButton.button == sf::Mouse::Left){
                Node* node = graph.getNodeFromPosition(x, y);
                if(node->getMovementCostFactor() > 1.0f) {
                    node->setMovementCostFactor(1.0f);
                }
                else {
                    node->setMovementCostFactor(2.0f);
                }
            }
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(event.type == sf::Event::MouseButtonReleased) {
            int x = event.mouseButton.x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
            int y = event.mouseButton.y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);

            if (event.mouseButton.button == sf::Mouse::Left){
                Node* node = graph.getNodeFromPosition(x, y);
                if(node->getMovementCostFactor() > 2.0f) {
                    node->setMovementCostFactor(1.0f);
                }
                else {
                    node->setMovementCostFactor(10.0f);
                }
            }
        }
    }
    else if(event.type == sf::Event::MouseButtonPressed) {
        int x = event.mouseButton.x / (WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW);
        int y = event.mouseButton.y / (WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN);

        if(event.mouseButton.button == sf::Mouse::Left){
            start = graph.getNodeFromPosition(x, y);
        }
        if(event.mouseButton.button == sf::Mouse::Right) {
            end = graph.getNodeFromPosition(x, y);
        }
    }
}

void draw() {
    for(int i = 0; i < NUMBER_OF_NODES_IN_A_COLUMN; i++) {
        for(int j = 0; j < NUMBER_OF_NODES_IN_A_ROW; j++) {
            Node* node = graph.getNodeFromPosition(j,i);
            int x = node->getX();
            int y = node->getY();

            sf::Color color;

            if(node->isAccessible()) {
                float factor = node->getMovementCostFactor();
                if(factor < 2.0f)
                    color = sf::Color::White;
                else if(factor < 10.0f)
                    color = sf::Color(100, std::max(255.0f, factor*200.0f), 100);
                else
                    color = sf::Color(0, 191, 255);
            }
            else {
                color = gray;
            }

            if(node == start) {
                color = sf::Color::Blue;
            }

            if(node == end) {
                color = sf::Color::Red;
            }

            draw(x, y, color);
        }
    }

    for(int i = 1; i < finalPath->getPathLength()-1; i++) {
        drawCircle((*finalPath)[i].getX(),
             (*finalPath)[i].getY(),
             sf::Color(255, 255, 0, 255));
    }
}

void draw(int x, int y, sf::Color color) {
    sf::RectangleShape shape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
    shape.setOrigin(sf::Vector2f(-x*BLOCK_WIDTH, -y*BLOCK_HEIGHT));

    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(color);

    window.draw(shape);
}

void drawCircle(int x, int y, sf::Color color) {
    sf::CircleShape shape(BLOCK_WIDTH/6);
    shape.setOrigin(sf::Vector2f(-x*BLOCK_WIDTH - BLOCK_WIDTH/4,
                                 -y*BLOCK_HEIGHT - BLOCK_HEIGHT/4));

    shape.setOutlineThickness(2.0f);
    shape.setOutlineColor(sf::Color::Black);
    shape.setFillColor(color);

    window.draw(shape);
}
