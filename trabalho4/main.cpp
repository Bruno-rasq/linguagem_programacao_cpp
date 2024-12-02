#include <iostream>
#include <vector>
#include <memory>

#include "./include/output.hpp"
#include "./include/veiculo.hpp"
#include "./include/procedimentos.hpp"
#include "./include/controleMemoria.hpp"
#include "./include/cadastros.hpp"

using namespace std;

int main(){

    vector<unique_ptr<Veiculo>> frota;

    bool status = carregarDados(frota);
    if(status == false){
        cout << "Error ao carregar arquivos da memoria" << endl;
        return 0;
    }

    while(true){

        cout << menu() << endl;

        int opcao;
        cin >> opcao;

        switch(opcao){

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