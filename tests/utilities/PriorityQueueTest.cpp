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

        WHEN("PriorityQueue is initialized with strings") {

            pathfinder::PriorityQueue<std::string> pq;

            THEN("PriorityQueue holds type of strings") {
                REQUIRE(true);
            }
        }
    }

}

SCENARIO("Elements can be pushed and popped to/from priority queue",
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

        WHEN("Adding 2, -1, 2, 4, 0, 7, 1, 2, 8, 5, 7, 3, -1, 0 to PriorityQueue") {
            pq.push(2);
            pq.push(-1);
            pq.push(2);
            pq.push(4);
            pq.push(0);
            pq.push(7);
            pq.push(1);
            pq.push(2);
            pq.push(8);
            pq.push(5);
            pq.push(7);
            pq.push(3);
            pq.push(-1);
            pq.push(0);

            THEN("Elements should be removed starting with the greatest int") {
                REQUIRE(pq.top() == 8);
                pq.pop();
                REQUIRE(pq.top() == 7);
                pq.pop();
                REQUIRE(pq.top() == 7);
                pq.pop();
                REQUIRE(pq.top() == 5);
                pq.pop();
                REQUIRE(pq.top() == 4);
                pq.pop();
                REQUIRE(pq.top() == 3);
                pq.pop();
                REQUIRE(pq.top() == 2);
                pq.pop();
                REQUIRE(pq.top() == 2);
                pq.pop();
                REQUIRE(pq.top() == 2);
                pq.pop();
                REQUIRE(pq.top() == 1);
                pq.pop();
                REQUIRE(pq.top() == 0);
                pq.pop();
                REQUIRE(pq.top() == 0);
                pq.pop();
                REQUIRE(pq.top() == -1);
                pq.pop();
                REQUIRE(pq.top() == -1);
                pq.pop();
            }
        }
    }
}

SCENARIO("Element in top of the PriorityQueue is always greatest",
         "[priorityqueue]") {

    GIVEN("PriorityQueue of ints") {

        pathfinder::PriorityQueue<int> pq;

        WHEN("Adding 3, 1 and 2 to PriorityQueue") {
            pq.push(3);
            pq.push(1);
            pq.push(2);

            THEN("Top element is 3") {
                REQUIRE(pq.top() == 3);
            }

            AND_WHEN("Removing top element") {

                pq.pop();

                THEN("Top element is 2") {
                    REQUIRE(pq.top() == 2);
                }

                AND_WHEN("Removing last element from the top") {

                    pq.pop();

                    THEN("Top element is 1") {
                        REQUIRE(pq.top() == 1);
                    }
                }
            }
        }

        WHEN("Adding 4, 2, 4, 2 to PriorityQueue") {
            pq.push(4);
            pq.push(2);
            pq.push(4);
            pq.push(2);

            THEN("Top element is 4") {
                REQUIRE(pq.top() == 4);
            }

            AND_WHEN("Adding 6 to PriorityQueue") {
                pq.push(6);

                THEN("Top element is 6") {
                    REQUIRE(pq.top() == 6);
                }

                AND_WHEN("Removing two elements from the top") {
                    pq.pop();
                    pq.pop();

                    THEN("Top element is 4") {
                        REQUIRE(pq.top() == 4);
                    }

                    AND_WHEN("Adding 3 to PriorityQueue") {
                        pq.push(3);

                        THEN("Top element is 4") {
                            REQUIRE(pq.top() == 4);
                        }

                        AND_WHEN("Removing top element") {
                            pq.pop();

                            THEN("Top element is 3") {
                                REQUIRE(pq.top() == 3);
                            }
                        }
                    }
                }

            }

            AND_WHEN("Removing two elements from the top") {
                pq.pop();
                pq.pop();

                THEN("Top element is 2") {
                    REQUIRE(pq.top() == 2);
                }

                AND_WHEN("Adding 7 and 4 to PriorityQueue and removing one "
                         "element from the top") {
                    pq.push(7);
                    pq.push(4);
                    pq.pop();

                    THEN("Top element is 4") {
                        REQUIRE(pq.top() == 4);
                    }
                }
            }

            AND_WHEN("Adding 100 to PriorityQueue") {
                pq.push(100);

                THEN("Top element is 100") {
                    REQUIRE(pq.top() == 100);
                }

                AND_WHEN("Adding 20 to PriorityQueue") {
                    pq.push(20);

                    THEN("Top element is 100") {
                        REQUIRE(pq.top() == 100);
                    }

                    AND_WHEN("Adding 80 to PriorityQueue") {
                        pq.push(80);

                        THEN("Top element is 100") {
                            REQUIRE(pq.top() == 100);
                        }

                        AND_WHEN("Adding 60 to PriorityQueue") {
                            pq.push(60);

                            THEN("Top element is 100") {
                                REQUIRE(pq.top() == 100);
                            }

                            AND_WHEN("Removing top element") {
                                pq.pop();

                                THEN("Top element is 80") {
                                    REQUIRE(pq.top() == 80);
                                }

                                AND_WHEN("Removing 4 elements") {
                                    pq.pop();
                                    pq.pop();
                                    pq.pop();
                                    pq.pop();

                                    THEN("Top element is 4") {
                                        REQUIRE(pq.top() == 4);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

SCENARIO("Elements in PriorityQueue can be updated", "[priorityqueue]") {

    GIVEN("PriorityQueue with three PointerInt (1, 3, 2)") {

        // Creating three PointerInts:

        // First
        PointerInt firstInt;
        int firstValue = 1;
        firstInt.value = &firstValue;

        // Second
        PointerInt secondInt;
        int secondValue = 3;
        secondInt.value = &secondValue;

        // Third
        PointerInt thirdInt;
        int thirdValue = 2;
        thirdInt.value = &thirdValue;

        pathfinder::PriorityQueue<PointerInt> pq;

        pq.push(firstInt);
        pq.push(secondInt);
        pq.push(thirdInt);

        WHEN("Nothing is done") {

            THEN("Top element points to second pushed integer (3)") {
                REQUIRE(*(pq.top().value) == secondValue);
            }

            AND_WHEN("First value will be changed from 1 -> 4 and PriorityQueue "
                     "will be updated") {

                firstValue = 4;
                pq.update();

                THEN("Top element now points to first pushed integer "
                     "(changed from 1 -> 4)") {
                    REQUIRE(*(pq.top().value) == firstValue);
                }
            }

        }



    }

}
