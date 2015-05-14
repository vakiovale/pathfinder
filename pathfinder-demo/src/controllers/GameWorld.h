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

#include <BlockGraph.h>
#include <PathFinder.h>
#include <AStarPathFinder.h>

using namespace pathfinder;

class GameWorld : public Updateable {

    public:
        /**
         * @brief Initializes GameWorld
         *
         * Initializes graph and sets A* as default path finder algorithm
         *
         * @param graphSize to be used in the GameWorld. Minimum width and
         * length of the graph is 1. If graphSize is lower than 1, then default
         * 35 is used as graph size.
         */
        GameWorld(int graphSize = 35);

        /**
         * @brief GameWorld destructor
         */
        ~GameWorld();

        /**
         * @brief Updates GameWorld
         */
        void update();

        /**
         * @brief Set A* algorithm to be used in path finding
         */
        void useAStarAlgorithm();

        /**
         * @brief Get width of the game world
         * @return width of the game world
         */
        int getWidth() const;

        /**
         * @brief Get height of the game world
         * @return height of the game world
         */
        int getHeight() const;

    private:
        BlockGraph graph;

        int width;

        int height;

        PathFinder* pathFinder;
};

#endif
