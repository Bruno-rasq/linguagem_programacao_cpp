#ifndef __GAME__LOOP__HPP__
#define __GAME__LOOP__HPP__

#include "./core_std.hpp"
#include "./core_types.hpp"

#include "./asteroids.hpp"
#include "./collision.hpp"
#include "./framer.hpp"
#include "./keyboard.hpp"
#include "./moviment.hpp"
#include "./player.hpp"
#include "./timer.hpp"

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
        Lifes_T lifes = {true, true, true};
        Scores_T score = 0;

        /* gerenciamento de pontuação e vidas. */
        void incrementScore(const uint8_t score);

        /* funções de screen. */
        void RenderFrame(const FB& fb);
        void HUD(); /* interface de vida e poontos do jogador. */

        /* funções de remoção. */
        void RemoveShoot(size_t idx);
        void RemoveAsteroid(size_t idx);

        /* Funções de colisão. */
        void collisionsResolver(Collisions& collisions);
        void collisionAsteroidxPlayer(Collision& collision);
        void collisionAsteroidxShoot(Collision& collision);
        void collisionAsteroidxAsteroid(Collision& collision);


        /* funções que atualizam estados e objetos. */
        void updateFrame(FB& fb);
        void updateShootsCoord(FB& fb);
        void updateAsteroidsCoord(FB& fb);
        void updatePlayerCoord(FB& fb);

        /* funções que resolve comandos do teclado. */
        bool SwitchKeyPress(const WinKeyState keypressed);

    public:
        Game();

        void start();
};

#endif