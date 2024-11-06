#include "../include/procedimentos.hpp"
#include "../include/output.hpp"
#include "../include/cadastros.hpp"

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

void exibirVeiculos(vector<unique_ptr<Veiculo>>& frota){

    for(const auto& veiculo : frota){
        cout << veiculo->toString() << endl;
    }
}

void pesquisarVeiculo(vector<unique_ptr<Veiculo>>& frota){

    string placa;
    cout << "insira a placa do veiculo:\n";
    cin >> placa;

    for(const auto& veiculo: frota){
        if(veiculo->getPlaca() == placa){
            cout << veiculo->toString() << endl;
            return;
        }
    }

    cout << "veiculo nao encontrado." << endl;
}

void cadastrarVeiculo(vector<unique_ptr<Veiculo>>& frota){

    char tipoDeVeiculo;
    string placa, descricao;
    float odometro;

    cout << menuTiposDeVeiculos() << endl;
    cin >> tipoDeVeiculo;

    cout << "[placa]: \n";
    cin >> placa;

    cout << "[descricao]: \n";
    cin.ignore();
    getline(cin, descricao);
    
    cout << "[odometro]: \n";
    cin >> odometro;

    if(tipoDeVeiculo == 'c' || tipoDeVeiculo == 'C'){ 

        int passageiros;
        cout << "[maximo de passageiros]: \n";
        cin >> passageiros;

        cadastrarCarro(placa, descricao, odometro, passageiros, frota);  
    }

    if(tipoDeVeiculo == 'o' || tipoDeVeiculo == 'O'){

        int passageiros;
        cout << "[maximo de passageiros]: \n";
        cin >> passageiros;

        cadastrarOnibus(placa, descricao, odometro, passageiros, frota); 
    }

    //preciso achar uma terminação melhor para caminhao leve e pesado
    //não posso comparar string com char 
    if(tipoDeVeiculo == 'l' || tipoDeVeiculo == 'L'){

        float carga;
        cout << "[carga]: \n";
        cin >> carga;

        cadastrarCaminhaoLeve(placa, descricao, odometro, carga, frota);
    }

    if(tipoDeVeiculo == 'p' || tipoDeVeiculo == 'P'){

        float carga;
        cout << "[carga]: \n";
        cin >> carga;

        cadastrarCaminhaoLeve(placa, descricao, odometro, carga, frota);
    }
}

void cadastrarViagem(vector<unique_ptr<Veiculo>>& frota){
    cout << "implementando... " << endl;
}