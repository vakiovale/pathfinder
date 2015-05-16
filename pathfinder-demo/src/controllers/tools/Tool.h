#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include "TerrainBlock.h"

class Tool {

    public:
        void moveTo(const TerrainBlock* newPosition);

        virtual void hold();

        virtual void click();

        virtual void release();

        virtual void execute();

    protected:
        const TerrainBlock* lastPosition;

        bool justMovedToNewBlock;

};

#endif
