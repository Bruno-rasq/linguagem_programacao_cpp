
#include "../includes/mazeHandler.hpp"
#include "../includes/mazeStruct.hpp"
#include "../includes/mazeFileReader.hpp"


Maze_T MazeFileReader::LoadMaze(const std::string& filePath){
    
    Maze_T m;
    std::ifstream file(filePath);

    if(!file.is_open()) return m;


    std::string firstLine;
    getline(file, firstLine);
    std::istringstream iss(firstLine);
    uint16_t sx, sy, ex, ey;
    iss >> sx >> sy >> ex >> ey;
    m.start_x = sx;
    m.start_y = sy;
    m.end_x = ex;
    m.end_y = ey;


    std::string line;
    while(std::getline(file, line)){
        std::vector<char> row;

        for(size_t i = 0; i < line.size(); i++)
            row.push_back(line[i]);

        m.maze.push_back(row);
    }

    file.close();
    return m;
};
