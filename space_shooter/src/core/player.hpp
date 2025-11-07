#pragma once

#include <cstdint>
#include <windows.h>

#include "./navigationSystems.hpp"
#include "./spaceBoard.hpp"

using namespace SpaceBoardHandler;

namespace PlayerSpaceshipHandler {

    #define INITCOORDX 35
    #define INITCOORDY 15

    /*
        Estrutura basica da nave
    */
    struct Spaceship {

        NavigationSystem::PlayerSpaceShipHandler NAV_SYS;
        // TODO: sistema de ataque...
        // TODO: sistema de vital...

        Spaceship();
    };

    /*
        classe gerenciadora da instancia do player
    */
    class Player {
        private:
            Spaceship playerSpaceShip;

        public:

            Player();

            void MOVE(const uint16_t& key);

            Sprite getSprite() const;
    };
};