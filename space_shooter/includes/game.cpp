#include "./game.hpp"


/*
    ------------------------------------------------------
    |                 metodos auxiliares                 |
    ------------------------------------------------------
*/

Coord getRandomDelta()
{
    int8_t x, y;

    /* unica situação em que o delta não gera movimento*/
    do {
        x = DELTAOPTIONS[std::rand() % 3];
        y = DELTAOPTIONS[std::rand() % 3];
    } 
    while(x == 0 && y == 0);

    return Coord(x, y);
};




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

        /* o jgo termina se o player alcançar a pontuação maxima.*/
        if(this->score == MAX_SCORE) break;

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
    this->score = std::min(this->score + score, MAX_SCORE);
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

        /* tanto asteroide grande quanto o medio são divididos ao serem destruidos. */
    
        if(this->asteroids[asteroid_idx].size == asteroidsize::MEDIUM)
        {
            this->SplitAsteroid(asteroid_idx);
            this->incrementScore(SCORE_MEDIUM_ASTEROID);
        }

        if(this->asteroids[asteroid_idx].size == asteroidsize::HIGH)
        {
            this->SplitAsteroid(asteroid_idx);
            this->incrementScore(SCORE_LARGE_ASTEROID);
        }

        if(this->asteroids[asteroid_idx].size == asteroidsize::LOW)
        {
            this->incrementScore(SCORE_SMALL_ASTEROID);
        }

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
    const uint8_t score_text_len = 13;
    const uint8_t lifes_text_len = 14;
    const Scores_T currentScore = std::min(MAX_SCORE, this->score);
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

void Game::SplitAsteroid(size_t idx)
{
    
    Asteroid atd = this->asteroids[idx];

    /* asteroide grande se fragmenta em 2 asteroides medios. */
    if(atd.size == asteroidsize::HIGH){

        Coord delta1 = getRandomDelta();
        Coord delta2 = Coord(-delta1.x, -delta1.y);

        this->asteroids.push_back(asteroidhandler::create_medium_asteroid(
            atd.rocks[0].x, atd.rocks[0].y, delta1
        ));

        this->asteroids.push_back(asteroidhandler::create_medium_asteroid(
            atd.rocks[14].x, atd.rocks[14].y, delta2
        ));

        return;
    }

    /* asteroide medio se fragmenta em 4 asteroides pequenos*/
    this->asteroids.push_back(asteroidhandler::create_small_asteroid(
        atd.rocks[0].x, atd.rocks[0].y, Coord(-1, -1)
    ));
    this->asteroids.push_back(asteroidhandler::create_small_asteroid(
        atd.rocks[3].x, atd.rocks[3].y, Coord(-1, 1)
    ));
    this->asteroids.push_back(asteroidhandler::create_small_asteroid(
        atd.rocks[4].x, atd.rocks[4].y, Coord(1, -1)
    ));
    this->asteroids.push_back(asteroidhandler::create_small_asteroid(
        atd.rocks[7].x, atd.rocks[7].y, Coord(1, 1)
    ));
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

    /* caso em que o asteroide deve se mover antes de ser desenhado.*/
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
    
    /* se o asteroid não de mover deve ser desenhado do mesmo jeito. */
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
