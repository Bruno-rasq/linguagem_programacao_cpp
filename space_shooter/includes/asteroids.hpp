#ifndef __ASTEROIDS__HPP__
#define __ASTEROIDS__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"
#include "./moviment.hpp"

namespace asteroidhandler
{

    /**
     *  frame gid tenho 20 linhas por 70 colunas
     *  dividido por 4 setores tenho cada setor com 10 linhas e 35 colunas.
     *
     *  setor 0 - (top esquerdo):  x (0, 9) e y (0 34)
     *  setor 1 - (top direita):   x (0, 9) e y (35, 69)
     *  setor 2 - (base esquerdo): x (10, 19) e y (0 34)
     *  setor 3 - (base direita):  x (10, 19) e y (35 69)
     *
     */
    typedef framerHandler::Sprite Sprite;
    typedef movimenthandler::Coord Coord;
    typedef std::vector<Sprite> Rocks;


    /**
     *  Estruturas de Asteroids seguem um modelo padrão mas com diferenças
     *  de valores dos dados. Cada instancia possue um vetor de Sprites de
     *  cada pedra que compoe o asteroide, sendo que cada sprite possue uma
     *  coordenada xy e um char ASCII. 
     * 
     *  Alem disse há uma coordenada especial (delta) referente ao sentido
     *  de deslocamento do asteroid, sentido esse que pode ser modificado 
     *  assim que ococrrer uma colisão asteroid x asteroid
    */
    struct Asteroid
    {

        Rocks rocks;           
        Coord delta_direction;

        Asteroid(const Rocks rocks, const Coord direction);

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