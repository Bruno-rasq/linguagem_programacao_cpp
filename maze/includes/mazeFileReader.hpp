#pragma once

#include <vector>
#include <string>

#include "./mazeStruct.hpp" 

class MazeFileReader {
public:
    static Maze_T LoadMaze(const std::string& filePath);
};