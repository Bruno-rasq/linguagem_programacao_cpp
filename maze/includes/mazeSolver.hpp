#pragma once

#include <utility>
#include <vector>
#include <cstdint>
#include "./mazeHandler.hpp"

class MazeSolver {
public:
    using Coord = std::vector<std::pair<uint16_t, uint16_t>>;

private:
    MazeHandler::Maze_t maze;
    std::vector<Coord> path;

public:
    MazeSolver(const MazeHandler::Maze_t& maze);

    void BFS();
    std::vector<Coord> getShortestPath() const;
};