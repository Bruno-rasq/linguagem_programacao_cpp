#include "../include/caminhaoPesado.hpp"
#include <sstream>

using namespace std;

CaminhaoPesado::CaminhaoPesado(const string placa, const string descricao, float quilometragem_inicial): 
Veiculo(placa, descricao, quilometragem_inicial){};

CaminhaoPesado::~CaminhaoPesado(){};

string CaminhaoPesado::toString() const {
    std::ostringstream oss;
    oss << "Veiculo: Caminhao Pesado" << endl;
    oss << Veiculo::toString();
    return oss.str();
}