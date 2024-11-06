#ifndef CADASTROS_HPP
#define CADASTROS_HPP

#include <string>
#include <vector>
#include <memory>
#include "./veiculo.hpp"

using namespace std;

void cadastrarCarro(

    const string placa, 
    const string descricao, 
    float odometro, 
    int passageiros, 
    vector<unique_ptr<Veiculo>>& frota
);

void cadastrarOnibus(

    const string placa, 
    const string descricao, 
    float odometro, 
    int passageiros, 
    vector<unique_ptr<Veiculo>>& frota
);

void cadastrarCaminhaoLeve(

    const string placa, 
    const string descricao, 
    float odometro, 
    float carga, 
    vector<unique_ptr<Veiculo>>& frota
);
void cadastrarCaminhaoPesado(

    const string placa, 
    const string descricao, 
    float odometro, 
    float carga, 
    vector<unique_ptr<Veiculo>>& frota
);

#endif