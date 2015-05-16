#ifndef TOOL_H
#define TOOL_H

#include <iostream>
#include <Point.h>

using namespace pathfinder;

class Tool {

    public:
        virtual void execute();

        void moveTo(const Point newPosition);

        void clickLeftMouseButton();

        void releaseLeftMouseButton();

        void clickRightMouseButton();

        void releaseRightMouseButton();

        void reset();

        bool primaryActionExecutedFirstTime();

    protected:
        Point lastPosition = Point(-1,-1);

        bool justMovedToNewBlock;

        bool holdingLeftMouseButton;

        bool holdingRightMouseButton;

        bool executedPrimaryActionOnce;

        bool executedSecondaryActionOnce;

};

#endif
