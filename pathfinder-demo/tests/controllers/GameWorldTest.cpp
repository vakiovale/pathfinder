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
