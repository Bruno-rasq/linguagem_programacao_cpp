#include "./game.hpp"

Game::Game(){
    this->player = Player();
    this->framebuffer = Framer();
    this->playersprite = this->player.getSprite();
};

void Game::start(){

    this->framebuffer.draw(this->playersprite);
    this->resetConsoleFrame();

    // o game inteiro acontece aqui.
    while(true){

        Sleep(TIME_SLEEP);

        const WinKeyState key = Keyboardhandler::keypress();

        if(key == VK_ESCAPE) break;

        this->SwitchKeyPress(key);
        this->updateShootsCoord();
        this->framebuffer.clear(this->playersprite);
        this->playersprite = this->player.getSprite();
        this->framebuffer.draw(this->playersprite);
        this->resetConsoleFrame();
    }

    this->resetConsoleFrame();
};


void Game::resetConsoleFrame() const {
    system("cls");
    this->framebuffer.render();
};

void Game::updateShootsCoord() {

    size_t idx = 0;

    while(true){

        if(idx >= this->frameshoot.size()) break;

        Shoot& shoot = this->frameshoot[idx];
    
        this->framebuffer.clear(shoot.getSprite());

        shoot.updateCoord();

        if(!movimenthandler::inBounds(shoot.coord)){
            std::swap(this->frameshoot[idx], this->frameshoot.back());
            this->frameshoot.pop_back();
            continue;
        }

        this->framebuffer.draw(shoot.getSprite());
        idx++;
    }
};

void Game::SwitchKeyPress(const WinKeyState keypressed){
    if(keypressed == 0) return;                 // teclas não mapeadas (ou sem movimentacao)
    if(keypressed == VK_SPACE){                 // espaço para atirar
        Shoot shoot = this->player.attack();
        this->frameshoot.push_back(shoot);
        return;
    }
    this->player.move(keypressed);              // executa um movimento.
};