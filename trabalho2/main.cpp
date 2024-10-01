#include <iostream>
#include "Ponto.hpp"
#include "Triangulo.hpp"

using namespace std;

int main(){

    Ponto p1, p2, p3;
    
    p1.setXY(0.0, 0.0);
    p2.setXY(3.0, 0.0);
    p3.setXY(0.0, 4.0);

    cout << "x=" << p1.getX() << " y=" << p1.getY() << endl;


    Triangulo t1(3.0, 4.0, 5.0); // instanciando direto com os valores dos vertices.

    cout << "area=" << t1.getArea() << " perimetro=" << t1.getPerimetro() << endl;


    Triangulo t2(p1, p2, p3); // instanciando atraves dos valoes dos pontos.

    cout << "area=" << t2.getArea() << " perimetro=" << t2.getPerimetro() << endl;


    return 0;
}