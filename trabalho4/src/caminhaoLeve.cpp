#include "../include/caminhaoLeve.hpp"
#include "../include/procedimentos.hpp"
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
    oss << "Caminhao leve " + Veiculo::toString() + " passageiros: 0"; 
    oss <<" carga: " + precisaoDecimal(CaminhaoLeve::getCarga(), 2) + "kg";
    oss << "\n-----------------------------------------------------------------------------\n";
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