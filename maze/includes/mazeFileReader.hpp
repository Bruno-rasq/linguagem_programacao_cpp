#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "./mazeStruct.hpp" 

class MazeFileReader {
public:
    static Maze_T LoadMaze(const std::string& filePath);
};