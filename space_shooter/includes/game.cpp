#include "./game.hpp"

Game::Game()
{

    this->player = Player();
    this->playersprite = this->player.getSprite();

    // teste
    this->asteroids = {
        asteroidhandler::create_large_asteroid(3, 5, Coord(1, 1)),
        asteroidhandler::create_medium_asteroid(13, 5, Coord(-1, 0)),
        asteroidhandler::create_small_asteroid(10, 65, Coord(-1, -1)),
    };
};

void Game::start()
{
    framerHandler::framer_buffer start_frame;
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
            framerHandler::framer_buffer current_frame;
            this->updateFrame(current_frame);

            Collision_handler::checkCollisions(
                this->running,
                this->playersprite,
                this->asteroids,
                this->frameshoot);

            this->RenderFrame(current_frame);
            this->timer.clock();
        }
    }

    framerHandler::framer_buffer end_frame;
    this->updateFrame(end_frame);
    this->RenderFrame(end_frame);
};

void Game::RenderFrame(const framerHandler::framer_buffer& fb)
{
    system("cls");
    fb.render();
};


void Game::updateFrame(framerHandler::framer_buffer& fb)
{
    this->updatePlayerCoord(fb);
    this->updateAsteroidsCoord(fb);
    this->updateShootsCoord(fb);
};

void Game::updateShootsCoord(framerHandler::framer_buffer& fb)
{

    size_t idx = 0;

    while (true)
    {

        if (idx >= this->frameshoot.size()) break;

        Shoot &shoot = this->frameshoot[idx];

        shoot.updateCoord();

        if (!movimenthandler::inBounds(shoot.coord))
        {
            // amanha eu te pego... -_-
            std::swap(this->frameshoot[idx], this->frameshoot.back());
            this->frameshoot.pop_back();
            continue;
        }

        fb.draw(shoot.getSprite());
        idx++;
    }
};

void Game::updateAsteroidsCoord(framerHandler::framer_buffer& fb)
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

void Game::updatePlayerCoord(framerHandler::framer_buffer& fb)
{
    this->playersprite = this->player.getSprite();
    fb.draw(this->playersprite);
};

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
