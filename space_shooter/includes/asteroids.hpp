#ifndef __ASTEROIDS__HPP__
#define __ASTEROIDS__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"
#include "./moviment.hpp"

namespace asteroidhandler {

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

    struct Asteroid {

        Rocks rocks;
        Coord delta_direction;     // indica o sentido de deslocamento.
        uint8_t size;               // 1(pequeno) - 2(medio) - 3(grande)

        Asteroid(const Rocks rocks, Coord direction, uint8_t size);

        void update_coord();
    };

    Asteroid create_small_asteroid(int8_t x, int8_t y, Coord delta);
    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta);
    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta);
    
    void change_asteroid_direction_after_colission();

    void split_asteroid_after_colission();
};

#endif