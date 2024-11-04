#include "../include/onibus.hpp"
#include <sstream>

using namespace std;

Onibus::Onibus(const string placa, const string descricao, float quilometragem_inicial): 
Veiculo(placa, descricao, quilometragem_inicial){};

Onibus::~Onibus(){};

string Onibus::toString() const {
    std::ostringstream oss;
    oss << "Veiculo: Onibus" << endl;
    oss << Veiculo::toString();
    return oss.str();
}