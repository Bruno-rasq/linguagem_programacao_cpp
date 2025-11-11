#pragma once

#include "./core.hpp"
#include "./engine2D.hpp"

namespace NavigationSystem {

    typedef Engine2D::Coordinates Coord;

    struct PlayerSpaceShipHandler {

        char shipFacing;
        Coord coord;

        PlayerSpaceShipHandler();
        PlayerSpaceShipHandler(uint8_t row, uint8_t col);
        void changeFacing(const int8_t direction);
        void MOV(const uint16_t& key);
    };
}