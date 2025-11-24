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

typedef framerHandler::Sprite Sprite;
typedef framerHandler::Framerbuffer Framer;
typedef movimenthandler::Projectil Shoot;
typedef std::vector<Shoot> Shoots;
typedef asteroidhandler::Asteroid Asteroid;
typedef std::vector<Asteroid> Asteroids;

class Game
{
private:
    Timer timer;
    Player player;
    Framer framebuffer;
    Shoots frameshoot;
    Sprite playersprite;
    Asteroids asteroids;
    bool running = true;

    void updateFrame();
    void updateShootsCoord();
    void updateAsteroidsCoord();
    void updatePlayerCoord();

    void resetConsoleFrame() const;
    bool SwitchKeyPress(const WinKeyState keypressed);

public:
    Game();

    void start();
};

#endif