#include "./navigationSystems.hpp"

namespace NavigationSystem {

    PlayerSpaceShipHandler::PlayerSpaceShipHandler(uint8_t x, uint8_t y){
        this->coord = SpaceBoardHandler::Coordination(x, y);
        this->shipFacing = '^';
    };

    void PlayerSpaceShipHandler::changeFacing(const int8_t direction){

        if(direction == 1) this->shipFacing = '^';
        if(direction == 2) this->shipFacing = 'v';
        if(direction == 3) this->shipFacing = '<';
        if(direction == 4) this->shipFacing = '>';
    };

    void PlayerSpaceShipHandler::MOV(const uint16_t& key){

        this->coord.MOV(key);

        if(key == VK_UP)    { this->changeFacing(1); }
        if(key == VK_DOWN)  { this->changeFacing(2); }
        if(key == VK_LEFT)  { this->changeFacing(3); }
        if(key == VK_RIGHT) { this->changeFacing(4); }
    };
}