#include "./timer.hpp"

void Timer::clock()
{
    this->asteroid_clock -= 1;
};

void Timer::resetAsteroid()
{
    this->asteroid_clock = this->asteroid_speed;
};