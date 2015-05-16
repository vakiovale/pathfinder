#ifndef POINT_MOVER_H
#define POINT_MOVER_H

#include "Tool.h"
#include "GameWorld.h"

class PointMover : public Tool {

    public:
        PointMover(GameWorld* gameWorld);

        void execute();

        virtual void movePoint();

    protected:
        GameWorld* gameWorld;

};

#endif
