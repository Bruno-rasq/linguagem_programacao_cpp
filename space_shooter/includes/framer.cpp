#include "./framer.hpp"

namespace framerHandler
{

    Sprite::Sprite() : x(0), y(0), obj(' ') {};

    Sprite::Sprite(Coord_row x, Coord_col y, Obj_ascii obj) : x(x), y(y), obj(obj) {};


    framer_buffer::framer_buffer()
    {
        for(size_t i = 0; i < FRAME_BOARD_MAX_HEIGTH; i++)
            this->data.push_back(std::string(FRAME_BOARD_MAX_WIDTH, ' '));
    };

    void framer_buffer::draw(const Sprite& sprite)
    {
        this->data[sprite.x][sprite.y] = sprite.obj;
    };

    void framer_buffer::render() const 
    {
        Buffer buff;

        buff << std::string(FRAME_BOARD_MAX_WIDTH + 2, '_') << "\n";

        for (const std::string &line : this->data)
            buff << "|" << line << "|\n";

        buff << "|" << std::string(FRAME_BOARD_MAX_WIDTH, '_') << "|\n";

        std::cout << buff.str();
    };

}