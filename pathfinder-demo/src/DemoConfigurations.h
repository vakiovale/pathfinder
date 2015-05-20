#ifndef DEMO_CONFIGURATIONS_H
#define DEMO_CONFIGURATIONS_H

/** CONFIGURATIONS */
const int NUMBER_OF_NODES_IN_A_ROW = 50;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const bool RANDOM_WALLS = false;
const int START_MOVING_SPEED = 5;
const bool PRINT_PATH_FINDER_TIME = false;
const bool DISPLAY_PATH = true;
const bool SLOW_DOWN_MOVEMENT_BY_COST_FACTOR = false;
/** ************** */

/** PLEASE, DON'T TOUCH HERE */
const int NUMBER_OF_NODES_IN_A_COLUMN = NUMBER_OF_NODES_IN_A_ROW;
const float BLOCK_WIDTH = WINDOW_WIDTH / (float)NUMBER_OF_NODES_IN_A_ROW;
const float BLOCK_HEIGHT = WINDOW_HEIGHT / (float)NUMBER_OF_NODES_IN_A_COLUMN;
/** ************************ */

#endif
