//-----------------------------------------------------------------
// Labirinto (Maze) - projeto c++ simulando solução de labirinto
// 
// Este programa lê algunso arquivos modelos de labirintos e usa
// uma algoritmo de busca em largura (BFS)  para encontrar o menor
// caminho.
//
// Depois de encotrar um caminho o programa atualiza e exibe no con-
// sole o estado atual do labirinto dando a noção de movimento.
//
//-----------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>

#include "./includes/mazeHandler.hpp"
#include "./includes/mazeSolver.hpp"


#define TIME 50


void auto_follow();


int main(){

    std::srand(std::time(nullptr));

    auto_follow();

    return 0;
}

void auto_follow(){

    MazeHandler mazehandler = MazeHandler();
    const std::vector<PathCoord> path = MazeSolver::getShortestPath(mazehandler);

    for(const PathCoord& coord : path){

        system("cls");
        mazehandler.updateCurrentStateMaze(coord.x, coord.y);
        mazehandler.display();
        Sleep(TIME);
    }

    system("cls");
    mazehandler.display();
}