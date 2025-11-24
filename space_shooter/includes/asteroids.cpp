#include "./asteroids.hpp"

namespace asteroidhandler
{

    Asteroid::Asteroid(const Rocks rocks, const Coord direction)
    {

        this->rocks = rocks;
        this->delta_direction = direction;
    }

    void Asteroid::update_coord()
    {
        for (Sprite &rock : this->rocks)
        {
            rock.x += this->delta_direction.x;
            rock.y += this->delta_direction.y;

            movimenthandler::wrap_around(rock.x, rock.y);
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

    Asteroid create_small_asteroid(int8_t x, int8_t y, Coord delta)
    {
        const Rocks rocks = {
            Sprite(x, y, '@')};
        return Asteroid(rocks, delta);
    };

    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta)
    {
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
        return Asteroid(rocks, delta);
    };

    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta)
    {
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
        return Asteroid(rocks, delta);
    };

}