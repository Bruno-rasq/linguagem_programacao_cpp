#include "../headers/attackSystem.hpp"

namespace AttkSystem {

    Projectile::Projectile(){
        this->row = 0;
        this->col = 0;
        this->direction = 1;
        this->setObj(this->direction);
    };

    Projectile::Projectile(uint8_t row, uint8_t col, uint8_t direction){
        this->row = row;
        this->col = col;
        this->direction = direction;
        this->setObj(this->direction);
    };

    void Projectile::setObj(uint8_t direction){
        // 1(cima) - 2(baixo) - 3(esquerda) - 4(direita)
        if(direction == 1 || direction == 2) this->obj = '|';
        if(direction == 3 || direction == 4) this->obj = '-';
    };

    void Projectile::update(){

        if(this->direction == 1) this->row--;
        if(this->direction == 2) this->row++;
        if(this->direction == 3) this->col--;
        if(this->direction == 4) this->col++;
    };

    Engine2D::Sprite Projectile::getSprite() const {
        return Engine2D::Sprite(this->row, this->col, this->obj);
    };
}