#include <sstream>
#include "../include/carro.hpp"

#define MAXIMO_PASSAGEIROS 4
#define MINIMO_PASSAGEIROS 1

using namespace std;

Carro::Carro(const string placa, const string descricao, float quilometragem_inicial, int passageiros):
Veiculo(placa, descricao, quilometragem_inicial){
    Carro::setPassageiros(passageiros);
};

Carro::~Carro(){};

string Carro::toString() const {
    std::ostringstream oss;
    oss << "Carro     " + Veiculo::toString() + " " + to_string(Carro::getNumeroPassageiros()) + " 0.0 ";
    oss << Veiculo::getDescricao();
    return oss.str();
}

void Carro::setPassageiros(int passageiros){
    if(passageiros <= MAXIMO_PASSAGEIROS && passageiros >= MINIMO_PASSAGEIROS){
        this->numero_passageiros = passageiros;
        return;
    }
    this->numero_passageiros = MINIMO_PASSAGEIROS;
}

int Carro::getNumeroPassageiros() const {
    return this->numero_passageiros;
}