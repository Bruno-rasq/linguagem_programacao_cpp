#include "../include/veiculo.hpp"
#include "../include/procedimentos.hpp"

#include <vector>
#include <tuple>
#include <sstream>
#include <cmath>

using namespace std;

Veiculo::Veiculo(const string placa, const string descricao, float quilometragem_inicial){
    
    this->PLACA = placa;
    this->DESCRICAO = descricao;
    this->HODOMETRO = quilometragem_inicial;
    this->quilometragem_atual = this->HODOMETRO;
}

Veiculo::~Veiculo(){}

string Veiculo::getPlaca() const { 
    return this->PLACA; 
}

string Veiculo::getDescricao() const { 
    return this->DESCRICAO; 
}

vector<tuple<string, float, float>> Veiculo::getHistoricoViagens() const { 
    return this->historico_viagens; 
}

string Veiculo::getHodometro() const {

    ostringstream oss;
    oss << precisaoDecimal(this->HODOMETRO, 2) + "km";
    return oss.str();
}

string Veiculo::getQuilometragemAtual() const {

    ostringstream oss;
    oss << precisaoDecimal(this->quilometragem_atual, 2) + "km";
    return oss.str();
}

string Veiculo::toString() const {

    ostringstream oss;
    oss << Veiculo::getPlaca() + "  ";
    oss << Veiculo::getHodometro() + "     ";
    oss << Veiculo::getQuilometragemAtual() + "   ";
    oss << precisaoDecimal(Veiculo::consumoMedio(), 3) + "km/l       ";
    return oss.str();
}

void Veiculo::setQuilometragemAtual(float km){ 
    this->quilometragem_atual += km; 
}

void Veiculo::setHistoricoViagens(const string destino,float km, float combustivel){

    tuple<string, float, float> viagem (destino, km, combustivel);
    this->historico_viagens.push_back(viagem);
}

void Veiculo::novaViagem(const string destino, float km, float combustivel){

    Veiculo::setHistoricoViagens(destino, km, combustivel);
    Veiculo::setQuilometragemAtual(km);
}

float Veiculo::consumoMedio() const {

    float kmTotal = 0.0, combustivelTotal = 0.0;

    for(int i = 0; i < this->historico_viagens.size(); i++){
        auto viagem = this->historico_viagens[i];

        float km = get<1>(viagem);
        float combustivel = get<2>(viagem);

        kmTotal += km;
        combustivelTotal += combustivel;
    }

    double result = kmTotal / combustivelTotal;

    if(std::isnan(result)){
        return 0.0;
    }

    return kmTotal / combustivelTotal;

}