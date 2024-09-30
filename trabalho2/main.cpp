#include <iostream>
#include <vector>

#include "Triangulo.hpp"
#include "Ponto.hpp"

using namespace std;

int main(){

    Ponto2D p1 = Ponto2D(5.4, 5.2);
    Ponto2D p2 = Ponto2D(5.5, 4.3);
    Ponto2D p3 = Ponto2D(5.1, 1.2);

    vector<Triangulo> triangulos;

    triangulos.push_back(Triangulo(5.0, 4.5, 4.3, 5.1, 4.2, 5.2)); // por coordenadas
    triangulos.push_back(Triangulo(p1, p2, p3)); // por  Ponto2d
    triangulos.push_back(Triangulo(5.1, 5.2, 5.3)); // passando direto os lados

    for(Triangulo &t : triangulos){
        t.getInfo();
    }

    return 0;
}