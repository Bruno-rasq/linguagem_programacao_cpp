#include <iostream>
#include <windows.h>
#include <cstdlib>

#include "./includes/spaceGrid.hpp"
#include "./includes/keyboardHandler.hpp"

#define TIMESLEEP  150

using namespace SpaceGrid;
using namespace KEYBOARDHANDLER;
using namespace std;

int main(){

    bool running = true;
    while(running){

        Sleep(TIMESLEEP);
        
        const uint16_t key = captureKey();

        switch(key){
            case VK_UP: { cout << "cima\n"; break; }
            case VK_DOWN: { cout << "baixo\n"; break; }
            case VK_LEFT: { cout << "esquerda\n"; break; }
            case VK_RIGHT: { cout << "direita\n"; break; }
            case VK_SPACE: { cout << "espaco\n"; break; }
            case VK_ESCAPE: { cout << "saindo\n"; running = false; break;}
            default: { cout << "0\n"; break; }
        }
    }

    return 0;
}