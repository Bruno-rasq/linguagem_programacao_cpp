#ifndef __CORE__TYPES__HPP__
#define __CORE__TYPES__HPP__

#include "core_std.hpp"

/*
    ------------------------------------------------------
    |           foward declaration                       |
    ------------------------------------------------------
*/

namespace movimenthandler {
    struct Coord;
    struct Spaceship;
    struct Projectil;
};

namespace framerHandler {
    struct Sprite;
    struct framer_buffer;
};

namespace asteroidhandler { struct Asteroid; }
namespace Collision_handler { struct IDs; }


/*
    ------------------------------------------------------
    |                 definições de tipo                 |
    ------------------------------------------------------
*/

namespace TYPING {

    /* Definições do modulo de movimento. */
    using Coord = movimenthandler::Coord;
    using Spaceship = movimenthandler::Spaceship;
    using Shoot = movimenthandler::Projectil;
    using Shoots = std::vector<Shoot>;

    /* Definições do modulo de framer. */
    using Sprite = framerHandler::Sprite;
    using FB = framerHandler::framer_buffer;
    using Rocks = std::vector<Sprite>; /*uitlizado em asteroids*/

    /* definições do movulo de asteroids. */
    using Asteroid = asteroidhandler::Asteroid;
    using Asteroids = std::vector<Asteroid>;

    /* definições de coleções para modulo de colisão. */
    using Collection = Collision_handler::IDs;
    using Collections = std::vector<Collection>;
    using processedObjects = std::unordered_map<size_t, bool>;


    /* tipos auxiliares. */
    using Buffer = std::stringstream;
    using Frame = std::vector<std::string>;

    using Coord_row = int8_t;      
    using Coord_col = int8_t;

    /* 1=cima, 2=baixo 3=esquerda, 4=direita */
    using Direction = uint8_t;
    using WinKeyState = uint16_t;

    using Obj_ascii = char;
    using Spaceshipface = char;

    using Lifes = std::vector<bool>;
};

#endif