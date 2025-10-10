#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "../src/gridCollections.cpp"

class Grid {
private:
    GridCollections::Board board;

public:
    Grid();

    void printGridState();
    void setRobotCoord(int x, int y);
    void clearPrevRobotCoord(int x, int y);

    GridCollections::Board getGridState() const;

};

#endif