#ifndef __GAME__LOOP__HPP__
#define __GAME__LOOP__HPP__

#include "./core_std.hpp"
#include "./core_types.hpp"

#include "./framer.hpp"
#include "./keyboard.hpp"
#include "./player.hpp"
#include "./moviment.hpp"
#include "./asteroids.hpp"
#include "./timer.hpp"
#include "./collision.hpp"

using namespace TYPING;

class Game
{
    private:

        Timer timer;
        Player player;
        Shoots frameshoot;
        Sprite playersprite;
        Asteroids asteroids;

        bool running = true;
        Lifes lifes = {true, true, true};
        uint32_t score = 0;

        void HUD(); /* interface de vida e poontos do jogador. */

        void RemoveShoot(size_t idx);

        void updateFrame(FB& fb);
        void updateShootsCoord(FB& fb);
        void updateAsteroidsCoord(FB& fb);
        void updatePlayerCoord(FB& fb);

        void RenderFrame(const FB& fb);
        bool SwitchKeyPress(const WinKeyState keypressed);

    public:
        Game();

        void start();
};

#endif