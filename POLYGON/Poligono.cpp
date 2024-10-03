#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#include "Poligono.hpp"
#include "Coordenadas.hpp"

using namespace std;

int potencia(int a){
    return a *a;
}

int calcularVertice(Coordenada p1, Coordenada p2){
    return sqrt(
        potencia(p2.getCoordenadaX() - p1.getCoordenadaX()) + (p2.getCoordenadaY() - p1.getCoordenadaY())
    );
}

int Poligono::getPerimetro() {
    return this->perimetro;
}

void Poligono::showVertices(){
    string vertices = "vertices: ";
    for(int vertice : this->vertices){
        vertices += vertice + ", ";
    }
    cout << vertices << endl << endl;
}

void Poligono::calcularPerimetro(){
    for(int vertice : this->vertices){
        this->perimetro += vertice;
    }
}

Poligono::Poligono(vector<Coordenada> coords ){

    if(coords.size() >= 3){
        Coordenada coordenada1 = coords[0];
        for(int i = 0; i < coords.size(); i++){
            if(i + 1 >= coords.size()){
                this->vertices.push_back(calcularVertice(coordenada1, coords[i]));
                continue;
            }
            this->vertices.push_back(calcularVertice(coords[i], coords[i + 1]));
        }
    }
}