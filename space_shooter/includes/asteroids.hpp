#ifndef __ASTEROIDS__HPP__
#define __ASTEROIDS__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"
#include "./moviment.hpp"

namespace asteroidhandler {

    // deve haver 3 tipos de asteroids (pequeno, medio e grande).
    // devem ser criados de forma randomica (1 chance em 6).
    // devem ser capaz de se movimentar horizontalmente, verticalmente e
    // diagonalmente.
    // deve conter 3 tipos de colisões:
    //  - auto colisão (maior prevalce e o menor é destruido)
    //  - colisao contra o player (causa dado no player)
    //  - colisao contra naves inimigas.
    // asteroids devem ser criados fora do frame game.
    
    typedef std::vector<framerHandler::Sprite> Rocks;
    typedef movimenthandler::Coord Coord;

    struct AsteroidInfo { int8_t x, y, dx, dy; };
    
    struct Asteroid {

        Rocks rocks;
        Coord delta_direction;     // indica o sentido de deslocamento.
        bool has_entered = false;  // indica se já esteve dentro do frame.

        Asteroid(const Rocks rocks, Coord direction);

        void update_coord();
    };


    Asteroid create_small_asteroid(int8_t x, int8_t y, Coord delta);
    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta);
    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta);

    Asteroid create_random_asteroid();
    
};

#endif