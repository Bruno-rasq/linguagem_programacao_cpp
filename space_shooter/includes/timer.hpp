#include "./core_std.hpp"

struct Timer
{

    const int8_t asteroid_speed = 3;
    int8_t asteroid_clock = 3;

    void clock();
    void resetAsteroid();
};