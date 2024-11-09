#ifndef CONTROLEMEMORIA
#define CONTROLEMEMORIA

#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <tuple>

#include "./veiculo.hpp"


using namespace std;


void carregarHistoricoEmFrota(
    const string placa, 
    const string destino, 
    float km, 
    float combustivel, 
    vector<unique_ptr<Veiculo>>& frota
);

bool carregarHistorico(vector<unique_ptr<Veiculo>>& frota);

void carregarVeiculosEmfrota(
    char tipo,
    const string placa,
    const string descricao,
    float odometro,
    int passageiros,
    float carga,
    vector<unique_ptr<Veiculo>>& frota
);

bool carregarDados(vector<unique_ptr<Veiculo>>& frota);

void gravarHistoricos(vector<tuple<string, float, float>>& historico, ofstream& arquivo, const string placa);

bool gravarDados(vector<unique_ptr<Veiculo>>& frota);

#endif