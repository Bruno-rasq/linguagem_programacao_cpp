#pragma once

#include <cstdint>
#include <string>
using namespace std;

namespace PlayerHandler {

    #define HP_FULL   500
    #define MOV_SPEED 3
    #define ATK_SPEED 3
    #define DIRECTION 1 
    #define COORD_X   27
    #define COORD_Y   5

    struct Spaceship {

        char symbol = '^';                  // cima(^) baixo(v) esquerda(<) direita(>) 
        uint8_t direction = DIRECTION;      // cima(1) baixo(2) esquerda(3) direita(4)             
        uint8_t atkspd = ATK_SPEED;         // velocidade do projetil.
        uint8_t movspd = MOV_SPEED;         // velocidade (mov a cada X frames.)
        uint8_t HP_full = HP_FULL;          // vida total.
        uint8_t HP = HP_FULL;               // vida atual.
        uint8_t x = COORD_X, y = COORD_Y;   // coordenada da nave no space.

        void setCurrentDirection(const uint8_t dir);
        void SetSymbolByCurrentDirection();
        void DecrementHP(const uint8_t damage);
        void setNewCoord(const uint8_t x, const uint8_t y);
        char getSymbol() const;
    };

    class PlayerSpaceship {
        private:
            Spaceship spaceship;

        public:
            PlayerSpaceship();

            void move(const uint8_t x, const uint8_t y);
            void atk();
    };
}