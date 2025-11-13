#ifndef __MOVIMENT__HPP__
#define __MOVIMENT__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"

namespace movimenthandler {

    struct Coord {

        Coord_row x;
        Coord_col y;

        Coord();
        Coord(Coord_row x, Coord_col y);

        void delta(const Coord_row dx, const Coord_col dy);
    };

    struct Spaceship {

        Coord coord;
        Spaceshipface shipFacing;

        Spaceship();
       
        void changeFacing(const Direction dir);
        void moveSpaceship(const Coord delta, const Direction dir);
        framerHandler::Sprite getSprite() const;
    };

    struct Projectil {

        Coord coord;
        Direction dir;
        Obj_ascii obj;

        Projectil(const Coord coord, const Spaceshipface& dir);
        void updateCoord();
        framerHandler::Sprite getSprite() const;
    };

    bool inBounds(const Coord& coord);
};

#endif