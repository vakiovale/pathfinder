/**
 * @brief ExtendedNode class.
 *
 * ExtendedNode holds a pointer to another Node and holds
 * specific node data to use in pathfinding.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef EXTENDED_NODE_H
#define EXTENDED_NODE_H

#include <limits>
#include "Node.h"

namespace pathfinder {

    class ExtendedNode {

        public:
            /**
             * @brief ExtendedNode
             *
             * Binds a Node to this ExtendedNode
             *
             * @param node to be binded
             */
            ExtendedNode(const Node* node);

            /**
             * @brief Get reference to binded Node
             * @return reference to binded node
             */
            const Node& getNode() const;

            /**
             * @brief operator ==
             * @param lhs
             * @param rhs
             * @return true if inner Nodes are equal
             */
            friend bool operator==(const ExtendedNode& lhs,
                                   const ExtendedNode& rhs);

            /**
             * @brief operator !=
             * @param lhs
             * @param rhs
             * @return true if inner Nodes are not equal
             */
            friend bool operator!=(const ExtendedNode& lhs,
                                   const ExtendedNode& rhs);

            /**
             * @brief Compare two ExtendedNodes
             *
             * Less than operator returns true if total cost
             * is greater than other ExtendedNode's total cost
             *
             * @param node to be compared
             * @return true if total cost is greater
             */
            bool operator<(const ExtendedNode& node) const;

            /**
             * @brief Get total cost
             *
             * Total cost is a calculated estimation from this node
             * to the end node.
             *
             * @return total cost
             */
            float getTotalCost() const;

            /**
             * @brief Set total cost to new value
             * @param new total cost
             */
            void setTotalCost(float totalCost);

            /**
             * @brief Get current cost
             *
             * Current cost is cost that has been wasted coming to this Node.
             *
             * @return current cost
             */
            float getCurrentCost() const;

            /**
             * @brief Set current cost to new value
             * @param new current cost
             */
            void setCurrentCost(float currentCost);

            /**
             * @brief Check if node is set to be in open list
             * @return true if node has been set to be in open list
             */
            bool isInOpenList() const;

            /**
             * @brief Set node to be in open list
             *
             * After calling this, isInOpenList() will return true
             */
            void setNodeToOpenList();

            /**
             * @brief Set node to be removed from open list
             *
             * After calling this, isInOpenList() will return false
             */
            void setNodeRemovedFromOpenList();

            /**
             * @brief Check if node is set to be in closed list
             * @return true if node has been set to be in closed list
             */
            bool isInClosedList() const;

            /**
             * @brief Set node to be in closed list
             *
             * After calling this, isInClosedList() will return true
             */
            void setNodeToClosedList();

            /**
             * @brief Set node to be removed from closed list
             *
             * After calling this, isInClosedList() will return false
             */
            void setNodeRemovedFromClosedList();

        private:
            const Node* node; /*< binded node */

            float totalCost; /*< estimated total cost to the end node */
            float currentCost; /*< current cost that's wasted coming to this node */

            bool nodeIsInOpenList; /*< flag to tell if node is in open list */
            bool nodeIsInClosedList; /*< flag to tell if node is in closed list */

    };

}

#endif
