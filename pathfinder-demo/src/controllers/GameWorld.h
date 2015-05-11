/**
 * @brief GameWorld
 *
 * GameWorld which controls the path finder demo
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include "Updateable.h"

class GameWorld : public Updateable {

    public:
        /**
         * @brief Initializes GameWorld
         */
        GameWorld();

        /**
         * @brief Updates GameWorld
         */
        void update();
};

#endif
