#ifndef POINT_MOVER_H
#define POINT_MOVER_H

#include "Tool.h"
#include "GameWorld.h"

class PointMover : public Tool {

    public:
        PointMover(GameWorld* gameWorld);

        void subExecute();

        virtual void movePoint() = 0;
        virtual void leftMouseAction();
        virtual void rightMouseAction();

    protected:
        GameWorld* gameWorld;

};

#endif
