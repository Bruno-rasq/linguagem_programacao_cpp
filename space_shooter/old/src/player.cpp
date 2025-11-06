#include "../includes/player.hpp"

namespace PlayerHandler {

    const map<uint8_t, char> delta_symbol = {{1, '^'}, {2, 'v'}, {3, '<'}, {4, '>'}};

    // struct 
    void Spaceship::setCurrentDirection(const uint8_t dir){

        this->direction = dir;
        this->SetSymbolByCurrentDirection(delta_symbol.at(dir));
    };


    void Spaceship::SetSymbolByCurrentDirection(const char symbol){
        this->symbol = symbol;
    };


    void Spaceship::DecrementHP(const uint8_t damage){
        this->HP = max(0, this->HP - damage);
    };


    // class
    PlayerSpaceship::PlayerSpaceship(){};

    SPACESHIPINFO PlayerSpaceship::Info() const {
        const SPACESHIPINFO info = {
            this->spaceship.coord.x,
            this->spaceship.coord.y, 
            this->spaceship.symbol};
            
        return info;
    };

    void PlayerSpaceship::move(const uint16_t key){

        this->spaceship.coord.MOVE(key); // seta nova coordenada

        // modifica o simbolo da nave 
        if(key == VK_UP)    { this->spaceship.setCurrentDirection(1); }
        if(key == VK_DOWN)  { this->spaceship.setCurrentDirection(2); }
        if(key == VK_LEFT)  { this->spaceship.setCurrentDirection(3); }
        if(key == VK_RIGHT) { this->spaceship.setCurrentDirection(4); }
    };

    // TODO
    void PlayerSpaceship::atk(){};
}