#ifndef TOOL_H
#define TOOL_H

#include <Point.h>

using namespace pathfinder;

class Tool {

    public:
        void execute();

        virtual void subExecute() = 0;

        void moveTo(const Point newPosition);

        void clickLeftMouseButton();

        virtual void leftMouseAction() = 0;

        void releaseLeftMouseButton();

        void clickRightMouseButton();

        virtual void rightMouseAction() = 0;

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
