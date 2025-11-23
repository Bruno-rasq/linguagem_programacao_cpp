#include "./asteroids.hpp"

namespace asteroidhandler {


    Asteroid::Asteroid(
        const Coord centro, const Rocks rocks,
        const Coord direction, const uint8_t size, const float radio
    ){
        this->centro = centro;
        this->rocks = rocks;
        this->delta_direction = direction;
        this->size = size;
        this->radio = radio;
    }

    void Asteroid::update_coord() {
        for(Sprite& rock : this->rocks){
            rock.x += this->delta_direction.x;
            rock.y += this->delta_direction.y;

            movimenthandler::wrap_around(rock.x, rock.y);
        }
        this->centro.x += this->delta_direction.x;
        this->centro.y += this->delta_direction.y;
    }

    /**
     *   asteroides pequeno:
     *   @
     * 
     *   asteroide medio:
     *   .@@#
     *   @#@.
     * 
     *   asteroide grande:
     *   .#@@#.
     *   @@@#@@
     *   @@##@.
     *    .##.
    */

    Asteroid create_small_asteroid(int8_t x, int8_t y, Coord delta){
        const Rocks rocks = { Sprite(x, y, '@') };
        return Asteroid(Coord(x,y), rocks, delta, 1, 0.5);
    };

    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta){
        const Rocks rocks = {
            Sprite(x, y - 2, '.'),
            Sprite(x, y - 1, '@'),
            Sprite(x, y, '@'),
            Sprite(x, y + 1, '#'),

            Sprite(x + 1, y - 2, '@'),
            Sprite(x + 1, y - 1, '#'),
            Sprite(x + 1, y, '@'),
            Sprite(x + 1, y + 1, '.'),
        };
        return Asteroid(Coord(x,y), rocks, delta, 2, 0.5);
    };

    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta){
        const Rocks rocks = {
            
            Sprite(x - 1, y - 3, '.'), 
            Sprite(x - 1, y - 2, '#'),
            Sprite(x - 1, y - 1, '@'),
            Sprite(x - 1, y, '@'),
            Sprite(x - 1, y + 1, '#'),
            Sprite(x - 1, y + 2, '.'),

            Sprite(x, y - 3, '@'), 
            Sprite(x, y - 2, '@'),
            Sprite(x, y - 1, '@'),
            Sprite(x, y, '#'),
            Sprite(x, y + 1, '@'),
            Sprite(x, y + 2, '@'),

            Sprite(x + 1, y - 3, '@'), 
            Sprite(x + 1, y - 2, '@'),
            Sprite(x + 1, y - 1, '#'),
            Sprite(x + 1, y, '#'),
            Sprite(x + 1, y + 1, '@'),
            Sprite(x + 1, y + 2, '.'),

            Sprite(x + 2, y - 2, '.'),
            Sprite(x + 2, y - 1, '#'),
            Sprite(x + 2, y, '#'),
            Sprite(x + 2, y + 1, '.'),
        };
        return Asteroid(Coord(x,y), rocks, delta, 3, 0.5);
    };

}