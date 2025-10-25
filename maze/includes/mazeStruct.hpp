#pragma once

#include <cstdint>
#include <vector>

struct Maze_T {
    
    std::vector<std::vector<char>> maze;
    int32_t start_x;
    int32_t start_y;
    int32_t end_x;
    int32_t end_y;

    Maze_T(): start_x(0), start_y(0), end_x(0), end_y(0){}

    Maze_T(
        const std::vector<std::vector<char>>& maze,
        int32_t sx, int32_t sy, int32_t ex, int32_t ey
    ): maze(maze), start_x(sx), start_y(sy), end_x(ex), end_y(ey){}
};