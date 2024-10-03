#pragma once

#include <vector>
#include "Coordenadas.hpp"

using namespace std;

class Poligono {

    private:
        vector<Coordenada> vertices;
        double perimetro;

    public:
        Poligono(vector<Coordenada> coords);

        void calcularPerimetro();
        void showVertices();
        double getPerimetro();
};