#include "collision.hpp"

// função que gera uma chave hash com base em uma coordenada x y.
struct CoordHash {
    size_t operator()(const movimenthandler::Coord& c) const noexcept {
        return (c.x << 8) ^ c.y;
    }
};

typedef std::unordered_map<
    movimenthandler::Coord, 
    Collision_handler::collections, 
    CoordHash> gridCollisionHash;

namespace Collision_handler {

    void collisionAsteroidxPlayer(bool& game_is_running){
        game_is_running = false;
    };

    void checkCollisions(bool& game_onoff, Sprite& player, Asteroids& asteroids, Shoots& shoots){

        gridCollisionHash collisiongrid;

        /*
            TODO: ideia criar um hash de objetos processados 
            isso evita multiplas colições para objetos com mais de 
            1 sprite.

            cada objeto possue uma collecao a qual pertence e um index
            posso usar esses dados para gerar uma chave hash e deixar a 
            verificação se um objeto ja foi processado em tempo constante.
        */

        // adicionando objeto do player.
        collisiongrid[{player.x, player.y}].push_back({objtype::Player, -1});

        // adicionando objetos dos asteroides.
        for(int i = 0; i < asteroids.size(); i++)
            for(Sprite& rock : asteroids[i].rocks)
                collisiongrid[{rock.x, rock.y}].push_back({objtype::Asteroid, i});

        // adicionando objetos dos disparos.
        for(int i = 0; i < shoots.size(); i++)
            collisiongrid[{shoots[i].coord}].push_back({objtype::Shoot, i});


        // checar cada coordenada salva no hash para verificar se houve colisão
        for(auto& kv: collisiongrid){
            auto& vec = kv.second;

            if(vec.size() < 2) continue;

            for(int i = 0; i < vec.size(); i++)
                for(int j = i + 1; j < vec.size(); j++){

                    objtype A = vec[i].collection_type;
                    objtype B = vec[j].collection_type;

                    // Asteroid x Player
                    if(A == objtype::Asteroid && B == objtype::Player || 
                    B == objtype::Asteroid && A == objtype::Player){
                        collisionAsteroidxPlayer(game_onoff);
                    }
                }
        }
    };
}