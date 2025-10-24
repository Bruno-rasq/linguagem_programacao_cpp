#pragma once

#include <cstdint>
#include <vector>

struct Maze_T {
    
    std::vector<std::vector<char>> maze;
    uint16_t start_x;
    uint16_t end_x;
    uint16_t start_y;
    uint16_t end_y;

    Maze_T(): start_x(0), start_y(0), end_x(0), end_y(0){}

    Maze_T(
        const std::vector<std::vector<char>>& maze,
        uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey
    ): maze(maze), start_x(sx), start_y(sy), end_x(ex), end_y(ey){}
};