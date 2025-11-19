#include "./game.hpp"

Game::Game(){

    this->player = Player();
    this->framebuffer = Framer();
    this->playersprite = this->player.getSprite();

    // teste
    this->asteroids = {
        asteroidhandler::create_large_asteroid(3, 5, Coord(1, 1)),
        asteroidhandler::create_medium_asteroid(13, 5, Coord(-1, 0)),
        asteroidhandler::create_small_asteroid(10, 65, Coord(1, -1)),
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
            if(this->check_colission_with_player()) break;
            this->resetConsoleFrame();
            this->timer.clock();
        }
    }

    this->resetConsoleFrame();
};

bool Game::check_colission_with_player(){

    Sprite plyer = this->playersprite;
    for(Asteroid& asteroid : this->asteroids)
        for(Sprite& rock : asteroid.rocks)
            if(rock.x == plyer.x && rock.y == plyer.y) 
                return true;
        
    return false;
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