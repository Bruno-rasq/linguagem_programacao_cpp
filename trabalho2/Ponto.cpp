#include "Ponto.hpp"

void Ponto::setXY(float x, float y){
    this->x = x;
    this->y = y;
}

float Ponto::getX() const {
    return this->x;
}

float Ponto::getY() const {
    return this->y;
}