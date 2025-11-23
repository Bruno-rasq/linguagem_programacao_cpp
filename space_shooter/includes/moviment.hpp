#ifndef __MOVIMENT__HPP__
#define __MOVIMENT__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"

namespace movimenthandler {

    /**
     *  variacoes de movimento
     * 
     * (-1,  0) -> para cima
     * (1,   0) -> para baixo
     * (0,  -1) -> para esquerda
     * (0,   1) -> para direita
     * (1,   1) -> top (esquerda) -> base (direita)
     * (1,  -1) -> top (direita) -> base (esquerda)
     * (-1,  1) -> base (esquerda) -> top (direita)
     * (-1, -1) -> base (direita) -> top (esquerda)
    */

    struct Coord {

        Coord_row x;
        Coord_col y;

        Coord();
        Coord(Coord_row x, Coord_col y);

        void delta(const Coord_row dx, const Coord_col dy);

        // remover se naõ der certo
        bool operator==(const Coord& other) const;
    };

    struct Spaceship {

        Coord coord;
        Spaceshipface shipFacing;

        Spaceship();
       
       /**
        *  1(cima)
        *  2(baixo)
        *  3(esquerda)
        *  4(direita)
       */
        void changeFacing(const Direction dir); //privado

        void moveSpaceship(const Coord delta, const Direction dir);

        framerHandler::Sprite getSprite() const;
    };

    struct Projectil {

        Coord coord;
        Direction dir; //controla para aonde deve atualizar a coordenada
        Obj_ascii obj; //obj é baseado na direçaõ do projetil 

        Projectil(const Coord coord, const Spaceshipface& dir);

        void updateCoord();

        framerHandler::Sprite getSprite() const;
    };

    bool inBounds(const Coord& coord); // verifica se a coordenada esta dentro dos limites do frame

    void wrap_around(int8_t& x, int8_t& y);
};

#endif