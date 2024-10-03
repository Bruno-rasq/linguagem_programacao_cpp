#include "Coordenadas.hpp"

void Coordenada::setCoordenadas(int x, int y){
    this->x = x;
    this->y = y;
}

int Coordenada::getCoordenadaX(){
    return this->x;
}

int Coordenada::getCoordenadaY(){
    return this->y;
}