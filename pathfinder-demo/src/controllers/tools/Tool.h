#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <Point.h>

using namespace pathfinder;

class Tool {

    public:
        void moveTo(const Point newPosition);

        void hold();

        void click();

        void release();

        void execute();

    protected:
        Point lastPosition = Point(0,0);

        bool justMovedToNewBlock;

};

#endif
