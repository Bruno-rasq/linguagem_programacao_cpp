#include "../includes/mazeHandler.hpp"

#define mazeModel001 "src/mazeModels/maze_001.txt"
#define mazeModel002 "src/mazeModels/maze_002.txt"
#define mazeModel003 "src/mazeModels/maze_003.txt"
#define mazeModel004 "src/mazeModels/maze_004.txt"
#define mazeModel005 "src/mazeModels/maze_005.txt"
#define mazeModel006 "src/mazeModels/maze_006.txt"
#define mazeModel007 "src/mazeModels/maze_007.txt"
#define voidCell     ' '
#define filterCell   '@'


MazeHandler::Coord::Coord(int32_t x, int32_t y): x(x), y(y){}


MazeHandler::MazeObject::MazeObject(
    const maze_t& maze, const Coord& start, const Coord& end):
maze(maze), start(start), end(end){}


MazeHandler::MazeObject::MazeObject():
maze({}), start({-1, -1}), end({-1, -1}){}


MazeHandler::MazeObject MazeHandler::loadMaze(const std::string& filePath){

    MazeObject mo;
    std::ifstream file(filePath);
    std::string line;

    if(!file.is_open()) return mo;

    getline(file, line);
    std::istringstream iss(line);
    int32_t sx, sy, ex, ey;
    iss >> sx >> sy >> ex >> ey;
    mo.start = {sx, sy};
    mo.end = {ex, ey};

    while(std::getline(file, line)){

        std::vector<char> row;
        for(size_t i = 0; i < line.size(); i++)
            row.push_back(line[i]);

        mo.maze.push_back(row);
    }

    file.close();
    return mo;
}


MazeHandler::MazeObject MazeHandler::randMaze(){
    std::vector<MazeObject> loadedMazes;

    loadedMazes.push_back(loadMaze(mazeModel001));
    loadedMazes.push_back(loadMaze(mazeModel002));
    loadedMazes.push_back(loadMaze(mazeModel003));
    loadedMazes.push_back(loadMaze(mazeModel004));
    loadedMazes.push_back(loadMaze(mazeModel005));
    loadedMazes.push_back(loadMaze(mazeModel006));
    loadedMazes.push_back(loadMaze(mazeModel007));

    const size_t idx = std::rand() % loadedMazes.size();
    return loadedMazes[idx];
}

MazeHandler::Coord MazeHandler::getNextCoord(Coord currentCoord, const uint16_t key){
    
    if(key == VK_UP) currentCoord.x--;
    if(key == VK_DOWN) currentCoord.x++;
    if(key == VK_LEFT) currentCoord.y--;
    if(key == VK_RIGHT) currentCoord.y++;

    return currentCoord;
}


MazeHandler::Maze::Maze(){
    this->currentMaze = randMaze();
}


void MazeHandler::Maze::setCoord(uint16_t x, uint16_t y){
    this->currentMaze.maze[x][y] = filterCell;
}


void MazeHandler::Maze::clearCoord(uint16_t x, uint16_t y){
    this->currentMaze.maze[x][y] = voidCell;
}


bool MazeHandler::Maze::inBounds(uint16_t x, uint16_t y) const {
    return (0 <= x && x < this->currentMaze.maze.size()
        && 0 <= y && y < this->currentMaze.maze[0].size());
}


void MazeHandler::Maze::display() const {
    std::ostringstream buffer;

    for(size_t i = 0; i < this->currentMaze.maze.size(); i++){
        for(size_t j = 0; j < this->currentMaze.maze[i].size(); j++)
            buffer << this->currentMaze.maze[i][j];
        buffer << "\n";
    }

    std::cout << buffer.str() << std::endl;
}


MazeHandler::MazeObject MazeHandler::Maze::getMaze() const {
    return this->currentMaze;
}