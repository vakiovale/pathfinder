#ifndef END_POINT_MOVER_H
#define END_POINT_MOVER_H

#include <Point.h>
#include "Tool.h"
#include "GameWorld.h"

class EndPointMover : public Tool {

    public:
        EndPointMover(GameWorld* gameWorld, const Point& currentPosition);

        void subExecute();

        void leftMouseAction();

        void rightMouseAction();

    private:
        GameWorld* gameWorld;

};

#endif
