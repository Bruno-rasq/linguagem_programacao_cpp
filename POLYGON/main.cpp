#include <iostream>
#include <vector>

#include "Coordenadas.hpp"
#include "Poligono.hpp"

using namespace std;

int main(){

    vector<Poligono> poligonos;
    Coordenada pT1, pT2, pT3, pQ1, pQ2, pQ3, pQ4, pP1, pP2, pP3, pP4, pP5;

    //coordenadas parar formar um triangulo de perimetro 11.22
    pT1.setCoordenadas(0, 0);
    pT2.setCoordenadas(4, 0);
    pT3.setCoordenadas(2, 3);

    //pontoss que formam um quadrado de perimetro 16
    pQ1.setCoordenadas(0, 0);
    pQ2.setCoordenadas(0, 4);
    pQ3.setCoordenadas(4, 4);
    pQ4.setCoordenadas(4, 0);

    // pontos para formar um pentagono de perimetro 13.84
    pP1.setCoordenadas(0, 0);
    pP2.setCoordenadas(2, 3);
    pP3.setCoordenadas(4, 1);
    pP4.setCoordenadas(3, -2);
    pP5.setCoordenadas(1, -2);

    vector<Coordenada> triangulo = {pT1, pT2, pT3};
    vector<Coordenada> quadrado  = {pQ1, pQ2, pQ3, pQ4};
    vector<Coordenada> pentagono = {pP1, pP2, pP3, pP4, pP5};

    poligonos.push_back(Poligono(triangulo));
    poligonos.push_back(Poligono(quadrado));
    poligonos.push_back(Poligono(pentagono));


    for(Poligono poligono : poligonos){
        poligono.calcularPerimetro();

        cout << "perimetro: " << poligono.getPerimetro() << endl;
        poligono.showVertices();
    }
    

    return 0;
}