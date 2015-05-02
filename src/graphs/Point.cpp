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

    bool operator==(const Point& lhs, const Point& rhs) {
        return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
    }

    bool operator!=(const Point& lhs, const Point& rhs) {
        return !(lhs == rhs);
    }

}
