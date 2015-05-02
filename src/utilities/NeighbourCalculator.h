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
