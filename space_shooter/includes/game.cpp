#include "./game.hpp"


Game::Game()
{

    this->player = Player();
    this->playersprite = this->player.getSprite();
    this->asteroids = {
        asteroidhandler::create_large_asteroid(3, 5, Coord(1, 1)),
        asteroidhandler::create_medium_asteroid(13, 5, Coord(-1, 0)),
        asteroidhandler::create_small_asteroid(10, 65, Coord(-1, -1)),

        // asteroidhandler::create_small_asteroid(8, 65, Coord(-1, 1)),
        // asteroidhandler::create_small_asteroid(4, 35, Coord(1, -1)),
        // asteroidhandler::create_small_asteroid(2, 5, Coord(1, 0))
    };
};

void Game::start()
{
    FB start_frame;
    this->updateFrame(start_frame);
    this->RenderFrame(start_frame);

    // o game inteiro acontece aqui.
    while (this->running)
    {
        Sleep(TIME_SLEEP);

        const WinKeyState key = Keyboardhandler::keypress();

        this->running = this->SwitchKeyPress(key);

        if (this->running)
        {
            FB current_frame;
            this->updateFrame(current_frame);

            Collisions collisions = checkCollisions(
                this->playersprite, 
                this->asteroids, 
                this->frameshoot);
 
            this->collisionsResolver(collisions);
            this->RenderFrame(current_frame);
            this->timer.clock();
        }
    }

    FB end_frame;
    this->updateFrame(end_frame);
    this->writeEndgame(end_frame);
    this->RenderFrame(end_frame);
};


void Game::incrementScore(const uint8_t score)
{
    this->score += score;
};

void Game::decrementLife()
{
    size_t idx = TOTAL_LIFES - 1;
    while(true)
    {
        if(this->lifes[idx] == false)
        {
            idx--;
            continue;
        }

        this->lifes[idx] = false;
        if(idx == 0) this->running = false;
        break;
    }
};


/*
    ------------------------------------------------------
    |                 funções colisão                    |
    ------------------------------------------------------
*/

void Game::collisionsResolver(Collisions& collisions)
{
    for(Collision& collision : collisions)
    {
        objtype obt1 = collision.object_1.collection_type;
        objtype obt2 = collision.object_2.collection_type;

        if((obt1 == objtype::Asteroid_T || obt1 == objtype::Player_T) 
        && (obt2 == objtype::Asteroid_T || obt2 == objtype::Player_T))
            this->collisionAsteroidxPlayer(collision);

        if((obt1 == objtype::Asteroid_T || obt1 == objtype::Shoot_T) 
        && (obt2 == objtype::Asteroid_T || obt2 == objtype::Shoot_T))
            this->collisionAsteroidxShoot(collision);
        
        if(obt1 == objtype::Asteroid_T && obt2 == objtype::Asteroid_T)
            this->collisionAsteroidxAsteroid(collision); 
    }
};

void Game::collisionAsteroidxPlayer(Collision& collision)
{
    IDs obj1 = collision.object_1;
    IDs obj2 = collision.object_2;

    size_t asteroid_idx = obj1.collection_type == objtype::Asteroid_T ?
        obj1.index_object : obj2.index_object;

    this->RemoveAsteroid(asteroid_idx);
    
    this->player = Player();
    this->playersprite = player.getSprite();
    this->decrementLife();
};

void Game::collisionAsteroidxShoot(Collision& collision)
{
    IDs obj1 = collision.object_1;
    IDs obj2 = collision.object_2;

    size_t asteroid_idx = obj1.collection_type == objtype::Asteroid_T ?
        obj1.index_object : obj2.index_object;

    size_t shoot_idx = obj1.collection_type == objtype::Shoot_T ?
        obj1.index_object : obj2.index_object;

    this->RemoveShoot(shoot_idx);

    this->asteroids[asteroid_idx].hitscount -= 1;
    if(this->asteroids[asteroid_idx].hitscount == 0)
    {
        if(this->asteroids[asteroid_idx].size == asteroidsize::LOW)
            this->incrementScore(SCORE_SMALL_ASTEROID);

        if(this->asteroids[asteroid_idx].size == asteroidsize::MEDIUM)
            this->incrementScore(SCORE_MEDIUM_ASTEROID);

        if(this->asteroids[asteroid_idx].size == asteroidsize::HIGH)
            this->incrementScore(SCORE_LARGE_ASTEROID);

        this->RemoveAsteroid(asteroid_idx);
    }
};

void Game::collisionAsteroidxAsteroid(Collision& collision)
{
    /* TODO: implementar logica de colisão entre asteroides.*/
};


