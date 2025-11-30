#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#include "core_std.hpp"
#include "core_sys.hpp"
#include "core_types.hpp"

#include "moviment.hpp"
#include "framer.hpp"

using namespace TYPING;

class Player
{
    private:
        Spaceship spaceship;

    public:
        Player();

        void move(const WinKeyState key);
        Shoot attack() const;
        Sprite getSprite() const;
};

#endif