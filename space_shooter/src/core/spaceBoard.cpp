#include "./spaceBoard.hpp"

namespace SpaceBoardHandler {

    Sprite::Sprite(): x(0), y(0){};
    Sprite::Sprite(uint8_t x, uint8_t y, const char obj): 
    x(x), y(y), obj_ascii(obj){};

    Coordinates::Coordinates(): x(0), y(0){};
    Coordinates::Coordinates(uint8_t x, uint8_t y): x(x), y(y){};

    bool Coordinates::inBounds(const uint8_t x, const uint8_t y){

        return (0 <= x && x < HEIGHT && 0 <= y && y < WIDTH);
    };

    void Coordinates::wrapAround(uint8_t& x, uint8_t& y){

        if(x < 0)        x = HEIGHT - 1;
        if(x >= HEIGHT)  x = 0;
        if(y < 0)        y = WIDTH - 1;
        if(y >= WIDTH)   y = 0;
    };

    void Coordinates::normalizeCoord(uint8_t x, uint8_t y){

        if(!this->inBounds(x, y)) this->wrapAround(x, y);

        this->x = x;
        this->y = y;
    };

    void Coordinates::MOV(const uint16_t& key){

        if(key == VK_UP)    { this->normalizeCoord((this->x - 1), this->y); }
        if(key == VK_DOWN)  { this->normalizeCoord((this->x + 1), this->y); }
        if(key == VK_LEFT)  { this->normalizeCoord(this->x, (this->y - 1)); }
        if(key == VK_RIGHT) { this->normalizeCoord(this->x, (this->y + 1)); }
    };

    SpaceBoard::SpaceBoard(){
        for(size_t i = 0; i < HEIGHT; i++)
            this->board.push_back(string(WIDTH, ' '));
    };

    void SpaceBoard::draw(const uint8_t x, const uint8_t y, const char obj){
        this->board[x][y] = obj;
    };

    void SpaceBoard::clear(const uint8_t x, const uint8_t y){
        this->board[x][y] = ' ';
    };

    BoardFrame SpaceBoard::getFrameBoard() const {
        return this->board;
    };

}