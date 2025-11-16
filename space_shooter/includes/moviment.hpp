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

        /**
         * (-1, 0) -> para cima
         * (1, 0)  -> para baixo
         * (0, -1) -> para esquerda
         * (0, 1)  -> para direita
        */
        void delta(const Coord_row dx, const Coord_col dy);
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

    // nao sei se vai ser util ainda....
    const std::unordered_map<std::string, Coord> DELTAS = {
        
        {"cima",        Coord(-1,  0)},
        {"baixo",       Coord(1,   0)},
        {"esquerda",    Coord(0,  -1)},
        {"direita",     Coord(0,   1)},

        {"diagonal1",   Coord(1,   1)}, //top (esquerda) -> base (direita)
        {"diagonal2",   Coord(1,  -1)}, //top (direita) -> base (esquerda)
        {"diagonal3",   Coord(-1,  1)}, //base (esquerda) -> top (direita)
        {"diagonal4",   Coord(-1, -1)}, //base (direita) -> top (esquerda)
    };

    Coord get_random_coord();
};

#endif