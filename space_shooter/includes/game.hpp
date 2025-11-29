#ifndef __GAME__LOOP__HPP__
#define __GAME__LOOP__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"
#include "./keyboard.hpp"
#include "./player.hpp"
#include "./moviment.hpp"
#include "./asteroids.hpp"
#include "./timer.hpp"
#include "./collision.hpp"

//typedef framerHandler::Framerbuffer Framer;
typedef framerHandler::Sprite Sprite;
typedef movimenthandler::Projectil Shoot;
typedef std::vector<Shoot> Shoots;
typedef asteroidhandler::Asteroid Asteroid;
typedef std::vector<Asteroid> Asteroids;

class Game
{
private:
    Timer timer;
    Player player;
    Shoots frameshoot;
    Sprite playersprite;
    Asteroids asteroids;
    bool running = true;

    void updateFrame(framerHandler::framer_buffer& fb);
    void updateShootsCoord(framerHandler::framer_buffer& fb);
    void updateAsteroidsCoord(framerHandler::framer_buffer& fb);
    void updatePlayerCoord(framerHandler::framer_buffer& fb);

    //void resetConsoleFrame() const;
    void RenderFrame(const framerHandler::framer_buffer& fb);
    bool SwitchKeyPress(const WinKeyState keypressed);

public:
    Game();

    void start();
};

#endif