/**
 * @brief CompassPosition
 *
 * CompassPosition holds all the 8 compass positions

@author*
 */

#ifndef COMPASS_POSITION_H
#define COMPASS_POSITION_H

namespace pathfinder {

    enum CompassPosition {
        NORTH, EAST, SOUTH, WEST,
        NORTH_EAST, SOUTH_EAST, SOUTH_WEST, NORTH_WEST
    };
}

#endif
