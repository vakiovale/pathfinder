#include "Node.h"
#include <iostream>

using namespace pathfinder;

int main() {

    Node node(2,1);
    std::cout << "Demo node (" << node.getX() << "," << node.getY() << ")" << std::endl;
    return 0;

}
