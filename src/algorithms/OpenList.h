/**
 * @brief OpenList class.
 *
 * OpenList holds ExtendedNodes
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef OPENLIST_H
#define OPENLIST_H

#include <unordered_map>
#include "PriorityQueue.h"
#include "ExtendedNodePointer.h"
#include "ExtendedNode.h"

namespace pathfinder {

    class OpenList {

        public:
            /**
             * @brief initializes OpenList
             */
            OpenList();

            /**
             * @brief Add ExtendedNode into the open list
             *
             * ExtendedNode will be set to be in open list.
             *
             * If added ExtendedNode is already in some other
             * open list or already in this open list, there
             * WILL be some undefined behaviour.
             *
             * @param node to be added
             */
            void add(ExtendedNode& node);

            /**
             * @brief Remove best node from the open list
             *
             * ExtendedNode that is removed, will be set to be
             * removed from the open list
             */
            void removeBestNode();

            /**
             * @brief Get best node from open list
             * @return reference to the best ExtendedNode
             */
            ExtendedNode& getBestNode();

            /**
             * @brief  Check if open list contains ExtendedNode
             *
             * Checks if a specific ExtendedNode is in the open list.
             *
             * @param extendedNode to be searched inside open list
             * @return true if extendedNode is inside open list
             */
            bool contains(const ExtendedNode& extendedNode) const;

            /**
             * @brief Check if open list is empty
             * @return true if there's zero nodes in the open list
             */
            bool isEmpty() const;

            /**
             * @brief Fixes OpenList
             */
            void fixOpenList();

        private:
            PriorityQueue<ExtendedNodePointer> openList;

    };

}

#endif
