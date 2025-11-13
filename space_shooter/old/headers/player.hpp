#pragma once

#include "./core.hpp"
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

    typedef AttkSystem::Projectile Shoot;
    typedef NavigationSystem::PlayerSpaceShipHandler Spaceshiphandler;
    typedef Engine2D::Sprite Sprite;

    //===========================================================
    //
    //  Estrutura de controle dos sistemas da nave.
    //
    //===========================================================

    struct Spaceship {

        Spaceshiphandler NAV_SYS;
        Shoot shot();
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
            Shoot  ATTK();
            Sprite getSprite() const;
    };
};