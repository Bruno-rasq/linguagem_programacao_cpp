#pragma once

#include <cstdint>
#include <string>
#include <windows.h>
#include <map>
#include <algorithm>
#include <tuple>
#include "./spaceGrid.hpp"

using namespace std;

namespace PlayerHandler {

    extern const map<uint8_t, char> delta_symbol;

    typedef tuple<int8_t, int8_t, char> SPACESHIPINFO;

    struct Spaceship {

        char symbol = '^';          // cima(^) baixo(v) esquerda(<) direita(>) 
        uint8_t direction = 1;      // cima(1) baixo(2) esquerda(3) direita(4)             
        uint8_t atkspd = 3;         // velocidade do projetil.
        uint8_t movspd = 3;         // velocidade (mov a cada X frames.)
        uint8_t HP_full = 200;      // vida total.
        uint8_t HP = 200;           // vida atual.
       
        SpaceGrid::SpaceCoord coord {5, 5};

        void setCurrentDirection(const uint8_t dir);
        void SetSymbolByCurrentDirection(const char symbol);
        void DecrementHP(const uint8_t damage);
    };

    class PlayerSpaceship {
        private:
            Spaceship spaceship;

        public:
            PlayerSpaceship();

            SPACESHIPINFO Info() const;

            void move(const uint16_t key);
            void atk();
    };
}