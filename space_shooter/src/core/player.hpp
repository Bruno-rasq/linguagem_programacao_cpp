#pragma once

// libs
#include <cstdint>
#include <windows.h>

// headers
#include "./navigationSystems.hpp"
#include "./spaceBoard.hpp"

using namespace SpaceBoardHandler;

namespace PlayerSpaceshipHandler {


    //===========================================================
    //
    //  Macros e definições de tipo.
    //
    //===========================================================

    #define INITCOORDX 35
    #define INITCOORDY 15

    //===========================================================
    //
    //  Estrutura de controle dos sistemas da nave.
    //
    //===========================================================

    struct Spaceship {

        NavigationSystem::PlayerSpaceShipHandler NAV_SYS;
        // TODO: sistema de ataque...
        // TODO: sistema de vital...

        Spaceship();
    };


    //===========================================================
    //
    //  classe do jogador
    //
    //===========================================================

    class Player {
        private:
            Spaceship playerSpaceShip;

        public:

            Player();

            void MOVE(const uint16_t& key);
            Sprite getSprite() const;
    };
};