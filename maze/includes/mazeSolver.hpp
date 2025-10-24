#pragma once

#include <vector>
#include <cstdint>
#include <queue>
#include <algorithm>

#include "./mazeHandler.hpp"
#include "./mazeStruct.hpp"

struct PathCoord {
    uint16_t x, y;

    PathCoord(): x(0), y(0){}
    PathCoord(uint16_t x, uint16_t y): x(x), y(y){}
};

typedef std::vector<std::vector<bool>> SET;
typedef std::vector<std::vector<PathCoord>> PARENTS;
typedef std::queue<PathCoord> QUEUE;

const std::vector<PathCoord> delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class MazeSolver {
public:
    // executa uma BFS para achar o menor caminho.
    static std::vector<PathCoord> getShortestPath(const MazeHandler& maze);
};