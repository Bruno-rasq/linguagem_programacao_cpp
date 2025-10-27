//-----------------------------------------------------------------
//
// Labirinto (Maze) - projeto c++ simulando solução de labirinto
// 
// Este programa lê algunso arquivos modelos de labirintos e usa
// uma algoritmo de busca em largura (BFS)  para encontrar o menor
// caminho.
//
// Depois de encotrar um caminho o programa atualiza e exibe no con-
// sole o estado atual do labirinto dando a noção de movimento.
//
// Autor: Bruno D.Rasq
//
//-----------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>

#include "./includes/mazeHandler.hpp"
#include "./includes/mazeResolvers.hpp"
#include "./includes/keyboardHandler.hpp"

#define TIME 50

using namespace std;
using namespace MazeHandler;
using namespace MazeResolvers;
using namespace KEYBOARDHANDLER;


void auto_follow(){

    Maze mazehandler = Maze();
    const COORDS path = BFS(mazehandler);

    for(const Coord& coord : path){

        system("cls");
        mazehandler.setCoord(coord.x, coord.y);
        mazehandler.display();
        Sleep(TIME);
    }

    system("cls");
    mazehandler.display();
}

void manual_follow(){

    Maze mazehandler = Maze();
    const Coord start = mazehandler.getMaze().start;
    const Coord end = mazehandler.getMaze().end;

    Coord currentCoord = start;

    mazehandler.setCoord(currentCoord.x, currentCoord.y);
    mazehandler.display();

    while(true){

        uint16_t key = WaitForKeyBlockingConsole();

        if(key == VK_ESCAPE) break;
        if(currentCoord.x == end.x && currentCoord.y == end.y) break;
        
        Coord nextCoord = getNextCoord(currentCoord, key);
        const char cell = mazehandler.getMaze().maze[nextCoord.x][nextCoord.y];

        if(cell != '|' || cell != '_'){
            mazehandler.clearCoord(currentCoord.x, currentCoord.y);
            mazehandler.setCoord(nextCoord.x, nextCoord.y);

            system("cls");
            mazehandler.display();
        }
    }

    system("cls");
    mazehandler.display();
}


int main(){

    srand(time(nullptr));

    int mode;
    cout << "press 1 (modo auto follow) | press 2 (modo manual)\n";
    cin >> mode;

    switch(mode){
        case 1:  { auto_follow(); break; }
        case 2:  { manual_follow(); break; }
        default: { cout << "Invalido!\n"; break; }
    }

    return 0;
}