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
                length = priorityQueue.size();
                priorityQueue.push_back(element);
                checkHeapRuleBetweenIndexAndParent(length);
            }

            /**
             * @brief Pop an element from priority queue
             *
             * Removes an element from the priority queue
             */
            void pop() {
                length = priorityQueue.size();

                if(length > 0) {
                    priorityQueue[0] = priorityQueue[length-1];
                    priorityQueue.pop_back();
                    checkHeapRuleBetweenIndexAndChildren(0);
                }
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
                heapify();
            }

        private:
            std::vector<T> priorityQueue;

            int length;
            int leftChild;
            int rightChild;

            void checkHeapRuleBetweenIndexAndParent(int index) {
                if(index == 0) return;
                int parentIndex = getParentIndex(index);

                if(priorityQueue[parentIndex] < priorityQueue[index]) {
                    swap(parentIndex, index);
                    checkHeapRuleBetweenIndexAndParent(parentIndex);
                }
            }

            int getParentIndex(int index) {
                return (index-1)/2;
            }

            void swap(int index1, int index2) {
                T tmp = priorityQueue[index1];
                priorityQueue[index1] = priorityQueue[index2];
                priorityQueue[index2] = tmp;
            }

            void checkHeapRuleBetweenIndexAndChildren(int index) {
                updateSizeAndChildIndexes(index);

                if(leftChildIsOutOfBounds()) return;

                int greaterChildIndex = getIndexOfGreaterValue(index, leftChild);

                if(!rightChildIsOutOfBounds()) {
                    greaterChildIndex =
                            getIndexOfGreaterValue(greaterChildIndex,
                                                   rightChild);
                }

                if(greaterChildIndex != index) {
                    swap(index, greaterChildIndex);
                    checkHeapRuleBetweenIndexAndChildren(greaterChildIndex);
                }
            }

            void updateSizeAndChildIndexes(int index) {
                length = priorityQueue.size();
                leftChild = getLeftChildIndex(index);
                rightChild = getRightChildIndex(index);
            }

            bool leftChildIsOutOfBounds() const {
                return leftChild >= length;
            }

            bool rightChildIsOutOfBounds() const {
                return rightChild >= length;
            }

            int getLeftChildIndex(int index) {
                return 2*index + 1;
            }

            int getRightChildIndex(int index) {
                return 2*index + 2;
            }

            int getIndexOfGreaterValue(int index1, int index2) {
                return priorityQueue[index1] < priorityQueue[index2] ?
                            index2 : index1;
            }

            void heapify() {
                for(int i = priorityQueue.size()-1; i >= 0; i--) {
                    checkHeapRuleBetweenIndexAndChildren(i);
                }
            }

    };

}

#endif
