#include "NeighbourCalculator.h"

namespace pathfinder {

    NeighbourCalculator::NeighbourCalculator(int x, int y) {
        this->x = x;
        this->y = y;
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

}
