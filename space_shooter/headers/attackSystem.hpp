#pragma once

#include "./core.hpp"
#include "./engine2D.hpp" 

namespace AttkSystem {

    typedef Engine2D::FrameBuffer Framer;
    typedef Engine2D::Sprite Sprite;
    typedef std::vector<Projectile> Shoots;

    struct Projectile {

        uint8_t row, col, direction;
        char obj;

        Projectile();
        Projectile(uint8_t row, uint8_t col, uint8_t direction);
        void setObj(uint8_t direction);
        void update();
        Sprite getSprite() const;
    };

    class ProjectilesHandler {
        private:
            Shoots shoots;

        public:
            ProjectilesHandler();

            void AddShoot(Projectile shoot);
            void UpdateShoots(Framer& framer);
    };
}