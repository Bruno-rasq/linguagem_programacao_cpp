#include <iostream>
#include <vector>

#include "Coordenadas.cpp"
#include "Poligono.cpp"

using namespace std;

int main(){

    vector<Poligono> poligonos;
    Coordenada p1, p2, p3, p4, p5;

    p1.setCoordenadas(4, 5);
    p2.setCoordenadas(5, 5);
    p3.setCoordenadas(3, 6);
    p4.setCoordenadas(4, 5);
    p5.setCoordenadas(3, 4);

    vector<Coordenada> triangulo = {p1, p2, p3};
    vector<Coordenada> quadrado  = {p1, p2, p3, p4};
    vector<Coordenada> pentagono = {p1, p2, p3, p4, p5};

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