#include "main.h"

int main() {
    graph.create2DGridMap(NUMBER_OF_NODES_IN_A_ROW);
    graph.getNodeFromPosition(12, 11)->setAccessible(false);
    graph.getNodeFromPosition(3, 6)->setAccessible(false);

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        draw();

        window.display();
    }
    
    return 0;
}

void draw() {
    for(int i = 0; i < NUMBER_OF_NODES_IN_A_ROW; i++) {
        for(int j = 0; j < NUMBER_OF_NODES_IN_A_ROW; j++) {
            Node* node = graph.getNodeFromPosition(j,i);
            int x = node->getX();
            int y = node->getY();

            sf::RectangleShape shape(sf::Vector2f(BLOCK_WIDTH, BLOCK_HEIGHT));
            shape.setOrigin(sf::Vector2f(-x*BLOCK_WIDTH, -y*BLOCK_HEIGHT));

            shape.setOutlineThickness(2.0f);

            shape.setOutlineColor(sf::Color::Black);

            if(node->isAccessible()) {
                shape.setFillColor(sf::Color::White);
            }
            else {
                shape.setFillColor(gray);
            }

            window.draw(shape);
        }
    }
}
