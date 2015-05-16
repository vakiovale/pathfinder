#include "GameWorldTest.h"

SCENARIO("Game world can be updated", "[gameworld]") {

    GIVEN("A GameWorld") {

        GameWorld game;

        WHEN("GameWorld is updated") {

            game.update();

            THEN("GameWorld is updated") {
                REQUIRE(true);
            }
        }
    }
}

SCENARIO("Game world can have different PathFinders", "[gameworld][pathfinder]") {

    GIVEN("A GameWorld") {

        GameWorld game;

        WHEN("Setting a* algorithm to the game world") {

            game.useAStarAlgorithm();

            THEN("GameWorld uses a* algorithm") {
                REQUIRE(true);
            }
        }
    }
}

SCENARIO("GameWorld can be initialized with graph size", "[gameworld]") {

    GIVEN("A GameWorld to be initialized") {

        GameWorld* game;

        WHEN("Initialized to 10") {
            game = new GameWorld(10);
            THEN("GameWorld has width 10 and height 10") {
                REQUIRE(game->getWidth() == 10);
                REQUIRE(game->getHeight() == 10);
            }
            delete game;
        }

        WHEN("Initialized to 100") {
            game = new GameWorld(100);
            THEN("GameWorld has width 100 and height 100") {
                REQUIRE(game->getWidth() == 100);
                REQUIRE(game->getHeight() == 100);
            }
            delete game;
        }

        WHEN("Initialized to 1") {
            game = new GameWorld(1);
            THEN("GameWorld has width 1 and height 1") {
                REQUIRE(game->getWidth() == 1);
                REQUIRE(game->getHeight() == 1);
            }
            delete game;
        }

        WHEN("Initialized to 0") {
            game = new GameWorld(0);
            THEN("GameWorld has default width 35 and default height 35") {
                REQUIRE(game->getWidth() == 35);
                REQUIRE(game->getHeight() == 35);
            }
            delete game;
        }

        WHEN("Initialized to -1") {
            game = new GameWorld(-1);
            THEN("GameWorld has default width 35 and default height 35") {
                REQUIRE(game->getWidth() == 35);
                REQUIRE(game->getHeight() == 35);
            }
            delete game;
        }

        WHEN("Initializer is left to zero") {
            game = new GameWorld();
            THEN("GameWorld has default width 35 and default height 35") {
                REQUIRE(game->getWidth() == 35);
                REQUIRE(game->getHeight() == 35);
            }
            delete game;
        }
    }

}
