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
    Collection obj = {objtype::Player_T, -1};

    gc[{plyr.x, plyr.y}].push_back(obj);
    p[objHash(obj)] = false;
};

void add_asteroid_objects(
    Asteroids& asteroids, processedObjects& p, gridCollisionHash& gc)
{
    for (int i = 0; i < asteroids.size(); i++)
        for (Sprite &rock : asteroids[i].rocks)
        {
            Collection obj = {objtype::Asteroid_T, i};

            gc[{rock.x, rock.y}].push_back(obj);
            p[objHash(obj)] = false;
        }
};

void add_shoot_objects(
   Shoots& shoots, processedObjects& p, gridCollisionHash& gc)
{
    for (int i = 0; i < shoots.size(); i++)
    {
        Collection obj = {objtype::Shoot_T, i};
        
        gc[{shoots[i].coord}].push_back(obj);
        p[objHash(obj)] = false;
    }
};


/*
    ------------------------------------------------------
    |                 funções de colisão                 |
    ------------------------------------------------------
*/

Collisions checkCollisions(
    Sprite& player, Asteroids& asteroids, Shoots& shoots)
{

    Collisions checkedcollisions;

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
        {
            for (int j = i + 1; j < vec.size(); j++)
            {
                size_t hash1 = objHash(vec[i]);
                size_t hash2 = objHash(vec[j]);

                /* se objeto já fsofreu uma colisão antes nao processe novamente. */
                if (processed[hash1] || processed[hash2]) continue;

                /* marca os objetos como já colididos. */
                processed[hash1] = true;
                processed[hash2] = true;

                checkedcollisions.push_back({vec[i], vec[j]});
            }
        }
    }

    return checkedcollisions;
};