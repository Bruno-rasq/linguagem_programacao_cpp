#include "./moviment.hpp"

namespace movimenthandler {

    Coord::Coord(): x(0), y(0){};
    Coord::Coord(Coord_row x, Coord_col y): x(x), y(y){};

    void Coord::delta(const Coord_row dx, const Coord_col dy){
        
        this->x += dx;
        this->y += dy;
    };

    Spaceship::Spaceship(){

        this->shipFacing = '^';
        this->coord = Coord(
            PLAYER_INITIAL_COORD_ROW, PLAYER_INITIAL_COORD_COL);
    };

    void Spaceship::changeFacing(const Direction dir){

       if(dir == 1) this->shipFacing = '^';
       if(dir == 2) this->shipFacing = 'v';
       if(dir == 3) this->shipFacing = '<';
       if(dir == 4) this->shipFacing = '>';
    };

    void Spaceship::moveSpaceship(const Coord delta, const Direction dir){

        this->coord.delta(delta.x, delta.y);
        this->changeFacing(dir);
    };

    framerHandler::Sprite Spaceship::getSprite() const {
        return framerHandler::Sprite(
            this->coord.x, this->coord.y, this->shipFacing
        );
    };

    Projectil::Projectil(const Coord coord, const Spaceshipface& dir){

        this->coord = coord;
        this->dir = dir;

        if(dir == 1 || dir == 2) this->obj = '|';
        if(dir == 3 || dir == 4) this->obj = '-';
    };

    void Projectil::updateCoord(){
    
        if(this->dir == 1) this->coord.delta(-1, 0);
        if(this->dir == 2) this->coord.delta(1, 0);
        if(this->dir == 3) this->coord.delta(0, -1);
        if(this->dir == 4) this->coord.delta(0, 1);
    };

    framerHandler::Sprite Projectil::getSprite() const {
        return framerHandler::Sprite(
            this->coord.x, this->coord.y, this->obj
        );
    };

    bool inBounds(const Coord& coord){
        return (0 <= coord.x && coord.x < FRAME_BOARD_MAX_HEIGTH
            && 0 <= coord.y && coord.y < FRAME_BOARD_MAX_WIDTH);
    };
}