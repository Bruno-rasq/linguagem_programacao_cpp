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


void auto_follow(Maze& MHR);
void manual_follow(Maze& MHR);
void clearConsoleWindows();
void ShowCurrentCoordConsole(const uint16_t x, const uint16_t y);


int main(){

    srand(time(nullptr));

    Maze mazehandler = Maze();

    mazehandler.display();

    int mode;
    cout << "\npress 1 (modo auto follow) | press 2 (modo manual)\n";
    cin >> mode;

    switch(mode){
        case 1:  { auto_follow(mazehandler); break; }
        case 2:  { manual_follow(mazehandler); break; }
        default: { break; }
    }

    // Limpa o console e exibi o estado do labirinto assim que terminar um modo
    // de forma a manter o desenho no do labirinto no console, sem isso quando chega
    //  no final o programa simplesmente apaga.
    clearConsoleWindows();
    mazehandler.display();

    return 0;
}


void auto_follow(Maze& MHR){

    // A busca em largura (BFS) busca todas as possibilidades de caminho partindo de uma
    // coordenada corrente, quando chega ao destino ela retorna o menor caminho que liga
    // a entrada do labirinto até a saida. este é o caminho (path)
    const COORDS path = BFS(MHR);

    for(const Coord& coord : path){

        clearConsoleWindows();
        MHR.setCoord(coord.x, coord.y);
        MHR.display();
        Sleep(TIME);
    }
} 

void manual_follow(Maze& MHR){

    clearConsoleWindows();

    const Coord start = MHR.getMaze().start;
    const Coord end = MHR.getMaze().end;

    Coord currentCoord = {start.x, start.y - 1};

    // seta e imprime o estado inicial do labirinto para ter uma informação visual de onde
    // o player começa no inicio do modo.
    MHR.setCoord(currentCoord.x, currentCoord.y);
    MHR.display();
    ShowCurrentCoordConsole(currentCoord.x, currentCoord.y);

    while(true){

        const uint16_t x = currentCoord.x;
        const uint16_t y = currentCoord.y;
        const uint16_t key = WaitForKeyBlockingConsole();
        const char currCell = MHR.getMaze().maze[x][y];

        //    - o loop pula a instancia caso:
        // WaitForKeyBlockingConsole retornar 0 (alguma tecla que nao seja um direcional).
        // caso o coordenada da nova posição não esteja nos limites do labirinto.
        // caso o caracter de nova coordenada seja um parede.
        //    - O loop termina caso:
        // Chegue no final do labirinto.
        // caso a tecla ESC seja pressionada.
        if(key == 0) continue;
        if(key == VK_ESCAPE) break;
        if(currCell == 'E' || (x == end.x && y == end.y)) break;
        
        const Coord nextCoord = getNextCoord(currentCoord, key);
        const uint16_t nx = nextCoord.x;
        const uint16_t ny = nextCoord.y;
        const char newcell = MHR.getMaze().maze[nx][ny];

        if(!MHR.inBounds(nx, ny)) continue;
        if(newcell == '|' || newcell == '_') continue;

        // para evitar reescrever toda vez o estado do labirinto apenas apague o caracter na
        // coordenada atual e reescreva-o na nova coordenada
        MHR.clearCoord(x, y);
        MHR.setCoord(nx, ny);
        currentCoord = nextCoord;

        clearConsoleWindows();
        MHR.display();

        ShowCurrentCoordConsole(currentCoord.x, currentCoord.y);
    }
}

void clearConsoleWindows(){
    system("cls");
}

void ShowCurrentCoordConsole(const uint16_t x, const uint16_t y) {
    cout << "Vá para o ponto E para concluir o labirinto.\n";
    cout << "coordenada atual: (" << x << " - " << y << ")\n";
    cout << "Use os direcionais\n";
}
