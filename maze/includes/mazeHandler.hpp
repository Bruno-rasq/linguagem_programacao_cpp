#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "./mazeStruct.hpp"
#include "./mazeSolver.hpp"

class MazeHandler {
private:
    std::vector<Maze_T> mazes;
    Maze_T currentMaze;

public:

    MazeHandler();

    void updateCurrentStateMaze(uint16_t x, uint16_t y);
    bool inbounds(uint16_t x, uint16_t y) const;
    void display() const;
    Maze_T getMaze() const;

};