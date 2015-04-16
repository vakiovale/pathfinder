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
