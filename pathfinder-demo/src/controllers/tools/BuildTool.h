#ifndef BUILD_TOOL_H
#define BUILD_TOOL_H

#include "Tool.h"
#include "Terrain.h"

class BuildTool : public Tool {

    public:
        BuildTool();

        /**
         * @brief Change tool to use new terrain
         * @param terrain to use with this BuildTool
         */
        void changeTerrainTool(Terrain terrain);

        virtual void hold();

        virtual void click();

        virtual void release();

        virtual void execute();

    private:
        Terrain terrainToUse;

};

#endif
