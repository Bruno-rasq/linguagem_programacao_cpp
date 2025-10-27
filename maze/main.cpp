//-----------------------------------------------------------------
//
// Labirinto (Maze) - projeto c++ simulando labirintos.
// 
// -- 2 modos de opeção:)
// 
//  - modo 1: Lê alguns arquivos de modelos de labirintos e usa
// uma algoritmo de busca em largura (BFS)  para encontrar o menor
// caminho.
//
// Depois de encotrar um caminho o programa atualiza e exibe no con-
// sole o estado atual do labirinto. .
//
//  - modo 2: Neste modo o usuario consegue controlar a movimentação
// dentro do labirinto usando os direcionais (ESC para sair.)
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


void auto_follow();
void manual_follow();

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

    Maze MHR = Maze();

    const Coord start = MHR.getMaze().start;
    const Coord end = MHR.getMaze().end;

    Coord currentCoord = {start.x, start.y - 1};

    MHR.setCoord(currentCoord.x, currentCoord.y);
    MHR.display();

    while(true){

        const uint16_t x = currentCoord.x;
        const uint16_t y = currentCoord.y;
        const uint16_t key = WaitForKeyBlockingConsole();

        const char currCell = MHR.getMaze().maze[x][y];

        if(key == 0) continue;
        if(key == VK_ESCAPE) break;
        if(currCell == 'E' || (x == end.x && y == end.y)) break;
        
        Coord nextCoord = getNextCoord(currentCoord, key);

        if(!MHR.inBounds(nextCoord.x, nextCoord.y)) continue;

        const char cell = MHR.getMaze().maze[nextCoord.x][nextCoord.y];

        if(cell == '|' || cell == '_') continue;

        MHR.clearCoord(currentCoord.x, currentCoord.y);
        MHR.setCoord(nextCoord.x, nextCoord.y);
        currentCoord = nextCoord;

        system("cls");
        MHR.display();

    }

    system("cls");
    MHR.display();
}