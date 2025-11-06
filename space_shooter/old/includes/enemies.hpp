#pragma once 

#include <cstdint>
#include <vector>
#include "./spaceGrid.hpp"
using namespace std;
using namespace SpaceGrid;

namespace HandleEnemiesDrone {

    // status  HP - damage - speed - atkSpeed - sprite(kkk)
    #define BASE_DRONE_STATUS  {50,  5,  5, 10, 'H'} // drone base
    #define A_DRONE_STATUS     {25,  3,  1, 5,  'o'} // rapido mais fraco
    #define B_DRONE_STATUS     {100, 10, 7, 15, 'B'} // forte mas lento


    struct EnemyDrone {
        uint8_t x, y;           // coordenada da nave inimiga
        uint8_t speed;          // velocidade (mov a cada X frames)
        uint8_t atkSpeed;       // velocidade (atk por X frame)
        uint8_t HP, HP_full;    // vida atual e total
        char symbol;            // representação visual
        bool isAlive;           // esta vivo ou morto

        EnemyDrone(
            uint8_t x, uint8_t y, 
            uint8_t speed, uint8_t atkspd, 
            uint8_t damage, uint8_t HP,
            const char symbol);

        void followPlayer(uint8_t x, uint8_t y);
        uint8_t porcentLive() const;
    };

    EnemyDrone createEnemyDrone();

    // função que executa o followPlayer para c/ drone inimigo.
    void f(const vector<EnemyDrone>& drones, const SpaceCoord& playerPosition);

    //TODO - criar uma animaçãozinha de explosão quando inimgo é derrotado.
    void Explosion();

    // metodo responsavel por fazer a contagem dos status a cada frame.
    //  exm: speed == 5
    //  - depois de 5 iterações do loop principal o contador speed zera
    //  - o drone se move uma posição e a contagem reinicia.
    void A(const vector<EnemyDrone>& drones);
}