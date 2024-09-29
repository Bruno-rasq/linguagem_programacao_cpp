#include "Triangulo.hpp"

using namespace std;

Triangulo::Triangulo(float l1, float l2, float l3){
    this->lado1 = l1;
    this->lado2 = l2;
    this->lado3 = l3;
}

Triangulo::Triangulo(float x1, float y1, float x2, float y2, float x3, float y3){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
}

float Triangulo::getArea(){

}