#ifndef BLOCK_GRAPH_H
#define BLOCK_GRAPH_H

#include <Graph.h>

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
         * @brief Get width of the graph.
         * @return width of the graph
         */
        int getWidth() const;

        /**
         * @brief Get height of the graph.
         * @return height of the graph
         */
        int getHeight() const;

    private:
        int width;
        int height;

};

#endif
