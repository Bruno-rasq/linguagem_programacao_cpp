#pragma once

#include "./core.hpp"
#include "./engine2D.hpp"
#include "./player.hpp"
#include "./attackSystem.hpp"

namespace GameHandler {

    #define TIMESLEEP 80

    typedef Engine2D::FrameBuffer Framer;
    typedef Engine2D::KeyboardInput KeyBoardHandler;
    typedef Engine2D::Sprite Sprite;
    typedef PlayerSpaceshipHandler::Player Player;
    typedef AttkSystem::Projectile Shoot;
    typedef AttkSystem::ProjectilesHandler Shoots;

    class GameLoop {
        private:

            bool OnOff = false;
            Sprite playerSprite;
            Player playerHandler;
            Shoots shootsHandler;
            Framer frameHandler;

        public:

        GameLoop(Framer& fh, Player& ph, Shoots& sh);

        void ON();
        void OFF();
        void LOOP();

        void ClearAndRender();
        void UpdatePlayer(const uint16_t keypressed);
        void SwitchKeyPress(const uint16_t keypressed);
            
    };
}