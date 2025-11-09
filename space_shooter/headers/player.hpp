#pragma once

// libs
#include <cstdint>
#include <windows.h>

// headers
#include "./engine2D.hpp"
#include "./navigationSystems.hpp"
#include "./attackSystem.hpp"


namespace PlayerSpaceshipHandler {

    //===========================================================
    //
    //  Macros e definições de tipo.
    //
    //===========================================================

    #define INITIAL_ROW 9
    #define INITIAL_COL 34

    //===========================================================
    //
    //  Estrutura de controle dos sistemas da nave.
    //
    //===========================================================

    struct Spaceship {

        NavigationSystem::PlayerSpaceShipHandler NAV_SYS;

        AttkSystem::Projectile shot();

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
            AttkSystem::Projectile ATTK();
            
            Engine2D::Sprite getSprite() const;
    };
};