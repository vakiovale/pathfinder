#include "ExtendedNodeGraph.h"

namespace pathfinder {

    ExtendedNodeGraph::ExtendedNodeGraph(Graph* graph) {
        this->graph = graph;
        initializeExtendedGraph();
    }

    void ExtendedNodeGraph::initializeExtendedGraph() {
        std::vector<std::vector<pathfinder::Node>> nodes =
                graph->getAllNodes();

        int numberOfRows = nodes.size();
        for(int i = 0; i < numberOfRows; i++) {

            std::vector<ExtendedNode> rowOfVectors;
            int numberOfColumns = (nodes[i]).size();

            for(int j = 0; j < numberOfColumns; j++) {
                rowOfVectors.push_back(
                            ExtendedNode(
                                graph->getNodeFromPosition(j,i)));
            }
            extendedNodes.push_back(rowOfVectors);
        }
    }

    ExtendedNode& ExtendedNodeGraph::getExtendedNodeInPosition(int x, int y) {
        return extendedNodes[y][x];
    }

    std::vector<ExtendedNode*> ExtendedNodeGraph::getAccessibleNeighboursOfExtendedNode(
            const ExtendedNode& extendedNode) {

        std::vector<ExtendedNode*> neighbours;
        std::vector<Point> neighbourPoints =
                getNeighbourPoints(extendedNode.getNode());

        std::vector<bool> accessibleNonDiagonalNodes;
        for(int i = 0; i < 4; i++) accessibleNonDiagonalNodes.push_back(true);

        for(int i = 0; i < neighbourPoints.size(); ++i) {

            Point& neighbourPoint = neighbourPoints[i];

            if(!pointExistsInGraph(neighbourPoint)) {
                continue;
            }

            ExtendedNode& neighbour = getExtendedNodeFromPoint(neighbourPoint);
            CompassPosition position = CompassPosition(i);

            if(extendedNodeIsAccessible(neighbour, position, accessibleNonDiagonalNodes)) {
                neighbours.push_back(&neighbour);
            }
        }

        return neighbours;
    }

    std::vector<Point> ExtendedNodeGraph::getNeighbourPoints(const Node& node) {
        int x = node.getX();
        int y = node.getY();
        NeighbourCalculator calculator(x, y);
        return calculator.getNeighbourPoints();
    }

    bool ExtendedNodeGraph::pointExistsInGraph(const Point& point) const {
        int x = point.getX();
        int y = point.getY();
        return graph->nodeExistsInPosition(x, y);
    }

    ExtendedNode& ExtendedNodeGraph::getExtendedNodeFromPoint(
            const Point& point) {

        int x = point.getX();
        int y = point.getY();
        return getExtendedNodeInPosition(x,y);
    }

    bool ExtendedNodeGraph::extendedNodeIsAccessible(
            const ExtendedNode& extendedNode,
            CompassPosition position,
            std::vector<bool>& accessibleNonDiagonalNodes) {

        const Node& node = extendedNode.getNode();
        bool accessible = node.isAccessible();

        switch(position) {
            case NORTH:
            case EAST:
            case SOUTH:
            case WEST:
                accessibleNonDiagonalNodes[position] = accessible;
                return accessible;
            case NORTH_EAST:
                if(!accessibleNonDiagonalNodes[NORTH] ||
                   !accessibleNonDiagonalNodes[EAST])
                    return false;
                break;
            case SOUTH_EAST:
                if(!accessibleNonDiagonalNodes[EAST] ||
                   !accessibleNonDiagonalNodes[SOUTH])
                    return false;
                break;
            case SOUTH_WEST:
                if(!accessibleNonDiagonalNodes[WEST] ||
                   !accessibleNonDiagonalNodes[SOUTH])
                    return false;
                break;
            case NORTH_WEST:
                if(!accessibleNonDiagonalNodes[NORTH] ||
                   !accessibleNonDiagonalNodes[WEST])
                    return false;
                break;
            default:
                return false;
        }

        return accessible;
    }

}
