#ifndef __MOVIMENT__HPP__
#define __MOVIMENT__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"

namespace movimenthandler
{

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

    /**
     *  Estrutura de coordenada dos objetos do game armazena o indice x
     *  (linha) e y (coluna) do frame onde o objeto está.
    */
    struct Coord
    {

        Coord_row x;
        Coord_col y;

        Coord();
        Coord(Coord_row x, Coord_col y);

        void delta(const Coord_row dx, const Coord_col dy);

        bool operator==(const Coord &other) const;
    };

    /**
     *  Estrutura spaceship  armazena a posição visual do player, sendo
     *  capaz de representar a direção que o player está virado (sendo 
     *  esta tambem a direção em que projeteis são disparados.)
    */
    struct Spaceship
    {

        Coord coord;
        Spaceshipface shipFacing;

        Spaceship();

        /**
         *  1(cima)
         *  2(baixo)
         *  3(esquerda)
         *  4(direita)
         */
        void changeFacing(const Direction dir); // privado

        void moveSpaceship(const Coord delta, const Direction dir);

        Sprite getSprite() const;
    };

    /**
     *  Estrutura de projeteis armazena as instancias de disparor feitos
     *  pelo player, cada disparo possue uma coordenada, um sentido de 
     *  movimento e um total de dano.
     * 
     *  Priojeteis que saem dos limites do grid (frame) são destruidos.
    */
    struct Projectil
    {

        Coord coord;
        Direction dir; // controla para aonde deve atualizar a coordenada
        Obj_ascii obj; // obj é baseado na direçaõ do projetil

        Projectil(const Coord coord, const Spaceshipface &dir);

        void updateCoord();

        Sprite getSprite() const;
    };

    /* verifica se a coordenada esta dentro dos limites do frame */
    bool inBounds(const Coord &coord);

    /* desloca a coordenada para o outro lado do frame assim que sair do
    limite do grid*/
    void wrap_around(int8_t &x, int8_t &y);
};

#endif