#ifndef __PLAYER__HPP__
#define __PLAYER__HPP__

#include "./core_std.hpp"
#include "./core_sys.hpp"
#include "./moviment.hpp"
#include "./framer.hpp"

typedef movimenthandler::Spaceship Spaceship;
typedef movimenthandler::Coord Coord;
typedef movimenthandler::Projectil Shoot;
typedef framerHandler::Sprite Sprite;

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