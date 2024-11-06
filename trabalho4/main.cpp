#include <iostream>
#include <vector>
#include <memory>

#include "./include/output.hpp"
#include "./include/veiculo.hpp"
#include "./include/procedimentos.hpp"

using namespace std;


void carregarDados(vector<unique_ptr<Veiculo>>& frota){ cout << "carregando dados..." << endl;}
void gravarDados(vector<unique_ptr<Veiculo>>& frota){ cout << "salvando dados..." << endl;}


int main(){

    vector<unique_ptr<Veiculo>> frota;

    carregarDados(frota);

    while(true){

        cout << menu() << endl;

        int opcao;
        cin >> opcao;

        switch (opcao){

            case 1: { cadastrarVeiculo(frota);  break; }

            case 2: { cadastrarViagem(frota);   break; }

            case 3: { exibirVeiculos(frota);    break; }

            case 4: { pesquisarVeiculo(frota);  break; }

            case 5: { gravarDados(frota);       return 0; } 
            
            default:{ break; }
        }
    }

    return 0;
}