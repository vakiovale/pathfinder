#include "Point.h"

namespace pathfinder {

    Point::Point(int x, int y) : X(x), Y(y) {
        // do nothing else
    }

    int Point::getX() const {
        return X;
    }

    int Point::getY() const {
        return Y;
    }

}
