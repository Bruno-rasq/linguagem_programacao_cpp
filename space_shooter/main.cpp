#include "./headers/game.hpp"
using namespace GameHandler;

//comando compilar -> g++ main.cpp src/*.cpp -I headers -o main.exe
//comando rodar -> main.exe

int main(){

    // variaveis de controle do game;
    Framer framerhandler;
    Player playerhandler;
    Shoots shootsheandler;

    framerhandler  = Engine2D::FrameBuffer();
    playerhandler  = PlayerSpaceshipHandler::Player();
    shootsheandler = AttkSystem::ProjectilesHandler();

    GameLoop game = GameLoop(framerhandler, playerhandler, shootsheandler);

    game.ON();
    
    return 0;
}