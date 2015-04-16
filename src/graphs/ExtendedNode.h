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
             * @brief Get a reference to binded Node
             * @return reference to binded node
             */
            const Node& getNode();

        private:
            const Node* node; /*< binded node */

    };

}

#endif
