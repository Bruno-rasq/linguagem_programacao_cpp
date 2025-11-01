#pragma once

#include <cstdint>
#include <string>
using namespace std;

namespace PlayerHandler {

    struct Spaceship {
        uint8_t x, y;               // coordenada da nave no space.
        uint8_t HP, HP_full;        // vida e vida total.
        uint8_t atkspd;             // velocidade do projetil.
        uint8_t movspd;             // velocidade (mov a cada X frames.)

        // para cima     == ^
        // para baixo    == v
        // para esquerda == <
        // para direita  == >
        char symbol;  
        string currentDirection;    // direção atual da nave.              
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