#include <iostream>
#include <cmath>
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

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3) : Triangulo(
    sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2)), //lado 1
    sqrt(pow(p3.getX() - p3.getX(), 2) + pow(p3.getY() - p2.getY(), 2)), //lado 2
    sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2)) //lado 3   
) {}

Triangulo::Triangulo(float x1, float y1, float x2, float y2, float x3, float y3) : Triangulo(
    Ponto2D(x1, y1), Ponto2D(x2, y2), Ponto2D(x3, y3)
) {}