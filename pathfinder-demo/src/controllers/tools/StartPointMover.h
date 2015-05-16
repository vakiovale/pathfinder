#ifndef START_POINT_MOVER_H
#define START_POINT_MOVER_H

#include "PointMover.h"
#include "GameWorld.h"

class StartPointMover : public PointMover {

    public:
        StartPointMover(GameWorld* gameWorld);

        void movePoint();

};

#endif
