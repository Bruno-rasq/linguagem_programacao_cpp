#include "veiculo.hpp"
#include <vector>
#include <tuple>

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

float Veiculo::getHodometro() const {
    return this->HODOMETRO;
}

float Veiculo::getQuilometragemAtual() const {
    return this->quilometragem_atual;
}

vector<tuple<string, float, float>> Veiculo::getHistoricoViagens() const {
    return this->historico_viagens;
}

void Veiculo::setQuilometragemAtual(float km){
    this->quilometragem_atual += km;
}

void Veiculo::setHistoricoViagens(const string destino,float km, float combustivel){
    tuple<string, float, float> viagem (destino, km, combustivel);

    this->historico_viagens.push_back(viagem);
}

void Veiculo::novaViagem(const string destino, float km, float combustivel) {
    Veiculo::setHistoricoViagens(destino, km, combustivel);
    Veiculo::setQuilometragemAtual(km);
}