#include "../headers/player.hpp"

namespace PlayerSpaceshipHandler {

    //===========================================================
    //
    //  implementação da estrutura da nave
    //
    //===========================================================

    Spaceship::Spaceship(){
        this->NAV_SYS.coord.row = INITIAL_ROW;
        this->NAV_SYS.coord.col = INITIAL_COL;
    };

    Shoot Spaceship::shot(){

        uint8_t direction = 1;
        uint8_t row = this->NAV_SYS.coord.row;
        uint8_t col = this->NAV_SYS.coord.col;

        if(this->NAV_SYS.shipFacing == '^'){ row--; }
        if(this->NAV_SYS.shipFacing == 'v'){ row++; direction = 2;}
        if(this->NAV_SYS.shipFacing == '<'){ col--; direction = 3;}
        if(this->NAV_SYS.shipFacing == '>'){ col++; direction = 4;}

        return AttkSystem::Projectile(row, col, direction);
    };


    //===========================================================
    //
    //  implementação da classe do jogador
    //
    //===========================================================

    Player::Player(){};

    void Player::MOVE(const uint16_t& key){
        this->playerSpaceShip.NAV_SYS.MOV(key);
    };

    Shoot Player::ATTK(){
        return this->playerSpaceShip.shot();
    };

    Sprite Player::getSprite() const {
        return Engine2D::Sprite(
            this->playerSpaceShip.NAV_SYS.coord.row, 
            this->playerSpaceShip.NAV_SYS.coord.col,
            this->playerSpaceShip.NAV_SYS.shipFacing
        );
    };
}