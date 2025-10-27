#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include <algorithm>
#include <utility>

#include "./mazeHandler.hpp"


namespace MazeResolvers {

    typedef std::vector<std::vector<bool>> SET;
    typedef std::vector<std::vector<MazeHandler::Coord>> PARENTS;
    typedef std::queue<MazeHandler::Coord> QUEUE;
    typedef std::vector<std::pair<int, int>> DELTA;
    typedef std::vector<MazeHandler::Coord> COORDS;

    const DELTA delta = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // BFS -> busca em largura
    COORDS BFS(const MazeHandler::Maze& maze);
};