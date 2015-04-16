/**
 * @brief PriorityQueue
 *
 * Implements priority queue.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <algorithm>

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
                return priorityQueue.front();
            }

            /**
             * @brief Push an element to priority queue
             *
             * Pushes element to priority queue
             *
             * @param element to be pushed to the priority queue
             */
            void push(const T& element) {
                priorityQueue.push_back(element);
                std::push_heap(priorityQueue.begin(), priorityQueue.end());
            }

            /**
             * @brief Pop an element from priority queue
             *
             * Removes an element from the priority queue
             */
            void pop() {
                std::pop_heap(priorityQueue.begin(), priorityQueue.end());
                priorityQueue.pop_back();
            }

            /**
             * @brief Check if priority queue is empty
             * @return true if priority queue is empty
             */
            bool isEmpty() const {
                return priorityQueue.empty();
            }

            /**
             * @brief Updates PriorityQueue
             *
             * Fixes priority queue by reorganizing its elements
             */
            void update() {
                std::make_heap(priorityQueue.begin(), priorityQueue.end());
            }

        private:
            std::vector<T> priorityQueue;

    };

}

#endif
