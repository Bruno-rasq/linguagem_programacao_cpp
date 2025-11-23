#ifndef __GAME__LOOP__HPP__
#define __GAME__LOOP__HPP__

#include "./core_std.hpp"
#include "./framer.hpp"
#include "./keyboard.hpp"
#include "./player.hpp"
#include "./moviment.hpp"
#include "./asteroids.hpp"
#include "./timer.hpp"
//#include "./collisionhdr.hpp"

typedef framerHandler::Sprite       Sprite;
typedef framerHandler::Framerbuffer Framer;

typedef movimenthandler::Projectil  Shoot;
typedef std::vector<Shoot>          Shoots;

typedef asteroidhandler::Asteroid   Asteroid;
typedef std::vector<Asteroid>       Asteroids;

//|-------|-------|-------|-------|-------|-------|-------
enum objtype { Shoot_T, Player_T, Asteroid_T };

struct IDs {
    objtype collectionKey;    // a qual coleção o objeto pertence
    int objectkey;            // sua chave da coleção
};

// função que gera uma chave hash com base em uma coordenada x y.
struct CoordHash {
    size_t operator()(const movimenthandler::Coord& c) const noexcept;
};
//|-------|-------|-------|-------|-------|-------|-------

class Game {
    private:

        Timer timer;
        Player player;
        Framer framebuffer;
        Shoots frameshoot;
        Sprite playersprite;
        Asteroids asteroids;
        bool running = true;

        // Para cada objeto na instancia do game a checagem de colisão 
        // consiste em guardar em um hashmap para cada objeto uma chave
        // sendo a coordenada xy do mesmto e ums estrutura de IDs (id da
        // coleção e o id do obj). Assim quando uma coordenada tiver mais
        // de um objeto significa que houve uma colisão. 
        // complexidade - O(n)
        void checkCollisions();

        void updateFrame();
        void updateShootsCoord();
        void updateAsteroidsCoord();
        void updatePlayerCoord();

        void resetConsoleFrame() const;
        bool SwitchKeyPress(const WinKeyState keypressed);

    public:

        Game();

        void start();
};

#endif