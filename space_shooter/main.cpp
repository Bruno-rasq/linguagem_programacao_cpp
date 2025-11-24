#include "./includes/game.hpp"

/* 
    compilar: g++ main.cpp includes/*.cpp -I includes -o main.exe
    rodar: main.exe 
*/

int main()
{

    Game game = Game();

    game.start();

    return 0;
}