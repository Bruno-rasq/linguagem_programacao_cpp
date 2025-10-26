#include "../includes/mazeHandler.hpp"
#include "../includes/mazeFileReader.hpp"

#define maze001 "src/mazeModels/maze_001.txt"
#define maze002 "src/mazeModels/maze_002.txt"
#define maze003 "src/mazeModels/maze_003.txt"
#define maze004 "src/mazeModels/maze_004.txt"
#define maze005 "src/mazeModels/maze_005.txt"
#define maze006 "src/mazeModels/maze_006.txt"
#define maze007 "src/mazeModels/maze_007.txt"

MazeHandler::MazeHandler(){

    mazes.push_back(MazeFileReader::LoadMaze(maze001));
    mazes.push_back(MazeFileReader::LoadMaze(maze002));
    mazes.push_back(MazeFileReader::LoadMaze(maze004));
    mazes.push_back(MazeFileReader::LoadMaze(maze003));
    mazes.push_back(MazeFileReader::LoadMaze(maze005));
    mazes.push_back(MazeFileReader::LoadMaze(maze006));
    mazes.push_back(MazeFileReader::LoadMaze(maze007));

    
    const uint8_t idx = std::rand() % mazes.size();
    currentMaze = mazes[idx];

}

void MazeHandler::updateCurrentStateMaze(uint16_t x, uint16_t y){
    currentMaze.maze[x][y] = '@';
}

bool MazeHandler::inbounds(uint16_t x, uint16_t y) const {
    return (0 <= x && x < currentMaze.maze.size() 
        && 0 <= y < currentMaze.maze[0].size());
}

void MazeHandler::display() const {
    std::ostringstream buffer;

    for(size_t i = 0; i < currentMaze.maze.size(); i++){
        for(size_t j = 0; j < currentMaze.maze[i].size(); j++)
            buffer << currentMaze.maze[i][j];
        buffer << "\n";
    }

    std::cout << buffer.str() << std::endl; 
}

Maze_T MazeHandler::getMaze() const { return currentMaze; }