/**
 * @brief NeighbourCalculator
 *
 * NeighbourCalculator calculates X and Y coordinates of the neighbouring
 * positions.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef NEIGHBOUR_CALCULATOR_H
#define NEIGHBOUR_CALCULATOR_H

#include <vector>
#include "Point.h"

namespace pathfinder {

    class NeighbourCalculator {

        public:
            /**
             * @brief NeighbourCalculator
             *
             * Initializes NeighbourCalculator with specific position
             *
             * @param x position
             * @param y position
             */
            NeighbourCalculator(int x, int y);

            /**
             * @brief Get all the 8 neighbours
             *
             * Neighbouring points will be all the 8 neighbours
             * starting from NORTH point and going clockwise
             * to the NORTHWEST point.
             *
             * @return vector of Points
             */
            std::vector<Point> getNeighbourPoints() const;

            int getNorthX() const;
            int getNorthY() const;

            int getSouthX() const;
            int getSouthY() const;

            int getEastX() const;
            int getEastY() const;

            int getWestX() const;
            int getWestY() const;

            int getNorthWestX() const;
            int getNorthWestY() const;

            int getSouthWestX() const;
            int getSouthWestY() const;

            int getNorthEastX() const;
            int getNorthEastY() const;

            int getSouthEastX() const;
            int getSouthEastY() const;

        private:
            int x;
            int y;

    };

}

#endif
