#include "collisionhdr.hpp"

namespace CollisonHDR {

    void collisionAsteroidxPlayer(){
        std::cout << "colisao asteroid x player\n";
    };
    void collisionAsteroidxAsteroid(){
        std::cout << "colisao asteroid x asteroid\n";
    };
    void collisionAsteroidxShoot(){
        std::cout << "colisao asteroid x shoot\n";
    };
    void collisionPlayerxShoot(){
        std::cout << "colisao shoot x player\n";
    };

    size_t CoordHash::operator()(const movimenthandler::Coord& c) const noexcept {
        return (c.x << 8) & c.y;
    };

    void checkCollisions(asteroids& a, shoots& s, Player& player){

        // Hash map que armazena para cada espaço no frame (coordenada xy) uma coleção de 
        // objetos ocupando aquele espaço e validando colisão.
        std::unordered_map<movimenthandler::Coord, std::vector<IDs>, CoordHash> collisionGrid;

        // inserir o player:
        collisionGrid[player.coord].push_back({objtype::Player_T, -1});

        // inerir asteroides:
        for(int i = 0; i < a.size(); i++)
            collisionGrid[a[i].centro].push_back({objtype::Asteroid_T, i});

        // inserir projetils:
        for(int i = 0; i < s.size(); i++)
            collisionGrid[s[i].coord].push_back({objtype::Shoot_T, i});

        // validar colisões:
        for(auto& kv: collisionGrid){
            auto vec = kv.second;

            // se não houver mais de um objeto por coordenada então sem colisão.
            if(vec.size() < 2) continue;

            // checar todos contra todos.
            for(int i = 0; i < vec.size(); i++){
                for(int j = i + 1; j < vec.size(); j++){

                    objtype A = vec[i].collectionKey;
                    objtype B = vec[j].collectionKey;

                    // Asteroid x Player
                    if(A == objtype::Asteroid_T && B == objtype::Player_T || 
                    B == objtype::Asteroid_T && A == objtype::Player_T){
                        collisionAsteroidxPlayer();
                    }

                    // Asteroid x Asteroid
                    if(A == objtype::Asteroid_T && B == objtype::Asteroid_T || 
                    B == objtype::Asteroid_T && A == objtype::Asteroid_T){
                        collisionAsteroidxAsteroid();
                    }

                    // Asteroid x shoot
                    if(A == objtype::Asteroid_T && B == objtype::Shoot_T || 
                    B == objtype::Asteroid_T && A == objtype::Shoot_T){
                        collisionAsteroidxShoot();
                    }

                    // Player x shoot
                    if(A == objtype::Player_T && B == objtype::Shoot_T || 
                    B == objtype::Player_T && A == objtype::Shoot_T){
                        collisionPlayerxShoot();
                    }
                }
            }
                
        }
    };
}