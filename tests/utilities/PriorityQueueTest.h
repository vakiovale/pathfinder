#ifndef PRIORITY_QUEUE_TEST_H
#define PRIORITY_QUEUE_TEST_H

#include "catch.hpp"
#include <string>
#include "PriorityQueue.h"

class PointerInt {

    public:
        int* value;

        bool operator<(const PointerInt& other) const {
            return *(this->value) < *(other.value);
        }

};

#endif
