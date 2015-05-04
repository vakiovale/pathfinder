#include "NeighbourCalculator.h"

namespace pathfinder {

    NeighbourCalculator::NeighbourCalculator(int x, int y) {
        this->x = x;
        this->y = y;
    }

    std::vector<Point> NeighbourCalculator::getNeighbourPoints() const {
        std::vector<Point> neighbours;

        neighbours.push_back(Point(getNorthX(), getNorthY()));
        neighbours.push_back(Point(getEastX(), getEastY()));
        neighbours.push_back(Point(getSouthX(), getSouthY()));
        neighbours.push_back(Point(getWestX(), getWestY()));

        neighbours.push_back(Point(getNorthEastX(), getNorthEastY()));
        neighbours.push_back(Point(getSouthEastX(), getSouthEastY()));        
        neighbours.push_back(Point(getSouthWestX(), getSouthWestY()));        
        neighbours.push_back(Point(getNorthWestX(), getNorthWestY()));

        return neighbours;
    }

    int NeighbourCalculator::getNorthX() const {
        return x;
    }

    int NeighbourCalculator::getNorthY() const {
        return y-1;
    }

    int NeighbourCalculator::getSouthX() const {
        return x;
    }

    int NeighbourCalculator::getSouthY() const {
        return y+1;
    }

    int NeighbourCalculator::getEastX() const {
        return x+1;
    }

    int NeighbourCalculator::getEastY() const {
        return y;
    }

    int NeighbourCalculator::getWestX() const {
        return x-1;
    }

    int NeighbourCalculator::getWestY() const {
        return y;
    }

    int NeighbourCalculator::getNorthWestX() const {
        return x-1;
    }

    int NeighbourCalculator::getNorthWestY() const {
        return y-1;
    }

    int NeighbourCalculator::getSouthWestX() const {
        return x-1;
    }

    int NeighbourCalculator::getSouthWestY() const {
        return y+1;
    }

    int NeighbourCalculator::getNorthEastX() const {
        return x+1;
    }

    int NeighbourCalculator::getNorthEastY() const {
        return y-1;
    }

    int NeighbourCalculator::getSouthEastX() const {
        return x+1;
    }

    int NeighbourCalculator::getSouthEastY() const {
        return y+1;
    }

}
