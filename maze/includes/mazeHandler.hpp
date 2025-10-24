#pragma once

#include <vector>
#include "./mazeStruct.hpp"

class MazeHandler {
private:

    std::vector<Maze_T> mazes;
    Maze_T currentMaze;

public:

    MazeHandler();

    void updateCurrentStateMaze() const;
    bool inbounds(uint16_t x, uint16_t y) const;
    void display() const;

};