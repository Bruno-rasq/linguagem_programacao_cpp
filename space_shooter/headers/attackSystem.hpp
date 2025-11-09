#pragma once

// libs
#include <cstdint>

// headers
#include "./engine2D.hpp" 

namespace AttkSystem {

    struct Projectile {

        uint8_t row, col, direction;
        char obj;

        Projectile();
        Projectile(uint8_t row, uint8_t col, uint8_t direction);

        void setObj(uint8_t direction);
        void update();

        Engine2D::Sprite getSprite() const;
    };
}