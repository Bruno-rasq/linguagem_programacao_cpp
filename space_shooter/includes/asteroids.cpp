#include "./asteroids.hpp"

namespace asteroidhandler {


    Asteroid::Asteroid(const Rocks rocks, Coord direction, uint8_t size){
        this->rocks = rocks;
        this->delta_direction = direction;
        this->size = size;
    }

    void Asteroid::update_coord() {
        for(Sprite& rock : this->rocks){
            rock.x += this->delta_direction.x;
            rock.y += this->delta_direction.y;

            wrap_around(rock.x, rock.y);
        }
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
        const Coord delta = movimenthandler::get_random_coord();
        const Rocks rocks = { Sprite(x, y, '@') };
        return Asteroid(rocks, delta, 1);
    };

    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta){
        const Coord delta = movimenthandler::get_random_coord();
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
        return Asteroid(rocks, delta, 2);
    };

    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta){
        const Coord delta = movimenthandler::get_random_coord();
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
            Sprite(x + 1, y = 2, '@'),
            Sprite(x + 1, y - 1, '#'),
            Sprite(x + 1, y, '#'),
            Sprite(x + 1, y + 1, '@'),
            Sprite(x + 1, y + 2, '.'),

            Sprite(x + 2, y - 2, '.'),
            Sprite(x + 2, y - 1, '#'),
            Sprite(x + 2, y, '#'),
            Sprite(x + 2, y + 1, '.'),
        };
        return Asteroid(rocks, delta, 3);
    };


    void wrap_around(int8_t& x, int8_t& y){
        if(x < 0) x = FRAME_BOARD_MAX_HEIGTH - 1;
        if(x > FRAME_BOARD_MAX_HEIGTH - 1) x = 0;
        if(y < 0) y = FRAME_BOARD_MAX_WIDTH - 1;
        if(y > FRAME_BOARD_MAX_WIDTH - 1) y = 0;
    };
}