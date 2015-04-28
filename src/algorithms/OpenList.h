/**
 * @brief OpenList class.
 *
 * OpenList holds ExtendedNodes
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef OPENLIST_H
#define OPENLIST_H

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
             * @brief Check if open list is empty
             * @return true if there's zero nodes in the open list
             */
            bool isEmpty() const;

        private:
            PriorityQueue<ExtendedNodePointer> openList;

    };

}

#endif
