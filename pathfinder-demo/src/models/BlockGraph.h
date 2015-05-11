#ifndef BLOCK_GRAPH_H
#define BLOCK_GRAPH_H

#include <Graph.h>
#include <vector>
#include "TerrainBlock.h"
#include "Terrain.h"

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
         * @param x position
         * @param y position
         * @return terrain of the block
         */
        Terrain getTerrainInPosition(int x, int y) const;

    private:
        std::vector<std::vector<TerrainBlock*>> blocks;
        int width;
        int height;

        void initializeGraph(int graphSize);
        void initializeBlocks();

};

#endif
