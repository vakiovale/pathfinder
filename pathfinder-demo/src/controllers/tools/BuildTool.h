#ifndef BUILD_TOOL_H
#define BUILD_TOOL_H

#include "Tool.h"
#include "Terrain.h"
#include "GameWorld.h"
#include "Point.h"

class BuildTool : public Tool {

    public:
        BuildTool(GameWorld* gameWorld);

        /**
         * @brief Execute tool action
         */
        void execute();

        void clickLeftMouseButton();

        void clickRightMouseButton();

        /**
         * @brief Change tool to use new terrain
         * @param terrain to use with this BuildTool
         */
        void changeTerrainTool(Terrain terrain);

    private:
        Terrain terrainToUse;

        GameWorld* gameWorld;

        Terrain getTerrainToolIsOn() const;

        bool eraseMode;

        bool primaryActionHasNotBeenExecuted();

        bool toolIsOnSameTerrainAsTerrainToUse();

        void erase();

        void paint();

        void checkEraseMode();

};

#endif