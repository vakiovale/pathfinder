/**
 * @brief Path class
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef PATH_H
#define PATH_H

#include <vector>
#include "Node.h"

namespace pathfinder {

    class Path {

        private:
            std::vector<Node> path;

        public:
            Path();
            bool pathExists() const;

    };

}

#endif
