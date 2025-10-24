#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>

#include "./includes/mazeHandler.hpp"
#include "./includes/mazeSolver.hpp"

#define TIME 120

void auto_follow();

int main(){

    std::srand(std::time(nullptr));

    auto_follow();

    return 0;
}

void auto_follow(){

    MazeHandler maze = MazeHandler();
    const std::vector<PathCoord> path = MazeSolver::getShortestPath(maze);

    maze.display();

    for(const PathCoord& coord : path){
        system("cls");
        maze.updateCurrentStateMaze(coord);
        maze.display();

        Sleep(TIME);
    }

    system("cls");
    maze.display();
    
}