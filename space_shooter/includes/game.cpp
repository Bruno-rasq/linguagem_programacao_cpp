#include "./game.hpp"

Game::Game(){

    this->player = Player();
    this->framebuffer = Framer();
    this->playersprite = this->player.getSprite();

    // teste
    this->asteroids = {
        asteroidhandler::create_large_asteroid(3, 5, Coord(1, 1)),
        asteroidhandler::create_medium_asteroid(13, 5, Coord(-1, 0)),
        asteroidhandler::create_small_asteroid(10, 65, Coord(-1, -1)),
    };
};

void Game::start(){

    this->framebuffer.draw(this->playersprite);
    this->resetConsoleFrame();

    // o game inteiro acontece aqui.
    while(this->running){

        Sleep(TIME_SLEEP);

        const WinKeyState key = Keyboardhandler::keypress();

        this->running = this->SwitchKeyPress(key);

        if(this->running){

            this->updateFrame();

            // problema não é aqui
            this->checkCollisions();

            this->resetConsoleFrame();
            this->timer.clock();
        }
    }

    this->resetConsoleFrame();
};

void Game::resetConsoleFrame() const {
    system("cls");
    this->framebuffer.render();
};

void Game::updateFrame(){

    this->updatePlayerCoord();
    this->updateAsteroidsCoord();
    this->updateShootsCoord();
};

void Game::updateShootsCoord(){

    size_t idx = 0;

    while(true){

        if(idx >= this->frameshoot.size()) break;

        Shoot& shoot = this->frameshoot[idx];
    
        this->framebuffer.clear(shoot.getSprite());

        shoot.updateCoord();

        if(!movimenthandler::inBounds(shoot.coord)){
            std::swap(this->frameshoot[idx], this->frameshoot.back());
            this->frameshoot.pop_back();
            continue;
        }

        this->framebuffer.draw(shoot.getSprite());
        idx++;
    }
};

void Game::updateAsteroidsCoord(){

    if(this->timer.asteroid_clock == 0){
        for(Asteroid& asteroid : this->asteroids){

            for(Sprite& rock : asteroid.rocks)
                this->framebuffer.clear(Sprite(rock.x, rock.y, rock.obj));
            
            asteroid.update_coord();

            for(Sprite& rock : asteroid.rocks)
                this->framebuffer.draw(Sprite(rock.x, rock.y, rock.obj));
        }
        this->timer.resetAsteroid();
    }
};

void Game::updatePlayerCoord(){
    this->framebuffer.clear(this->playersprite);
    this->playersprite = this->player.getSprite();
    this->framebuffer.draw(this->playersprite);
};

bool Game::SwitchKeyPress(const WinKeyState keypressed){

    if(keypressed == VK_ESCAPE) return false;
    if(keypressed == 0) return true;                 // teclas não mapeadas (ou sem movimentacao)
    if(keypressed == VK_SPACE){                 // espaço para atirar
        Shoot shoot = this->player.attack();
        this->frameshoot.push_back(shoot);
        return true;
    }
    this->player.move(keypressed);              // executa um movimento.
    return true;
};




// TESTE -----------------

enum objtype { Shoot_T, Player_T, Asteroid_T };

struct IDs {
    objtype collectionKey;    // a qual coleção o objeto pertence
    int objectkey;            // sua chave da coleção
};

// função que gera uma chave hash com base em uma coordenada x y.
struct CoordHash {
    size_t operator()(const movimenthandler::Coord& c) const noexcept {
        return (c.x << 8) ^ c.y;
    }
};

void Game::checkCollisions(){

    std::unordered_map<movimenthandler::Coord, std::vector<IDs>, CoordHash> collisiongrid;

    // inserir player
    Sprite p = this->playersprite;
    collisiongrid[{p.x, p.y}].push_back({objtype::Player_T, -1});

    // inserir asteroids:
    for(int i = 0; i < this->asteroids.size(); i++)
        for(Sprite& rock : this->asteroids[i].rocks){
            collisiongrid[{rock.x, rock.y}].push_back({objtype::Asteroid_T, i});
        }

    // // inserir shoots 
    // for(int i = 0; i < this->frameshoot.size(); i++)
    //     collisiongrid[this->frameshoot[i].coord].push_back({objtype::Shoot_T, i});

    // checar colisão
    for(auto& kv: collisiongrid){
        auto& vec = kv.second;

        if(vec.size() < 2) continue;

        for(int i = 0; i < vec.size(); i++)
            for(int j = i + 1; j < vec.size(); j++){

                objtype A = vec[i].collectionKey;
                objtype B = vec[j].collectionKey;

                // Asteroid x Player
                if(A == objtype::Asteroid_T && B == objtype::Player_T || 
                B == objtype::Asteroid_T && A == objtype::Player_T){
                    this->running = false;
                    return;
                }

                // // Asteroid x Asteroid
                // if(A == objtype::Asteroid_T && B == objtype::Asteroid_T || 
                // B == objtype::Asteroid_T && A == objtype::Asteroid_T){
                //     std::cout << "collision asteroid x asteroid\n";
                // }

                // Asteroid x shoot
                // if(A == objtype::Asteroid_T && B == objtype::Shoot_T || 
                // B == objtype::Asteroid_T && A == objtype::Shoot_T){

                //     size_t idx;

                //     if(A == objtype::Asteroid_T) idx = vec[i].objectkey;
                //     if(B == objtype::Asteroid_T) idx = vec[j].objectkey;

                //     std::swap(this->asteroids[idx], this->asteroids.back());
                //     this->asteroids.pop_back();

                // }

                // // Player x shoot
                // if(A == objtype::Player_T && B == objtype::Shoot_T || 
                // B == objtype::Player_T && A == objtype::Shoot_T){
                //     std::cout << "collision shoot x player\n";
                // }
            }
    }
};