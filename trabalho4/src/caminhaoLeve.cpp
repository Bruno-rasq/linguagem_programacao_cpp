#include "../include/caminhaoLeve.hpp"
#include <sstream>

using namespace std;

CaminhaoLeve::CaminhaoLeve(const string placa, const string descricao, float quilometragem_inicial): 
Veiculo(placa, descricao, quilometragem_inicial){};

CaminhaoLeve::~CaminhaoLeve(){};

string CaminhaoLeve::toString() const {
    std::ostringstream oss;
    oss << "Veiculo: Caminhao leve" << endl;
    oss << Veiculo::toString();
    return oss.str();
}