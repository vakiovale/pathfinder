#ifndef NODE_TEST_H
#define NODE_TEST_H

#include "catch.hpp"
#include "Node.h"

/**
 * @brief Check if constructor throws an exception
 *
 * Give coordinates x and y and this function will create a Node
 * with these parameters. If constructor throws an invalid_argument exception,
 * function returns true.
 *
 * @param x coordinate for the Node
 * @param y coordinate for the Node
 * @return true if invalid_argument exception is thrown
 */
bool checkIfNodeConstructorThrowsAnException(int x, int y);

#endif
