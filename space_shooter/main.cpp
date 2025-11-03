#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdlib>

#include "./includes/spaceGrid.hpp"
#include "./includes/keyboardHandler.hpp"
#include "./includes/player.hpp"

#define TIMESLEEP  25

using namespace SpaceGrid;
using namespace PlayerHandler;
using namespace KEYBOARDHANDLER;
using namespace std;

int main(){

    Space grid = Space();
    PlayerSpaceship pss = PlayerSpaceship();
    tuple<uint8_t, uint8_t, char> info;

    info = pss.Info();

    grid.setCoord(get<0>(info), get<1>(info), get<2>(info));

    cout << grid.getFrameState() << "\n";

    while(true){

        Sleep(TIMESLEEP);
        
        const uint16_t key = captureKey();

        if(key == VK_ESCAPE) break;
        if(key == VK_SPACE) continue;
        if(key == 0) continue;

        // move nave
        pss.move(key);

        // limpa posicao anterior
        grid.clearCoord(get<0>(info), get<1>(info));

        // pega as novas infos de coordenada e caracter
        info = pss.Info();

        normalizeCoord(get<0>(info), get<1>(info));

        // seta no grid a nova coordenada da nave
        grid.setCoord(get<0>(info), get<1>(info), get<2>(info));

        system("cls");

        // exibe o estado atual do grid
        cout << grid.getFrameState() << "\n";

    }

    return 0;
}