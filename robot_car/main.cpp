#include <iostream>
#include <windows.h>    // para usar Sleep
#include <cstdlib>      // para usar system

#include "src/gridCollections.cpp"
#include "src/robot.cpp"
#include "src/grid.cpp"


// compile command: g++ main.cpp src/*.cpp -o main.exe
// run command: main.exe

void auto_follow(){

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

        board.clearPrevRobotCoord(current_coord.first, current_coord.second);

        board.setRobotCoord(next_coord.first, next_coord.second);

        Sleep(500); 
    }
}

int main(){

    auto_follow();
    
    return 0;
}