#ifndef TOOL_CONTROLLER_H
#define TOOL_CONTROLLER_H

#include "Tool.h"
#include "BuildTool.h"
#include "Point.h"
#include "GameWorld.h"

class ToolController {

    public:
        ToolController(GameWorld* gameWorld);

        ~ToolController();

        void update(const Point& point);

    private:
        GameWorld* gameWorld;

        BuildTool* buildTool;

        void initializeTools();

};

#endif
