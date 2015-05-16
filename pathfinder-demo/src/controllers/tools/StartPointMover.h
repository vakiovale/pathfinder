#ifndef START_POINT_MOVER_H
#define START_POINT_MOVER_H

#include "Tool.h"
#include "GameWorld.h"

class StartPointMover : public Tool {

    public:
        StartPointMover(GameWorld* gameWorld);

        void subExecute();

        void leftMouseAction();

        void rightMouseAction();

    private:
        GameWorld* gameWorld;

};

#endif
