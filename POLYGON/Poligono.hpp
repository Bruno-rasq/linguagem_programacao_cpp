#include <vector>
#include "Coordenadas.cpp"

using namespace std;

class Poligono {

    private:
        vector<int> vertices;
        int perimetro;

    public:
        Poligono(vector<Coordenada> coords);

        void calcularPerimetro();
        void showVertices();
        int getPerimetro();
};