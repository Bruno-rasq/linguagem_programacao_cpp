#include <sstream>
#include "../include/carro.hpp"

using namespace std;

Carro::Carro(const string placa, const string descricao, float quilometragem_inicial):
Veiculo(placa, descricao, quilometragem_inicial){};

Carro::~Carro(){};

string Carro::toString() const {
    std::ostringstream oss;
    oss << "Veiculo: Carro" << endl;
    oss << Veiculo::toString();
    return oss.str();
}