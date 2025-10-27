#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdint>
#include <windows.h>

namespace MazeHandler {

    typedef std::vector<std::vector<char>> maze_t;
    
    struct Coord {
        int32_t x, y;
        Coord(int32_t x, int32_t y);
    };

    struct MazeObject {
        maze_t maze;
        Coord start, end;

        MazeObject();
        MazeObject(const maze_t& maze, const Coord& start, const Coord& end);
    };

    MazeObject loadMaze(const std::string& filePath);
    MazeObject randMaze();
    Coord getNextCoord(Coord& currentCoord, const uint16_t key);

    class Maze {
    private:
        MazeObject currentMaze;

    public:
        Maze();

        void setCoord(uint16_t x, uint16_t y);
        void clearCoord(uint16_t x, uint16_t y);
        bool inBounds(uint16_t x, uint16_t y) const;
        void display() const;
        MazeObject getMaze() const;
    };
}

