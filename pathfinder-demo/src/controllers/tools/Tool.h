/**
 * @brief Tool
 *
 * Tool is used for creating different kind of Tool objects.
 * Tool's execution actions can be modified.
 *
 * @author Valtteri Pyyhtiä
 */

#ifndef TOOL_H
#define TOOL_H

#include <Point.h>

using namespace pathfinder;

class Tool {

    public:
        /**
         * @brief Execute tool's actions
         */
        void execute();

        /**
         * @brief subExecute will be executed by execute() function
         */
        virtual void subExecute() = 0;

        /**
         * @brief Move tool to new position
         * @param newPosition of the tool
         */
        void moveTo(const Point newPosition);

        /**
         * @brief Left mouse button has been clicked
         */
        void clickLeftMouseButton();

        /**
         * @brief Left mouse button action will be executed
         * by clickLeftMouseButton() function
         */
        virtual void leftMouseAction() = 0;

        /**
         * @brief Releases left mouse button
         */
        void releaseLeftMouseButton();

        /**
         * @brief Right mouse button has been clicked
         */
        void clickRightMouseButton();

        /**
         * @brief Right mouse button action will be executed
         * by clickRightMouseButton() function
         */
        virtual void rightMouseAction() = 0;

        /**
         * @brief Releases right mouse button
         */
        void releaseRightMouseButton();

        /**
         * @brief Reset object
         */
        void reset();

        /**
         * @brief Check if primary action has been executed for the first time
         *
         * @return true if action has been executed only once, false if this
         * function has been called before
         */
        bool primaryActionExecutedFirstTime();

    protected:
        Point lastPosition = Point(-1,-1);

        bool justMovedToNewBlock;

        bool holdingLeftMouseButton;

        bool holdingRightMouseButton;

        bool executedPrimaryActionOnce;

        bool executedSecondaryActionOnce;

};

#endif
