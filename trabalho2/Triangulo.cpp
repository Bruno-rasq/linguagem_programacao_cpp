#include <iostream>
#include "Triangulo.hpp"
#include "Ponto.hpp"

using namespace std;

void Triangulo::getInfo(){
    cout << "l1:" << lado1 << " l2:" << lado2  << " l3:" << lado3 << endl; 
}

Triangulo::Triangulo(float l1, float l2, float l3){
    lado1 = l1;
    lado2 = l2;
    lado3 = l3;
}

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3): Triangulo(
    (p1.getY() - p1.getX()), (p2.getY() - p2.getX()), (p3.getY() - p3.getX())
) {}

Triangulo::Triangulo(float x1, float y1, float x2, float y2, float x3, float y3) : Triangulo(
    Ponto2D(x1, y1), Ponto2D(x2, y2), Ponto2D(x3, y3)
) {}