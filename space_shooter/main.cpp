#include "./headers/engine2D.hpp"
#include "./headers/player.hpp"
using namespace std;

//comando compilar -> g++ main.cpp src/*.cpp -I headers -o main.exe
//comando rodar -> main.exe

typedef Engine2D::FrameBuffer Framer;
typedef PlayerSpaceshipHandler::Player Player;
typedef Engine2D::Sprite Sprite;


void clearAndRender(Framer& FBC){
    system("cls");
    FBC.Render();
}

int main(){

    Framer FBC = Engine2D::FrameBuffer();

    Player plyr = PlayerSpaceshipHandler::Player();

    Sprite sprite = plyr.getSprite();

    FBC.DrawSprite(sprite);
    
    clearAndRender(FBC);

    while(true){

        Sleep(50);

        const uint16_t keypressed = Engine2D::KeyboardInput::capturePressedKey();

        if(keypressed == 0 || keypressed == VK_SPACE) continue;
        if(keypressed == VK_ESCAPE) break;

        FBC.ClearSprite(sprite);

        plyr.MOVE(keypressed);
        sprite = plyr.getSprite();

        FBC.DrawSprite(sprite);

        clearAndRender(FBC);
    }

    clearAndRender(FBC);
    
    return 0;
}