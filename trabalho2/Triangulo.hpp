#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP
#include "Ponto.cpp"

using namespace std;

class Triangulo {

    private:
        //fornecido.
        float x1,y1, x2,y2, x3,y3;
        float lado1, lado2, lado3;

        //calcular...
        float angulo1, angulo2, angulo3;
        float area;

    public:
        float getArea();
        float calcArea();

        Triangulo(float lado1, float lado2, float lado3);
        Triangulo(float x1, float y1, float x2, float y2, float x3, float y3);
        Triangulo(Ponto p1, Ponto p2, Ponto p3);
};

#endif