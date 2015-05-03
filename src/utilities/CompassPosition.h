/**
 * @brief CompassPosition
 *
 * CompassPosition holds all the 8 compass positions from North to North west

@author*
 */

#ifndef COMPASS_POSITION_H
#define COMPASS_POSITION_H

namespace pathfinder {

    enum CompassPosition {
        NORTH, NORTH_EAST, EAST, SOUTH_EAST,
        SOUTH, SOUTH_WEST, WEST, NORTH_WEST
    };
}

#endif
