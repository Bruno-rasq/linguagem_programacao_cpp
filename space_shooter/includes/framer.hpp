#ifndef __FRAMER__HPP__
#define __FRAMER__HPP__

#include "./core_std.hpp"

namespace framerHandler
{

    /**
     * coordenada x(linha) - y(coluna) - char(obj)
     */
    struct Sprite
    {

        Coord_row x;
        Coord_col y;
        Obj_ascii obj;

        Sprite();
        Sprite(Coord_row x, Coord_col y, Obj_ascii obj);
    };

    class Framerbuffer
    {
    private:
        Frame frame;

    public:
        Framerbuffer();
        void draw(const Sprite &sprite);
        void clear(const Sprite &sprite);
        void render() const;
    };
};

#endif