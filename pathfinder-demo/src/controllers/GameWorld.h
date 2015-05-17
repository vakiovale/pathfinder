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

#include <random>
#include <iostream>
#include <cmath>

#include <Node.h>
#include <Point.h>
#include <BlockGraph.h>
#include <PathFinder.h>
#include <AStarPathFinder.h>
#include "DemoConfigurations.h"

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

        /**
         * @brief Get BlockGraph
         * @return graph
         */
        BlockGraph* getBlockGraph();

        /**
         * @brief Create random walls
         */
        void createRandomWalls();

        /**
         * @brief Toggle moving on and off
         */
        void toggleMoving();

        const Point& getStartPoint() const;

        const Point& getEndPoint() const;

        void moveStartTo(const Point& point);

        void moveEndTo(const Point& point);

        void increaseMovementSpeed();

        void decreaseMovementSpeed();

        const Path& getPath() const;

    private:
        BlockGraph* graph;

        int startMovingSpeed = START_MOVING_SPEED;

        int movingSpeed;

        int width;

        int height;

        PathFinder* pathFinder;

        Point start = Point(-1,-1);

        Point end = Point(-1,-1);

        Path* finalPath;

        bool movingEnabled;

        bool startAndEndNodesExistInGraph() const;

        void findShortestPath();

        void moveAlongThePathIfNodeIsAccessible();
};

#endif
