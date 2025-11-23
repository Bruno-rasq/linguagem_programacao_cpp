#ifndef __COLLISIONHDR__HPP__
#define __COLLISIONHDR__HPP__

#include <unordered_map> 
#include "core_std.hpp" 
#include "moviment.hpp"
#include "asteroids.hpp"
#include "player.hpp"

typedef movimenthandler::Coord Coord_T;
typedef movimenthandler::Projectil Shoot_T;
typedef asteroidhandler::Asteroid  Asteroid_T;
typedef std::vector<Shoot_T> shoots;
typedef std::vector<Asteroid_T> asteroids;

namespace CollisonHDR {

    enum objtype { Coord_T, Shoot_T, Player_T, Asteroid_T };

    void collisionAsteroidxPlayer();
    void collisionAsteroidxAsteroid();
    void collisionAsteroidxShoot();
    void collisionPlayerxShoot();

    struct IDs {
        objtype collectionKey;    // a qual coleção o objeto pertence
        int objectkey;            // sua chave da coleção
    };

    // função que gera uma chave hash com base em uma coordenada x y.
    struct CoordHash {
        size_t operator()(const movimenthandler::Coord& c) const noexcept;
    };

    // Para cada objeto na instancia do game a checagem de colisão 
    // consiste em guardar em um hashmap para cada objeto uma chave
    // sendo a coordenada xy do mesmto e ums estrutura de IDs (id da
    // coleção e o id do obj). Assim quando uma coordenada tiver mais
    // de um objeto significa que houve uma colisão. 
    // complexidade - O(n)
    void checkCollisions(asteroids& a, shoots& s, Player& player);

};

#endif