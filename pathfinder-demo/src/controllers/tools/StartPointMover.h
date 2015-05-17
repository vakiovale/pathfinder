#ifndef START_POINT_MOVER_H
#define START_POINT_MOVER_H

#include <Point.h>
#include "Tool.h"
#include "GameWorld.h"

class StartPointMover : public Tool {

    public:
        StartPointMover(GameWorld* gameWorld, const Point& currentPosition);

        void subExecute();

        void leftMouseAction();

        void rightMouseAction();

    private:
        GameWorld* gameWorld;

};

#endif
