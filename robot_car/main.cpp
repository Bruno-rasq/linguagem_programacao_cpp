#include <iostream>
#include <windows.h>    // para usar Sleep
#include <cstdlib>      // para usar system

#include "include/gridCollections.hpp"
#include "include/robot.hpp"
#include "include/grid.hpp"


#define TIME 150
#define FILE "./src/boards.txt"


// compile command: g++ main.cpp src/*.cpp  -Iinclude -o program.exe
// run command: program.exe


void auto_follow(){

    bool load = GridCollections::loadFileText(FILE);

    if(!load){
        std::cout << "Erro ao carregar arquivos de boards\n";
        return;
    }

    Robot robot = Robot(0, 0);
    Grid board  = Grid();

    board.setRobotCoord(0, 0);

    while(true)
    {   
        system("cls");

        board.printGridState();

        GridCollections::Board boardstate = board.getGridState();

        std::pair<int, int> current_coord = robot.getCoord();
        std::pair<int, int> next_coord = robot.getNextCoord(boardstate);

        if(next_coord.first == -1 && next_coord.second == -1) break;

        board.clearPrevRobotCoord(
            current_coord.first, current_coord.second);

        board.setRobotCoord(next_coord.first, next_coord.second);
        robot.setCoord(next_coord.first, next_coord.second);

        Sleep(TIME); 
    }
}

int main(){

    auto_follow();
    
    return 0;
}