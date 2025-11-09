#pragma once

// libs
#include <cstdint>
#include <windows.h>

// headers
#include "./engine2D.hpp"


namespace NavigationSystem {

    /*
        Syistema de navegação para a nave do jogador.

        - possue uma estrutura de coordenada espacial
        - controle direciontal da face da nave.
    */
    struct PlayerSpaceShipHandler {

        char shipFacing;
        Engine2D::Coordinates coord;

        PlayerSpaceShipHandler();
        PlayerSpaceShipHandler(uint8_t row, uint8_t col);

        void changeFacing(const int8_t direction);

        void MOV(const uint16_t& key);
    };

    /*
        Sistema de navegação para a nave dos inimigos

        Inimigos não controlam diretamente suas naves, sua mvimentaçõa
        é de acordo com a posição da nave do player.
    */
    struct EnemySpaceShipHandler {

        Engine2D::Coordinates coord;

        EnemySpaceShipHandler();
        EnemySpaceShipHandler(uint8_t row, uint8_t col);

        void MOV(const uint8_t targetX, const uint8_t targetY);
    };
}