#include <iostream>
#include "Triangulo.hpp"
#include "Ponto.hpp"

using namespace std;

int main(){

    Ponto2D p1 = Ponto2D(5.4, 5.2);
    Ponto2D p2 = Ponto2D(5.5, 4.3);
    Ponto2D p3 = Ponto2D(5.1, 1.2);

    cout << "x:" << p1.getX() << " y:" << p1.getY() << endl; 

    return 0;
}