#ifndef __ASTEROIDS__HPP__
#define __ASTEROIDS__HPP__

#include "core_std.hpp"
#include "core_types.hpp"

#include "framer.hpp"
#include "moviment.hpp"

using namespace TYPING;

namespace asteroidhandler
{

    /**
     *  Estruturas de Asteroids seguem um modelo padrão mas com diferenças
     *  de valores dos dados. Cada instancia possue um vetor de Sprites de
     *  cada pedra que compoe o asteroide, sendo que cada sprite possue uma
     *  coordenada xy e um char ASCII. 
     * 
     *  Alem disse há uma coordenada especial (delta) referente ao sentido
     *  de deslocamento do asteroid, sentido esse que pode ser modificado 
     *  assim que ococrrer uma colisão asteroid x asteroid
     * 
     *  Os asteroides possuem uma contador de resistencia que indica quanto
     *  disparos o player deve acertar até destruir um asteroide.
     * 
     *  1 disparo => asteroide pequeno
     *  3 disparos => asteroide medio
     *  5 disparos => asteroide grande
    */
    struct Asteroid
    {

        asteroidsize size;

        Rocks rocks;           
        Coord delta_direction;
        size_t hitscount;

        Asteroid(const Rocks rocks, const Coord direction, size_t count, asteroidsize size);

        void update_coord();
    };

    /**
     *  Funções que criam um asteroid de um tamanho diferente.
    */
    Asteroid create_small_asteroid(int8_t x, int8_t y, Coord delta);
    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta);
    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta);

};

#endif