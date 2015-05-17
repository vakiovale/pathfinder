#ifndef TOOL_CONTROLLER_H
#define TOOL_CONTROLLER_H

#include "Tool.h"
#include "Terrain.h"
#include "BuildTool.h"
#include "StartPointMover.h"
#include "EndPointMover.h"
#include "Point.h"
#include "GameWorld.h"

class ToolController {

    public:
        ToolController(GameWorld* gameWorld);

        ~ToolController();

        void update();

        void changeBuildTool(Terrain terrain, const Point& currentPosition);

        void changeStartPointMoverTool(const Point& currentPosition);

        void changeEndPointMoverTool(const Point& currentPosition);

        void mouseMoved(const Point& point);

        void leftMouseButtonPressed();

        void rightMouseButtonPressed();

        void leftMouseButtonReleased();

        void rightMouseButtonReleased();

    private:
        GameWorld* gameWorld;

        Tool* tool;

        void initializeTools();

};

#endif
