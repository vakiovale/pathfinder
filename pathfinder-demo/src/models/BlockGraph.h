/**
 * @brief BlockGraph class
 *
 * BlockGraph extends Graph and holds information of all the different
 * TerrainBlocks in every Node.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef BLOCK_GRAPH_H
#define BLOCK_GRAPH_H

#include <Graph.h>
#include <Point.h>
#include <vector>
#include <iostream>

#include "TerrainBlock.h"
#include "Terrain.h"

#include "WallBlock.h"
#include "PlainBlock.h"
#include "GrassBlock.h"
#include "WaterBlock.h"

class BlockGraph : public pathfinder::Graph {

    public:
        /**
         * @brief BlockGraph constructor
         *
         * @param graphSize sets the size of the graph. Graph size is 35
         * by default if no graphSize is used. Graph size can't be lower than 1.
         */
        BlockGraph(int graphSize = 35);

        /**
         * @brief BlockGraph destructor
         */
        ~BlockGraph();

        /**
         * @brief Get width of the graph.
         * @return width of the graph
         */
        int getWidth() const;

        /**
         * @brief Get height of the graph.
         * @return height of the graph
         */
        int getHeight() const;

        /**
         * @brief Get terrain used in a specific block
         * @param position of the block
         * @return terrain of the block
         */
        Terrain getTerrainInPosition(const pathfinder::Point& position) const;

        /**
         * @brief Get terrain used in a specific block
         * @param x position
         * @param y position
         * @return terrain of the block
         */
        Terrain getTerrainInPosition(int x, int y) const;

        /**
         * @brief Changes terrain of a specific block
         *
         * @param position where the block is
         * @param terrain which will be added to a block
         */
        void changeBlockTerrainInPoint(const pathfinder::Point& position,
                                       Terrain terrain);

        /**
         * @brief Changes terrain of a specific block
         *
         * @param x position
         * @param y position
         * @param terrain which will be added to a block
         */
        void changeBlockTerrainInPoint(int x, int y, Terrain terrain);

        /**
         * @brief Get TerrainBlock in position
         * @param x position
         * @param y position
         * @return pointer to TerrainBlock
         */
        TerrainBlock* getTerrainBlockInPosition(int x, int y);


    private:
        std::vector<std::vector<TerrainBlock*>> blocks;
        int width;
        int height;

        void initializeGraph(int graphSize);
        void initializeBlocks();
        void printTerrainBlockPositions() const;
        void deleteGraph();
        void cleanBlockGraph();

};

#endif
