/**
 * @brief PriorityQueue
 *
 * Implements priority queue.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <queue>

namespace pathfinder {

    template <typename T> class PriorityQueue {

        public:
            /**
             * @brief Access the top element
             *
             * Access the top element in the priority queue
             *
             * @return reference to top element in the priority queue
             */
            const T& top() const {
                return priorityQueue.top();
            }

            /**
             * @brief Push an element to priority queue
             *
             * Pushes element to priority queue
             *
             * @param element to be pushed to the priority queue
             */
            void push(const T& element) {
                priorityQueue.push(element);
            }

            /**
             * @brief Pop an element from priority queue
             *
             * Removes an element from the priority queue
             */
            void pop() {
                priorityQueue.pop();
            }

            /**
             * @brief Check if priority queue is empty
             * @return true if priority queue is empty
             */
            bool isEmpty() const {
                return priorityQueue.empty();
            }

        private:
            std::priority_queue<T> priorityQueue;

    };

}

#endif
