#ifndef END_POINT_MOVER_H
#define END_POINT_MOVER_H

#include "PointMover.h"
#include "GameWorld.h"

class EndPointMover : public PointMover {

    public:
        EndPointMover(GameWorld* gameWorld);

        void movePoint();

};

#endif
