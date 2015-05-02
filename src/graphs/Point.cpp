#include "Point.h"

namespace pathfinder {

    Point::Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int Point::getX() const {
        return x;
    }

    int Point::getY() const {
        return y;
    }

}
