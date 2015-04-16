#include "PriorityQueueTest.h"

SCENARIO("Priority queue can be initialized with different types",
         "[priorityqueue]") {

    GIVEN("A PriorityQueue to be initialized") {

        WHEN("PriorityQueue is initialized with ints") {

            pathfinder::PriorityQueue<int> pq;

            THEN("PriorityQueue holds type of ints") {
                REQUIRE(true);
            }
        }

        WHEN("PriorityQueue is initialized with Nodes") {

            pathfinder::PriorityQueue<pathfinder::Node> pq;

            THEN("PriorityQueue holds type of Nodes") {
                REQUIRE(true);
            }
        }

    }
}

SCENARIO("Elements can be pushed and popped to priority queue",
         "[priorityqueue]") {

    GIVEN("A PriorityQueue initialized with ints") {

        pathfinder::PriorityQueue<int> pq;

        WHEN("2 is pushed to PriorityQueue") {

            pq.push(2);

            THEN("2 is top of the PriorityQueue") {
                REQUIRE(pq.top() == 2);
            }

        }

    }

}
