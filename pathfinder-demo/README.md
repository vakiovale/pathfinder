# pathfinder demo
Demo program for visualizing path finding

* <a href="#how-to-play">How to play</a>
* <a href="#building-pathfinder-demo">Building PathFinder demo</a>
* <a href="#installing-sfml">Installing SFML</a>
* <a href="#playing-pathfinder-demo">Playing PathFinder Demo</a>

## How to play

PathFinder demo starts with start (RED) and end (BLUE) points in opposite corners of the grid. 
Yellow circles will show the shortest path between start and end points. 
Pathfinder is constantly trying to find the shortest path. Grid can have different kind of terrains with
different cost factors. By default, cost factors for different terrains are:

- Plain (*white*) = **1.0**
- Grass (*green*) = **2.0**
- Water (*blue*) = **10.0**
- Wall (*gray*) = **not accessible**

<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfinder-basic-01.png?raw=true" alt="Finding shortest path" width="400px" />

### Controls

There's different controls for changing build tools and moving start/end points.

#### Build tools

Grid can be modified with different kind of tools. Selecting a build tool and 
clicking or holding **left mouse button** will execute tool's action.

Key                   | Tool
----------------------| -----------------
**1**                 | Wall (add/remove)
**2**                 | Grass (add/remove)
**3**                 | Water (add/remove)
**S**                 | Move start point
**E**                 | Move end point
**Left mouse button** | Execute action

#### Start point controls

Start point will try to hunt down the end point. Start point's movement can be controlled.

Key             | Action
----------------|--------------------
**SPACE**       | Start/stop moving
**PageUp**      | Increase movement speed
**PageDown**    | Decrease movement speed
**+**           | Increase movement speed
**-**           | Decrease movement speed
**Mouse wheel** | Increase/decrease movement speed

#### End point controls

End point is being hunted by start point. End point can be controlled by using keyboard.

Key             | Action
----------------|--------------------
**Up**          | Move up 
**Down**        | Move down
**Left**        | Move left
**Right**       | Move right
**Left ctrl**   | Use build tool

## Building PathFinder demo

1. Check that PathFinder library has been installed (<a href="https://github.com/valtteripyyhtia/pathfinder#installing-pathfinder-library">instructions here</a>)
2. Install SFML library using instructions in the "Installing SFML" section <a href="#installing-sfml">below</a>
3. Run these scripts from <code>pathfinder-demo/</code> directory:
  - <code>./runcmake</code>
  - <code>./build</code>

## Installing SFML

Installing SFML locally to the <code>pathfinder-demo/SFML/</code> directory is easy with the <code>installSFML</code> script inside <code>pathfinder-demo/</code> directory.

SFML library has some dependencies that needs to be installed. Dependencies can be checked from SFML's tutorial <a href="http://www.sfml-dev.org/tutorials/2.3/compile-with-cmake.php#installing-dependencies">here.</a>

Running <code>./installSFML</code> downloads SFML version 2.3 and installs it inside <code>pathfinder-demo/</code> directory.

## Playing PathFinder Demo

After successful installation you can start pathfinding with <code>./run</code> script inside <code>pathfinder-demo/</code> directory. Happy path finding!
