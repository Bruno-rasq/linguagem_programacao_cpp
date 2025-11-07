#include "./spaceBoard.hpp"

namespace SpaceBoardHandler {

    //===========================================================
    //
    //  Estrutura dos sprites
    //
    //===========================================================

    Sprite::Sprite(): x(0), y(0){};

    Sprite::Sprite(uint8_t x, uint8_t y, const char obj): x(x), y(y), obj_ascii(obj){};


    //===========================================================
    //
    //  Estrutura das coordenadas
    //
    //===========================================================

    Coordinates::Coordinates(): x(0), y(0){};
    
    Coordinates::Coordinates(uint8_t y, uint8_t x): x(x), y(y){};


    bool Coordinates::inBounds(const uint8_t y, const uint8_t x){

        return (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT);
    };


    void Coordinates::wrapAround(uint8_t& y, uint8_t& x){

        if(x < 0)        x = WIDTH - 1;
        if(x >= WIDTH)   x = 0;
        if(y < 0)        y = HEIGHT - 1;
        if(y >= HEIGHT)  y = 0;
    };


    void Coordinates::normalizeCoord(uint8_t y, uint8_t x){

        if(!this->inBounds(y, x)) this->wrapAround(y, x);

        this->x = x;
        this->y = y;
    };


    void Coordinates::MOV(const uint16_t& key){

        int dx = this->x;
        int dy = this->y;

        if(key == VK_UP)    { dy--; }
        if(key == VK_DOWN)  { dy++; }
        if(key == VK_LEFT)  { dx--; }
        if(key == VK_RIGHT) { dx++; }

        this->normalizeCoord(dy, dx);
    };

}