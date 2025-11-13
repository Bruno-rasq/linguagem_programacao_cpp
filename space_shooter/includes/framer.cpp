#include "./framer.hpp"

namespace framerHandler {

    Sprite::Sprite(): x(0), y(0), obj(' '){};
    
    Sprite::Sprite(Coord_row x, Coord_col y, Obj_ascii obj){
        this->x = x;
        this->y = y;
        this->obj = obj;
    };

    Framerbuffer::Framerbuffer(){
        for(size_t i = 0; i < FRAME_BOARD_MAX_HEIGTH; i++)
            this->frame.push_back(std::string(FRAME_BOARD_MAX_WIDTH, ' '));
    };

    void Framerbuffer::draw(const Sprite& sprite){
        this->frame[sprite.x][sprite.y] = sprite.obj;
    };

    void Framerbuffer::clear(const Sprite& sprite){
        this->frame[sprite.x][sprite.y] = ' ';
    };

    void Framerbuffer::render() const {
        
        Buffer buff;

        buff << std::string(FRAME_BOARD_MAX_WIDTH + 2, '_') << "\n";

        for(const std::string& line : this->frame)
            buff <<  "|" << line << "|\n";
        
        buff << "|" << std::string(FRAME_BOARD_MAX_WIDTH, '_') << "|\n";

        std::cout << buff.str();
    };
}