/**
 * @brief Point class.
 *
 * Point has x and y coordinates.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef POINT_H
#define POINT_H

namespace pathfinder {

    class Point {

        public:
            /**
             * @brief Point
             *
             * Initializes Point's x and y coordinates
             *
             * @param x coordinate
             * @param y coordinate
             */
            Point(int x, int y);

            /**
             * @brief Get x coordinate
             * @return x coordinate
             */
            int getX() const;

            /**
             * @brief Get y coordinate
             * @return y coordinate
             */
            int getY() const;

            /**
             * @brief Compare two Points
             *
             * Two point are equal if the x and y coordinates are the same
             *
             * @param lhs
             * @param rhs
             * @return true if equal
             */
            friend bool operator==(const Point& lhs, const Point& rhs);

            /**
             * @brief Compare two Points
             *
             * Two point are not equal if the x and y coordinates are the same
             *
             * @param lhs
             * @param rhs
             * @return true if not equal
             */
            friend bool operator!=(const Point& lhs, const Point& rhs);

        private:
            int x;
            int y;

    };

}

#endif
