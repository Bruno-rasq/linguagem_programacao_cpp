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

#define TIME 50

using namespace MazeResolvers;
using namespace std;


void auto_follow(){

    MazeHandler mazehandler = MazeHandler();
    const vector<Path> path = BFS(mazehandler);

    for(const Path& coord : path){

        system("cls");
        mazehandler.updateCurrentStateMaze(coord.x, coord.y);
        mazehandler.display();
        Sleep(TIME);
    }

    system("cls");
    mazehandler.display();
}


int main(){

    srand(time(nullptr));

    auto_follow();

    return 0;
}