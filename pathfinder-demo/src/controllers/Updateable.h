/**
 * @brief Updateable interface.
 *
 * Interface for updateable objects
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef UPDATEABLE_H
#define UPDATEABLE_H

class Updateable {

    public:
        /**
         * @brief Update object
         */
        virtual void update() = 0;

};

#endif
