#include "../include/caminhaoPesado.hpp"
#include <sstream>

#define CARGA_MAXIMA 30000 //considerar em kg
#define CARGA_MINIMA 15000

using namespace std;

CaminhaoPesado::CaminhaoPesado(const string placa, const string descricao, float quilometragem_inicial, float carga): 
Veiculo(placa, descricao, quilometragem_inicial){
    CaminhaoPesado::setCarga(carga);
};

CaminhaoPesado::~CaminhaoPesado(){};

string CaminhaoPesado::toString() const {
    std::ostringstream oss;
    oss << "Veiculo: Caminhao Pesado" << endl;
    oss << Veiculo::toString();
    oss << "carga total: " + to_string(CaminhaoPesado::getCarga()) + "kg" << endl;
    return oss.str();
}

void CaminhaoPesado::setCarga(float carga){
    if(carga <= CARGA_MAXIMA && carga >= CARGA_MINIMA){
        this->carga = carga;
        return;
    }
    this->carga = CARGA_MINIMA;
}

float CaminhaoPesado::getCarga() const {
    return this->carga;
}