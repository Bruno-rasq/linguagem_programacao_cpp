#include "../include/caminhaoLeve.hpp"
#include <sstream>

#define CARGA_MAXIMA 15000
#define CARGA_MINIMA 250

using namespace std;

CaminhaoLeve::CaminhaoLeve(const string placa, const string descricao, float quilometragem_inicial, float carga): 
Veiculo(placa, descricao, quilometragem_inicial){
    CaminhaoLeve::setCarga(carga);
};

CaminhaoLeve::~CaminhaoLeve(){};

string CaminhaoLeve::toString() const {
    std::ostringstream oss;
    oss << "Veiculo: Caminhao leve" << endl;
    oss << Veiculo::toString();
    oss << "carga total: " + to_string(CaminhaoLeve::getCarga()) + "kg" << endl;
    return oss.str();
}

void CaminhaoLeve::setCarga(float carga){
    if(carga <= CARGA_MAXIMA && carga >= CARGA_MINIMA){
        this->carga = carga;
        return;
    }
    this->carga = CARGA_MINIMA;
}

float CaminhaoLeve::getCarga() const {
    return this->carga;
}