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

    Sprite Projectile::getSprite() const {
        return Engine2D::Sprite(this->row, this->col, this->obj);
    };



    ProjectilesHandler::ProjectilesHandler(){};

    void ProjectilesHandler::AddShoot(Projectile shoot){
        this->shoots.push_back(shoot);
    };

    void ProjectilesHandler::UpdateShoots(Framer& framer){
        size_t idx = 0;
        while(true){
            if(idx >= this->shoots.size()) break;

            framer.ClearSprite(
                Sprite(this->shoots[idx].row, this->shoots[idx].col,' '));

            this->shoots[idx].update();

            if(Engine2D::inBounds(this->shoots[idx].row,this->shoots[idx].col)){
                framer.DrawSprite(
                    Sprite(
                        this->shoots[idx].row, 
                        this->shoots[idx].col,
                        this->shoots[idx].obj
                    ));
            }
            else{
                std::swap(this->shoots[idx], this->shoots.back());
                this->shoots.pop_back();
                continue;
            }
            idx++;
        }
    };
}