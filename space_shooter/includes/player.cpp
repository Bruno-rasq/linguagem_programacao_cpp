#include "./player.hpp"

Player::Player(): spaceship(movimenthandler::Spaceship()){};

Sprite Player::getSprite() const {
    return this->spaceship.getSprite();
};

void Player::move(const WinKeyState key){

    if(key == VK_UP) this->spaceship.moveSpaceship(Coord(-1, 0), 1);
    if(key == VK_DOWN) this->spaceship.moveSpaceship(Coord(1, 0), 2);
    if(key == VK_LEFT) this->spaceship.moveSpaceship(Coord(0, -1), 3);
    if(key == VK_RIGHT) this->spaceship.moveSpaceship(Coord(0, 1), 4);
};

Shoot Player::attack() const {

    Direction dir = 1;
    Coord_row x = this->spaceship.coord.x;
    Coord_row y = this->spaceship.coord.y;

    if(this->spaceship.shipFacing == '^'){ x--; }
    if(this->spaceship.shipFacing == 'v'){ x++; dir = 2; }
    if(this->spaceship.shipFacing == '<'){ y--; dir = 3; }
    if(this->spaceship.shipFacing == '>'){ y++; dir = 4; }

    return Shoot(Coord(x, y), dir);
};