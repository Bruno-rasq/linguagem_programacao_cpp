#include "collision.hpp"

/*
    ------------------------------------------------------
    |                 funções hash                       |
    ------------------------------------------------------
*/

/* função que gera uma chave hash com base em uma coordenada x y. */
struct CoordHash
{
    size_t operator()(const movimenthandler::Coord &c) const noexcept
    {
        return (c.x << 8) ^ c.y;
    }
};

/* função que gera uma chave unica para cada objeto do grid de colisão. */
size_t objHash(const Collision_handler::IDs &objeto)
{
    return (objeto.collection_type << 8) ^ objeto.index_object;
}

typedef std::unordered_map<
    movimenthandler::Coord,
    Collision_handler::collections,
    CoordHash>
    gridCollisionHash;

typedef std::unordered_map<size_t, bool> processedObjects;

/*
    ------------------------------------------------------
    |                 funções auxiliares                 |
    ------------------------------------------------------
*/

void add_player_object(framerHandler::Sprite &plyr, processedObjects& p, gridCollisionHash& gc)
{
    Collision_handler::IDs objectID = {Collision_handler::objtype::Player, -1};

    gc[{plyr.x, plyr.y}].push_back(objectID);
    p[objHash(objectID)] = false;
};

void add_asteroid_objects(
    std::vector<asteroidhandler::Asteroid>& asteroids, 
    processedObjects& p, gridCollisionHash& gc)
{
    for (int i = 0; i < asteroids.size(); i++)
        for (framerHandler::Sprite &rock : asteroids[i].rocks)
        {
            Collision_handler::IDs objectID = {Collision_handler::objtype::Asteroid, i};
            gc[{rock.x, rock.y}].push_back(objectID);
            p[objHash(objectID)] = false;
        }
};

void add_shoot_objects(
    std::vector<movimenthandler::Projectil>& shoots, processedObjects& p, gridCollisionHash& gc)
{
    for (int i = 0; i < shoots.size(); i++)
    {
        Collision_handler::IDs objectID = {Collision_handler::objtype::Shoot, i};
        gc[{shoots[i].coord}].push_back(objectID);
        p[objHash(objectID)] = false;
    }
};


/*
    ------------------------------------------------------
    |                 funções de colisão                 |
    ------------------------------------------------------
*/

namespace Collision_handler
{

    void collisionAsteroidxAsteroid(asteroidhandler::Asteroid& a, asteroidhandler::Asteroid& b)
    {
        struct Relative_coord { uint8_t x, y; }; 
        /* vetor relativo a posição dos asteroids */
        Relative_coord rel = {
            static_cast<uint8_t>(b.delta_direction.x - a.delta_direction.x),
            static_cast<uint8_t>(b.delta_direction.y - a.delta_direction.y),
        };

        /* 1 - colisão frontal: deltas opostos. */
        if(a.delta_direction.x == -b.delta_direction.x 
        && a.delta_direction.y == -b.delta_direction.y)
        {
            Coord deltaA = a.delta_direction;
            Coord deltaB = b.delta_direction;
            a.delta_direction = deltaB;
            b.delta_direction = deltaA;
            return;
        }

        uint8_t ax = std::abs(rel.x);
        uint8_t ay = std::abs(rel.y);

        /* 2 - impacto dominante no eixo x */
        if(ax > ay)
        {
            a.delta_direction.x = -a.delta_direction.x;
            b.delta_direction.x = -b.delta_direction.x;
            return;
        }

        /* 3 - impacto dominante no eixo y */
        if(ay > ax)
        {
            a.delta_direction.y = -a.delta_direction.y;
            b.delta_direction.y = -b.delta_direction.y;
            return;
        }

        /* 4 - colisão em diagonal */
        a.delta_direction.x = -a.delta_direction.x;
        b.delta_direction.x = -b.delta_direction.x;
        a.delta_direction.y = -a.delta_direction.y;
        b.delta_direction.y = -b.delta_direction.y;
    };

    void checkCollisions(bool &game_on, Sprite &player, Asteroids &asteroids, Shoots &shoots)
    {

        /*
            objetos terão seus valores hasheados e armazenados em uma hashmap 
            espacial, assim que uma coordenada x y apresentar mais de um objeto
            valida colisão.
        */
        gridCollisionHash collisiongrid;

        /*
            Apos uma colisão os objetos são marcados como já processados, isso 
            evita multiplas colisões acontecendo em um mesmo objeto.
        */
        processedObjects processed;

        
        add_player_object(player, processed, collisiongrid);
        add_asteroid_objects(asteroids, processed, collisiongrid);
        add_shoot_objects(shoots, processed, collisiongrid);


        /* checar cada coordenada salva no hash para verificar se houve colisão */
        for (auto &kv : collisiongrid)
        {
            auto &vec = kv.second;

            /* se não houver mais de 1 objeto na coordenada então não houve colisão. */
            if (vec.size() < 2) continue;

            for (int i = 0; i < vec.size(); i++)
                for (int j = i + 1; j < vec.size(); j++)
                {

                    /* se objeto já fsofreu uma colisão antes nao processe novamente. */
                    if (processed[objHash(vec[i])] || processed[objHash(vec[j])])
                        continue;

                    /* marca os objetos como já colididos. */
                    processed[objHash(vec[i])] = true;
                    processed[objHash(vec[j])] = true;

                    objtype A = vec[i].collection_type;
                    objtype B = vec[j].collection_type;

                    // Asteroid x Player
                    if(A == objtype::Asteroid && B == objtype::Player ||
                       B == objtype::Asteroid && A == objtype::Player)
                    {
                        game_on = false;
                        return;
                    }

                    if(A == objtype::Asteroid && B == objtype::Shoot ||
                       B == objtype::Asteroid && A == objtype::Shoot)
                    {
                        int idx_asteroid = vec[i].collection_type == objtype::Asteroid ? 
                            vec[i].index_object : vec[j].index_object;

                        int idx_shoot = vec[i].collection_type == objtype::Shoot ?
                            vec[i].index_object : vec[j].index_object;

                        std::swap(asteroids[idx_asteroid], asteroids.back());
                        std::swap(shoots[idx_shoot], shoots.back());

                        asteroids.pop_back();
                        shoots.pop_back();
                    }
                }
        }
    };
}