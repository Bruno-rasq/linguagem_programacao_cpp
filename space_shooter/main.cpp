#include "./headers/engine2D.hpp"
#include "./headers/player.hpp"
#include "./headers/attackSystem.hpp"

#define TIMESLEEP 55

typedef Engine2D::FrameBuffer Framer;
typedef PlayerSpaceshipHandler::Player Player;
typedef Engine2D::Sprite Sprite;
typedef AttkSystem::Projectile Shot;
typedef std::vector<Shot> Shots;

//comando compilar -> g++ main.cpp src/*.cpp -I headers -o main.exe
//comando rodar -> main.exe

uint16_t keypress(){
    return Engine2D::KeyboardInput::capturePressedKey();
};

void ClearAndRender(Framer& FBC){
    system("cls");
    FBC.Render();
};


void UpdateShots(Shots& shots, Framer& FBC){

    int idx = 0;
    while(true){
        if (idx >= shots.size()) break;
    
        FBC.ClearSprite(Sprite(shots[idx].row, shots[idx].col, ' '));

        shots[idx].update();
        
        if(Engine2D::inBounds(shots[idx].row, shots[idx].col)){
            FBC.DrawSprite(Sprite(shots[idx].row, shots[idx].col, shots[idx].obj));
        } 
        else{
            std::swap(shots[idx], shots.back());
            shots.pop_back();
            continue;
        }
        idx++;
    }
};

void UpdatePlayer(Framer& FBC, Sprite& sprite, Player& plyr, uint16_t key){
    
    FBC.ClearSprite(sprite);
    plyr.MOVE(key);
    sprite = plyr.getSprite();
    FBC.DrawSprite(sprite);
};

int main(){

    bool running = true;

    // variaveis de controle do game;
    Framer FBC;
    Player plyr;
    Sprite sprite;
    Shots shots;

    FBC = Engine2D::FrameBuffer();
    plyr = PlayerSpaceshipHandler::Player();
    sprite = plyr.getSprite();


    FBC.DrawSprite(sprite);
    
    ClearAndRender(FBC);

    while(running){

        Sleep(TIMESLEEP);

        const uint16_t keypressed = keypress();

        switch(keypressed){

            case 0: { 
                break; 
            }

            case VK_ESCAPE: { 
                running = false;  
                continue;
                break;
            }

            case VK_SPACE: {
                Shot shot = plyr.ATTK();
                shots.push_back(shot);
                break;
            }

            default: { 
                UpdatePlayer(FBC, sprite, plyr, keypressed);
                break;
            }
        }

        UpdateShots(shots, FBC);

        ClearAndRender(FBC);
    }

    ClearAndRender(FBC);
    
    return 0;
}