#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include "Ponto.cpp"

using namespace std;

class Triangulo {

    private:
        //fornecido.
        float lado1, lado2, lado3;

        //deve calcular...
        float angulo1, angulo2, angulo3, area;

    public:
        ~Triangulo(); //destrutor

        // multiplos construtores
        Triangulo(float x1, float y1, float x2, float y2, float x3, float y3);
        Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3);
        Triangulo(float lado1, float lado2, float lado3);
    
        string getAngulos();     
        string getInfo(); 
        float getArea();
};

#endif