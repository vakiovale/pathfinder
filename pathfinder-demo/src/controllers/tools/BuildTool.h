/**
 * @brief BuildTool is used for adding/removing different
 * kind of TerrainBlocks to the game world
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef BUILD_TOOL_H
#define BUILD_TOOL_H

#include "Tool.h"
#include "Terrain.h"
#include "GameWorld.h"
#include "Point.h"

class BuildTool : public Tool {

    public:
        BuildTool(GameWorld* gameWorld, const Point& currentPosition);

        void execute();

        void subExecute();

        void leftMouseAction();

        void rightMouseAction();

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

        bool toolIsOnSameTerrainAsTerrainToUse();

        void erase();

        void paint();

        void checkEraseMode();

};

#endif
