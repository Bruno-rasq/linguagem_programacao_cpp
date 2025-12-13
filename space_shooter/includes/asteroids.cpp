#include "./asteroids.hpp"

namespace asteroidhandler
{

    Asteroid::Asteroid(const Rocks rocks, const Coord direction, size_t count, asteroidsize size)
    {
        this->rocks = rocks;
        this->delta_direction = direction;
        this->hitscount = count;
        this->size = size;
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

    Asteroid create_small_asteroid(int8_t x, int8_t y, Coord delta)
    {
        const Rocks rocks = {Sprite(x, y, ASTEROID_CHAR)};

        return Asteroid(
            rocks, 
            delta, 
            HITS_TO_DESTROY_SMALL_ASTEROID,
            asteroidsize::LOW
        );
    };

    Asteroid create_medium_asteroid(int8_t x, int8_t y, Coord delta)
    {
        const Rocks rocks = {

            Sprite(x, y - 2, ASTEROID_CHAR),
            Sprite(x, y - 1, ASTEROID_CHAR),
            Sprite(x, y, ASTEROID_CHAR),
            Sprite(x, y + 1, ASTEROID_CHAR),
            Sprite(x + 1, y - 2, ASTEROID_CHAR),
            Sprite(x + 1, y - 1, ASTEROID_CHAR),
            Sprite(x + 1, y, ASTEROID_CHAR),
            Sprite(x + 1, y + 1, ASTEROID_CHAR),
        };

        return Asteroid(
            rocks, 
            delta, 
            HITS_TO_DESTROY_MEDIUM_ASTEROID,
            asteroidsize::MEDIUM
        );
    };

    Asteroid create_large_asteroid(int8_t x, int8_t y, Coord delta)
    {
        const Rocks rocks = {

            Sprite(x - 1, y - 3, ASTEROID_CHAR),
            Sprite(x - 1, y - 2, ASTEROID_CHAR),
            Sprite(x - 1, y - 1, ASTEROID_CHAR),
            Sprite(x - 1, y, ASTEROID_CHAR),
            Sprite(x - 1, y + 1, ASTEROID_CHAR),
            Sprite(x - 1, y + 2, ASTEROID_CHAR),

            Sprite(x, y - 3, ASTEROID_CHAR),
            Sprite(x, y - 2, ASTEROID_CHAR),
            Sprite(x, y - 1, ASTEROID_CHAR),
            Sprite(x, y, ASTEROID_CHAR),
            Sprite(x, y + 1, ASTEROID_CHAR),
            Sprite(x, y + 2, ASTEROID_CHAR),

            Sprite(x + 1, y - 3, ASTEROID_CHAR),
            Sprite(x + 1, y - 2, ASTEROID_CHAR),
            Sprite(x + 1, y - 1, ASTEROID_CHAR),
            Sprite(x + 1, y, ASTEROID_CHAR),
            Sprite(x + 1, y + 1, ASTEROID_CHAR),
            Sprite(x + 1, y + 2, ASTEROID_CHAR),

            Sprite(x + 2, y - 2, ASTEROID_CHAR),
            Sprite(x + 2, y - 1, ASTEROID_CHAR),
            Sprite(x + 2, y, ASTEROID_CHAR),
            Sprite(x + 2, y + 1, ASTEROID_CHAR),
        };

        return Asteroid(
            rocks, 
            delta, 
            HITS_TO_DESTROY_LARGE_ASTEROID,
            asteroidsize::HIGH
        );
    };

}