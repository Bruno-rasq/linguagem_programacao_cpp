#include "../include/onibus.hpp"
#include <sstream>

#define MAXIMO_PASSAGEIROS 32
#define MINIMO_PASSAGEIROS 1

using namespace std;

Onibus::Onibus(const string placa, const string descricao, float quilometragem_inicial, int passageiros): 
Veiculo(placa, descricao, quilometragem_inicial){
    Onibus::setPassageiros(passageiros);
};

Onibus::~Onibus(){};

string Onibus::toString() const {
    std::ostringstream oss;
    oss << "Onibus    " + Veiculo::toString() + " " + to_string(Onibus::getNumeroPassageiros()) + " 0.0 ";
    oss << Veiculo::getDescricao();
    return oss.str();
}

void Onibus::setPassageiros(int passageiros){
    if(passageiros <= MAXIMO_PASSAGEIROS && passageiros >= MINIMO_PASSAGEIROS){
        this->numero_passageiros = passageiros;
        return;
    }
    this->numero_passageiros = MINIMO_PASSAGEIROS;
}

int Onibus::getNumeroPassageiros() const {
    return this->numero_passageiros;
}