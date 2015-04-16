#include "PriorityQueueTest.h"

SCENARIO("Priority queue can be initialized with different types") {

    GIVEN("A PriorityQueue initializsed with ints") {

        pathfinder::PriorityQueue<int> pq;

        WHEN("PriorityQueue has been initialized") {

            THEN("PriorityQueue holds type of ints") {
                REQUIRE(true);
            }
        }

    }


}
