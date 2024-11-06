#ifndef PROCEDIMENTOS_HPP
#define PROCEDIMENTOS_HPP

#include <vector>
#include <memory>
#include "./veiculo.hpp"

void exibirVeiculos(vector<unique_ptr<Veiculo>>& frota);
void cadastrarVeiculo(vector<unique_ptr<Veiculo>>& frota);
void pesquisarVeiculo(vector<unique_ptr<Veiculo>>& frota);
void cadastrarViagem(vector<unique_ptr<Veiculo>>& frota);

#endif