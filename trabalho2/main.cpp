#include <iostream>
#include "Ponto.hpp"
#include "Triangulo.hpp"

using namespace std;

int main(){

    float x1 = 0.0, y1 = 0.0, x2 = 3.0, y2 = 0.0, x3 = 0.0, y3 = 4.0;

    Ponto p1, p2, p3;
    
    p1.setXY(x1, y1);
    p2.setXY(x2, y2);
    p3.setXY(x3, y3);

    cout << "x=" << p1.getX() << " y=" << p1.getY() << endl;


    Triangulo t1(3.0, 4.0, 5.0); // instanciando direto com os valores dos vertices.

    cout << "area=" << t1.getArea() << " perimetro=" << t1.getPerimetro() << endl;


    Triangulo t2(p1, p2, p3); // instanciando atraves dos valores dos pontos.

    cout << "area=" << t2.getArea() << " perimetro=" << t2.getPerimetro() << endl;
    
    
    Triangulo t3(x1, y1, x2, y2, x3, y3); // instanciando atraves dos valores de coordenadas

    cout << "area=" << t3.getArea() << " perimetro=" << t3.getPerimetro() << endl;


    return 0;
}