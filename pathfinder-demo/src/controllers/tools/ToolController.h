#ifndef TOOL_CONTROLLER_H
#define TOOL_CONTROLLER_H

#include "Tool.h"
#include "BuildTool.h"
#include "TerrainBlock.h"

class ToolController {

    public:
        ToolController();

        ~ToolController();

        void update(const TerrainBlock* terrainBlock);

    private:
        BuildTool* buildTool;

        void initializeTools();

};

#endif
