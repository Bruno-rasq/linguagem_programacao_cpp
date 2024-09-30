#include "Ponto.hpp"

Ponto2D::Ponto2D(float x, float y): x(x), y(y) {}

Ponto2D::~Ponto2D() {}

float Ponto2D::getX() {
    return x;
}

float Ponto2D::getY() {
    return y;
}