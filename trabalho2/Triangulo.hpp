#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include "Ponto.hpp"

class Triangulo {

    private:

        float vertice1, vertice2, vertice3;
        float area, perimetro;

    public:
        
        Triangulo(float lado1, float lado2, float lado3);
        Triangulo(const Ponto p1, const Ponto p2, const Ponto p3);
        Triangulo(float x1, float y1, float x2, float y2, float x3, float y3);

        float getPerimetro() const;
        float getArea() const;
};

#endif