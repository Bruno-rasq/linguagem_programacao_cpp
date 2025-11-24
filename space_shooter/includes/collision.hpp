#ifndef __COLLISIONS__HPP__
#define __COLLISIONS__HPP__

#include "core_std.hpp"
#include "moviment.hpp"
#include "framer.hpp"
#include "asteroids.hpp"

namespace Collision_handler
{

    enum objtype
    {
        Asteroid,
        Shoot,
        Player
    };

    struct IDs
    {
        objtype collection_type;
        int index_object;
    };

    typedef std::vector<IDs> collections;
    typedef framerHandler::Sprite Sprite;
    typedef std::vector<asteroidhandler::Asteroid> Asteroids;
    typedef std::vector<movimenthandler::Projectil> Shoots;

    void collisionAsteroidxPlayer(bool &game_is_running);
    void collisionAsteroidxAsteroid();
    void collisionAsteroidxShoot();
    void collisionPlayerxShoot();

    // Para cada objeto na instancia do game a checagem de colisão
    // consiste em guardar em um hashmap para cada objeto uma chave
    // sendo a coordenada xy do mesmto e ums estrutura de IDs (id da
    // coleção e o id do obj). Assim quando uma coordenada tiver mais
    // de um objeto significa que houve uma colisão.
    // complexidade - O(n)
    void checkCollisions(

        // estados
        bool &game_onoff,

        // objetos
        Sprite &player,
        Asteroids &asteroids,
        Shoots &shoots);
};

#endif