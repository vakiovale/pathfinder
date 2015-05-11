# pathfinder demo
Demo program for visualizing path finding

* <a href="#building-pathfinder-demo">Building PathFinder demo</a>
* <a href="#installing-sfml">Installing SFML</a>
* <a href="#playing-pathfinder-demo">Playing PathFinder Demo</a>

<img src="https://github.com/valtteripyyhtia/pathfinder/blob/master/dokumentit/images/pathfinder-basic-01.png?raw=true" alt="Finding shortest path" width="400px" />

## Building PathFinder demo

1. Check that PathFinder library has been installed (<a href="https://github.com/valtteripyyhtia/pathfinder#installing-pathfinder-library">instructions here</a>)
2. <a href="#installing-sfml">Installing SFML library</a>
3. Run these scripts from <code>pathfinder-demo/</directory>: <code>./runcmake</code> and <code>./build</code>

## Installing SFML

Installing SFML locally to the <code>pathfinder-demo/SFML/</code> directory is easy with the <code>installSFML</code> script inside <code>pathfinder-demo/</code> directory.

SFML library has some dependencies that needs to be installed. Dependencies can be checked from SFML's tutorial <a href="http://www.sfml-dev.org/tutorials/2.3/compile-with-cmake.php#installing-dependencies">here.</a>

Running <code>./installSFML</code> downloads SFML version 2.3 and installs it inside <code>pathfinder-demo/</code> directory.

## Playing PathFinder Demo

After successful installation you can start pathfinding with <code>./run</code> script inside <code>pathfinder-demo/</code> directory. Happy path finding!
