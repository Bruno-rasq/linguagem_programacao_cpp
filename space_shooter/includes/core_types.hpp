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


    /* definições do modulo de asteroids. */
    enum asteroidsize { LOW, MEDIUM, HIGH };

    using Asteroid = asteroidhandler::Asteroid;
    using Asteroids = std::vector<Asteroid>;



    /* definições de coleções para modulo de colisão. */
    /* tipos de objetos que o sistema de colisão trabalha. */
    enum objtype { Asteroid_T, Shoot_T, Player_T };

    /**
     *  estruturas IDs armazenam dados que auxiliam na identificação
     *  do objeto que esta sendo tratado. O primeiro valor é o tipo do
     *  do objeto ja o segundo qual o index dele na referencia da coleção.
    */
    struct IDs
    {
        objtype collection_type;
        int index_object;
    };

    struct Collision 
    { 
        IDs object_1, object_2; 
    };

    using Collection = IDs;
    using Collections = std::vector<Collection>;
    using processedObjects = std::unordered_map<size_t, bool>;
    using Collisions = std::vector<Collision>;



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

    using Lifes_T = std::vector<bool>;
    using Scores_T = uint32_t;
};

#endif