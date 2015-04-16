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
    }
}

SCENARIO("Elements can be pushed and popped to priority queue",
         "[priorityqueue]") {

    GIVEN("An empty PriorityQueue initialized with ints") {

        pathfinder::PriorityQueue<int> pq;

        WHEN("Nothing is done to the priority queue") {

            THEN("PriorityQueue is empty") {
                REQUIRE(pq.isEmpty());
            }

        }

        WHEN("2 is pushed to PriorityQueue") {

            pq.push(2);

            THEN("2 is top of the PriorityQueue") {
                REQUIRE(pq.top() == 2);
            }

            AND_WHEN("An element is popped out of the PriorityQueue") {

                pq.pop();

                THEN("PriorityQueue is empty") {
                    REQUIRE(pq.isEmpty());
                }
            }

        }

        WHEN("3 is pushed to PriorityQueue") {

            pq.push(3);

            THEN("3 is top of the PriorityQueue") {
                REQUIRE(pq.top() == 3);
            }

            AND_WHEN("2 is pushed to the PriorityQueue and an "
                     "element is popped out of the PriorityQueue") {

                pq.push(2);
                pq.pop();

                THEN("PriorityQueue is not empty") {
                    REQUIRE_FALSE(pq.isEmpty());
                }
            }
        }

        WHEN("1 is pushed to PriorityQueue") {

            pq.push(1);

            THEN("1 is top of the PriorityQueue") {
                REQUIRE(pq.top() == 1);
            }

            AND_WHEN("2 is pushed to the PriorityQueue and one "
                     "element is popped out of the PriorityQueue") {

                pq.push(2);
                pq.pop();

                THEN("PriorityQueue is not empty") {
                    REQUIRE_FALSE(pq.isEmpty());
                }
            }
        }

        WHEN("One element is added and one element is removed") {
            pq.push(111);
            pq.pop();

            THEN("PriorityQueue is empty") {
                REQUIRE(pq.isEmpty());
            }
        }
    }

}
