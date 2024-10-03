#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#include "Poligono.hpp"
#include "Coordenadas.hpp"

using namespace std;

double potencia(int a){
    return a * a;
}

double calcularDistancia(Coordenada p1, Coordenada p2){
    return sqrt(
        potencia(p2.getCoordenadaX() - p1.getCoordenadaX()) + 
        potencia(p2.getCoordenadaY() - p1.getCoordenadaY())
    );
}

double Poligono::getPerimetro() {
    return this->perimetro;
}

void Poligono::showVertices(){
    string vertices = "vertices: ";
    for(Coordenada vertice : this->vertices){
        vertices += "(" + to_string(vertice.getCoordenadaX()) + ", " + to_string(vertice.getCoordenadaY()) + ") ";
    }
    cout << vertices << endl << endl;
}

void Poligono::calcularPerimetro(){
    this->perimetro = 0.0;
    for(int i = 0; i < this->vertices.size(); i++){
        Coordenada atual = this->vertices[i];
        Coordenada proximo = this->vertices[(i + 1) % this->vertices.size()];

        this->perimetro += calcularDistancia(atual, proximo);
    }
}

Poligono::Poligono(vector<Coordenada> coords ){
    if(coords.size() >= 3){
        this->vertices = coords;
    }
}