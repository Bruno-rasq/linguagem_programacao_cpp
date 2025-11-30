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

            Collision_handler::checkCollisions(
                this->running,
                this->playersprite,
                this->asteroids,
                this->frameshoot);

            this->RenderFrame(current_frame);
            this->timer.clock();
        }
    }

    FB end_frame;
    this->updateFrame(end_frame);
    this->RenderFrame(end_frame);
};

void Game::HUD()
{
    /*
        X = FRAME_BOARD_MAX_WIDTH = 70 + 2 das bordas
        M = score = 11
        N = lifes = 14

        espaço = X - (M + N) = 45
    */

    Buffer buffer;

    buffer << std::string(FRAME_BOARD_MAX_WIDTH + 2, '_') << "\n";
    buffer << "|" << std::string(FRAME_BOARD_MAX_WIDTH, ' ') << "|\n";

    /* adicionando pontuação ao HUD. */
    buffer << "| SCORE: " << this->score << " ";
    buffer << std::string(47, ' ');

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


void Game::RemoveShoot(size_t idx)
{
    std::swap(this->frameshoot[idx], this->frameshoot.back());
    this->frameshoot.pop_back();
};


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
