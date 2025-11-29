#ifndef __COLLISIONS__HPP__
#define __COLLISIONS__HPP__

#include "core_std.hpp"
#include "moviment.hpp"
#include "framer.hpp"
#include "asteroids.hpp"

namespace Collision_handler
{
    /* tipos de objetos que o sistema de colisão trabalha. */
    enum objtype { Asteroid, Shoot, Player };

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

    typedef std::vector<IDs> collections;
    typedef framerHandler::Sprite Sprite;
    typedef movimenthandler::Coord Coord;
    typedef std::vector<movimenthandler::Projectil> Shoots;
    typedef std::vector<asteroidhandler::Asteroid> Asteroids;


    /**
     *  Metodos de colisão devem seguir uma ordem de precedencia
     *  sendo primeiro colisão de asteroid com player (fim de game.)
     *  depois colisão de projeteis em asteroids, asteroids com asteroids
     *  e por fim projeteis com o player
    */
    void collisionAsteroidxPlayer(bool &game_is_running);
    void collisionAsteroidxShoot();
    void collisionAsteroidxAsteroid(asteroidhandler::Asteroid& a, asteroidhandler::Asteroid& b);
    void collisionPlayerxShoot();

   
    /**
     *  Para checar colisão é criado um hashmapque armazena as coordenadas
     *  dos objetos do game, e um vetor de IDS. Quando uma chave possue 
     *  mais de um objeto ocorre uma colisão. 
     * 
     *  Coodenadas xy passam por uma função hash que tranforma em um
     *  inteiro.
     * 
     *  Alem disso é criado um hash de objetos já processados para cada co-
     *  lisão, assim evita multiplas aplicações de colisão em um omesmo ob-
     *  jeto por instancia do frame
    */
    void checkCollisions(

        // estados
        bool &game_on, /* capacidade de parar o game caso necessário. */

        // objetos
        Sprite &player,
        Asteroids &asteroids,
        Shoots &shoots
    );
};

#endif