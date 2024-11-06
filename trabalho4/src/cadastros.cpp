#include <memory>
#include <vector>
#include <string>

#include "../include/veiculo.hpp"
#include "../include/carro.hpp"
#include "../include/onibus.hpp"
#include "../include/caminhaoLeve.hpp"
#include "../include/caminhaoPesado.hpp"

using namespace std;

void cadastrarCarro(

    const string placa, 
    const string descricao, 
    float odometro, 
    int passageiros, 
    vector<unique_ptr<Veiculo>>& frota
){
    frota.push_back(make_unique<Carro>(placa, descricao, odometro, passageiros));
}

void cadastrarOnibus(

    const string placa, 
    const string descricao, 
    float odometro, 
    int passageiros,
    vector<unique_ptr<Veiculo>>& frota
){
    frota.push_back(make_unique<Onibus>(placa, descricao, odometro, passageiros));
}

void cadastrarCaminhaoLeve(

    const string placa, 
    const string descricao, 
    float odometro, 
    float carga,
    vector<unique_ptr<Veiculo>>& frota
){
    frota.push_back(make_unique<CaminhaoLeve>(placa, descricao, odometro, carga));
}

void cadastrarCaminhaoPesado(
    const string placa, 
    const string descricao, 
    float odometro, 
    float carga,
    vector<unique_ptr<Veiculo>>& frota
){
    frota.push_back(make_unique<CaminhaoPesado>(placa, descricao, odometro, carga));
}