/*
    ------------------------------------------------------
    |                 funções de screen                  |
    ------------------------------------------------------
*/

void Game::writeEndgame(FB& fb) 
{
    const uint8_t midY = (FRAME_BOARD_MAX_HEIGTH / 2) - 1;
    const uint8_t midX = (FRAME_BOARD_MAX_WIDTH / 2) - 1;

    fb.draw(Sprite(midY, midX - 3, 'E'));
    fb.draw(Sprite(midY, midX - 2, 'N'));
    fb.draw(Sprite(midY, midX - 1, 'D'));
    fb.draw(Sprite(midY, midX, ' '));
    fb.draw(Sprite(midY, midX + 1, 'G'));
    fb.draw(Sprite(midY, midX + 2, 'A'));
    fb.draw(Sprite(midY, midX + 3, 'M'));
    fb.draw(Sprite(midY, midX + 4, 'E'));
}

void Game::HUD() const
{
    const Scores_T currentScore = std::min(MAX_SCORE, this->score);
    const uint8_t score_text_len = 13;
    const uint8_t lifes_text_len = 14;
    const uint8_t space_length = FRAME_BOARD_MAX_WIDTH - score_text_len - lifes_text_len + 1;
   
    Buffer buffer;

    buffer << std::string(FRAME_BOARD_MAX_WIDTH + 2, '_') << "\n";
    buffer << "|" << std::string(FRAME_BOARD_MAX_WIDTH, ' ') << "|\n";

    /* adicionando pontuação ao HUD. */
    buffer << "| SCORE: ";
    buffer << std::setw(5) << std::setfill('0') << this->score;
    buffer << std::string(space_length, ' ');

    /* adicionando quantidade de vida ao HUD. */
    buffer << "LIFES: ";
    for(size_t i = 0; i < 3; i++)
        buffer << (this->lifes[i] == false ? ' ' : '@') << ' ';
    buffer << "|\n";

    system("cls");
    std::cout << buffer.str();
};

void Game::RenderFrame(const FB& fb)
{
    this->HUD();
    fb.render();
};


/*
    ------------------------------------------------------
    |              funções de remoção                    |
    ------------------------------------------------------
*/

void Game::RemoveShoot(size_t idx)
{
    std::swap(this->frameshoot[idx], this->frameshoot.back());
    this->frameshoot.pop_back();
};

void Game::RemoveAsteroid(size_t idx)
{
    std::swap(this->asteroids[idx], this->asteroids.back());
    this->asteroids.pop_back();
};


/*
    ------------------------------------------------------
    |              funções atualização                   |
    ------------------------------------------------------
*/

void Game::updateFrame(FB& fb)
{
    this->updatePlayerCoord(fb);
    this->updateAsteroidsCoord(fb);
    this->updateShootsCoord(fb);
};

void Game::updateShootsCoord(FB& fb)
{

    size_t idx = 0;

    while (true)
    {

        if (idx >= this->frameshoot.size()) break;

        this->frameshoot[idx].updateCoord();
        if (!movimenthandler::inBounds(this->frameshoot[idx].coord))
        {
            this->RemoveShoot(idx);
            continue;
        }

        fb.draw(this->frameshoot[idx].getSprite());
        idx++;
    }
};

void Game::updateAsteroidsCoord(FB& fb)
{

    if (this->timer.asteroid_clock == 0)
    {
        for (Asteroid &asteroid : this->asteroids)
        {
            asteroid.update_coord();

            for (Sprite &rock : asteroid.rocks)
                fb.draw(Sprite(rock.x, rock.y, rock.obj));
        }
        this->timer.resetAsteroid();
        return;
    }
    
    for(Asteroid& asteroid : this->asteroids)
        for (Sprite &rock : asteroid.rocks)
            fb.draw(Sprite(rock.x, rock.y, rock.obj));
};

void Game::updatePlayerCoord(FB& fb)
{
    this->playersprite = this->player.getSprite();
    fb.draw(this->playersprite);
};


/*
    ------------------------------------------------------
    |             funções de controle                    |
    ------------------------------------------------------
*/

bool Game::SwitchKeyPress(const WinKeyState keypressed)
{

    if (keypressed == VK_ESCAPE) return false;
    if (keypressed == 0) return true; // teclas não mapeadas (ou sem movimentacao)
    if (keypressed == VK_SPACE)
    { // espaço para atirar
        Shoot shoot = this->player.attack();
        this->frameshoot.push_back(shoot);
        return true;
    }
    this->player.move(keypressed); // executa um movimento.
    return true;
};
