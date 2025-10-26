#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <utility>

class MazeHandler;

namespace MazeResolvers {

    struct Path {
        int32_t x, y;

        Path();
        Path(int32_t x, int32_t y);
    };

    typedef std::vector<std::vector<bool>> SET;
    typedef std::vector<std::vector<Path>> PARENTS;
    typedef std::queue<Path> QUEUE;
    typedef std::vector<std::pair<int, int>> DELTA;

    const DELTA delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS -> busca em largura
    std::vector<Path> BFS(MazeHandler& maze);
};