#include "collision.hpp"

/*
    ------------------------------------------------------
    |                 funções hash                       |
    ------------------------------------------------------
*/

/* função que gera uma chave hash com base em uma coordenada x y. */
struct CoordHash
{
    size_t operator()(const Coord &c) const noexcept
    {
        return (c.x << 8) ^ c.y;
    }
};

/* função que gera uma chave unica para cada objeto do grid de colisão. */
size_t objHash(const Collection &objeto)
{
    return (objeto.collection_type << 8) ^ objeto.index_object;
}


typedef std::unordered_map<Coord, Collections, CoordHash> gridCollisionHash;

/*
    ------------------------------------------------------
    |                 funções auxiliares                 |
    ------------------------------------------------------
*/

void add_player_object(Sprite &plyr, processedObjects& p, gridCollisionHash& gc)
{
    Collection obj = {Collision_handler::objtype::PlayerC, -1};

    gc[{plyr.x, plyr.y}].push_back(obj);
    p[objHash(obj)] = false;
};

void add_asteroid_objects(
    Asteroids& asteroids, processedObjects& p, gridCollisionHash& gc)
{
    for (int i = 0; i < asteroids.size(); i++)
        for (Sprite &rock : asteroids[i].rocks)
        {
            Collection obj = {Collision_handler::objtype::AsteroidC, i};

            gc[{rock.x, rock.y}].push_back(obj);
            p[objHash(obj)] = false;
        }
};

void add_shoot_objects(
   Shoots& shoots, processedObjects& p, gridCollisionHash& gc)
{
    for (int i = 0; i < shoots.size(); i++)
    {
        Collection obj = {Collision_handler::objtype::ShootC, i};
        
        gc[{shoots[i].coord}].push_back(obj);
        p[objHash(obj)] = false;
    }
};


/*
    ------------------------------------------------------
    |                 funções de colisão                 |
    ------------------------------------------------------
*/

namespace Collision_handler
{

    void collisionAsteroidxAsteroid(Asteroid& a, Asteroid& b)
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

    /**
     *  Para evitar calcular dado de disparo, total de vida do asteroids e afins
     *  optei por usar um contador, indicando quantos disparos o player tem que 
     *  acertar para destruir um asterois.
     * 
     *  1 disparo => asteroide pequeno
     *  3 disparos => asteroide medio
     *  5 disparos => asteroide grande
     * 
     *  disparos são removidos sempre.
    */
    void collisionAsteroidxShoot(Asteroids& a, Shoots& s, size_t aidx, size_t sidx)
    {
        a[aidx].count -= 1;
        if(a[aidx].count == 0)
        {
            std::swap(a[aidx], a.back());
            a.pop_back();
        }
        
        std::swap(s[sidx], s.back());
        s.pop_back();
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
                    if(A == objtype::AsteroidC && B == objtype::PlayerC ||
                       B == objtype::AsteroidC && A == objtype::PlayerC)
                    {
                        game_on = false;
                        return;
                    }

                    if(A == objtype::AsteroidC && B == objtype::ShootC ||
                       B == objtype::AsteroidC && A == objtype::ShootC)
                    {
                        int idx_asteroid = vec[i].collection_type == objtype::AsteroidC ? 
                            vec[i].index_object : vec[j].index_object;

                        int idx_shoot = vec[i].collection_type == objtype::ShootC ?
                            vec[i].index_object : vec[j].index_object;

                        collisionAsteroidxShoot(asteroids, shoots, idx_asteroid, idx_shoot);
                    }
                }
        }
    };
}