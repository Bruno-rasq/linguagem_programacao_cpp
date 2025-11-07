#include "./player.hpp"

namespace PlayerSpaceshipHandler {

    Spaceship::Spaceship(){
        this->NAV_SYS.coord.x = INITCOORDX;
        this->NAV_SYS.coord.y = INITCOORDY;
    };

    Player::Player(){};

    void Player::MOVE(const uint16_t& key){
        this->playerSpaceShip.NAV_SYS.MOV(key);
    };


    Sprite Player::getSprite() const {
        return Sprite(
            this->playerSpaceShip.NAV_SYS.coord.x, 
            this->playerSpaceShip.NAV_SYS.coord.y,
            this->playerSpaceShip.NAV_SYS.shipFacing
        );
    };
}