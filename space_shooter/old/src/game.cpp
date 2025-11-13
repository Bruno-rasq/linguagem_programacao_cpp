#include "../headers/game.hpp"

namespace GameHandler {

    GameLoop::GameLoop(Framer& fh, Player& ph, Shoots& sh){
        this->frameHandler = fh;
        this->playerHandler = ph;
        this->shootsHandler = sh;
        this->playerSprite = this->playerHandler.getSprite();
    };

    void GameLoop::ON(){
        this->OnOff = true;
        this->LOOP();
    };

    void GameLoop::OFF(){
        this->OnOff = false;
    };

    void GameLoop::LOOP(){

        this->frameHandler.DrawSprite(this->playerSprite);
        this->ClearAndRender();

        while(this->OnOff){

            Sleep(TIMESLEEP);

            const uint16_t key = KeyBoardHandler::capturePressedKey();

            if(key == VK_ESCAPE){ this->OFF(); continue; }

            this->SwitchKeyPress(key);
            this->shootsHandler.UpdateShoots(this->frameHandler);
            this->ClearAndRender();
        }

        this->ClearAndRender();
    };

    void GameLoop::ClearAndRender(){
        system("cls");
        this->frameHandler.Render();
    };

    void GameLoop::UpdatePlayer(const uint16_t keypressed){
        this->frameHandler.ClearSprite(this->playerSprite);
        this->playerHandler.MOVE(keypressed);
        this->playerSprite = this->playerHandler.getSprite();
        this->frameHandler.DrawSprite(this->playerSprite);
    };

    void GameLoop::SwitchKeyPress(const uint16_t keypressed){
        if(keypressed == 0) return;
        if(keypressed == VK_SPACE){
            Shoot shoot = this->playerHandler.ATTK();
            this->shootsHandler.AddShoot(shoot);
            return;
        }
        this->playerHandler.MOVE(keypressed);
    };
}