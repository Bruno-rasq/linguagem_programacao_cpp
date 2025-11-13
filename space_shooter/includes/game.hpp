#ifndef __GAME__LOOP__HPP__
#define __GAME__LOOP__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"
#include "./keyboard.hpp"
#include "./player.hpp"
#include "./moviment.hpp"

typedef framerHandler::Sprite       Sprite;
typedef framerHandler::Framerbuffer Framer;
typedef movimenthandler::Projectil  Shoot;
typedef std::vector<Shoot>          Shoots;

class Game {
    private:
        Player player;
        Framer framebuffer;
        Shoots frameshoot;
        Sprite playersprite;

        void resetConsoleFrame() const;
        void updateShootsCoord();
        void SwitchKeyPress(const WinKeyState keypressed);

    public:
        Game();
        void start();
};

#endif