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


    //===========================================================
    //
    //  implementação da classe do jogador
    //
    //===========================================================

    Player::Player(){};

    void Player::MOVE(const uint16_t& key){
        this->playerSpaceShip.NAV_SYS.MOV(key);
    };


    Engine2D::Sprite Player::getSprite() const {
        return Engine2D::Sprite(
            this->playerSpaceShip.NAV_SYS.coord.row, 
            this->playerSpaceShip.NAV_SYS.coord.col,
            this->playerSpaceShip.NAV_SYS.shipFacing
        );
    };
}