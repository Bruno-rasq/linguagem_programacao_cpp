#include <iostream>
#include <ctime>

#include "./includes/mazeHandler.hpp"
#include "./includes/mazeSolver.hpp"

void auto_follow();

int main(){

    std::srand(std::time(nullptr));

    auto_follow();
    return 0;
}

void auto_follow(){

    MazeHandler mazehandler = MazeHandler();
    mazehandler.display();
    
}