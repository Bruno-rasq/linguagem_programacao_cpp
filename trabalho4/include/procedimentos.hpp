#ifndef PROCEDIMENTOS_HPP
#define PROCEDIMENTOS_HPP

#include <vector>
#include <memory>
#include <tuple>
#include "./veiculo.hpp"

//ajusta a precisao de casas decimais em float para string
string precisaoDecimal(float valor, int casas);

void cadastrarVeiculo(vector<unique_ptr<Veiculo>>& frota);
void cadastrarViagem(vector<unique_ptr<Veiculo>>& frota);
void exibirVeiculos(vector<unique_ptr<Veiculo>>& frota);
void pesquisarVeiculo(vector<unique_ptr<Veiculo>>& frota);
void exibirHistoricoDeViagens(vector<tuple<string, float, float>>& viagens);

//verificam os veiculos compativeis
void listarVeiculosCompativeisPessoas(vector<unique_ptr<Veiculo>>& frota, int passageiros);
void listarVeiculosCompativeisCarga(vector<unique_ptr<Veiculo>>& frota, float carga);

//em frota, cadastre uma viagem parar o veiculo de placa tal...
void efetuarViagem(
    vector<unique_ptr<Veiculo>>& frota, 
    const string placa, 
    const string destino, 
    float km, 
    float combustivel
);

#endif