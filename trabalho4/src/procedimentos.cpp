#include "../include/procedimentos.hpp"
#include "../include/output.hpp"
#include "../include/cadastros.hpp"
#include "../include/carro.hpp"
#include "../include/onibus.hpp"
#include "../include/caminhaoLeve.hpp"
#include "../include/caminhaoPesado.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string precisaoDecimal(float valor, int casas){
    ostringstream oss;
    oss << fixed << setprecision(casas) << valor;
    return oss.str();
}

void exibirHistoricoDeViagens(vector<tuple<string, float, float>>& viagens){
    cout << "[historico de viagens ] Destino - Km" << endl;
    for(int i = 0; i < viagens.size(); i++){
        auto viagem = viagens[i];

        string destino = get<0>(viagem);
        string km = precisaoDecimal(get<1>(viagem), 2);

        cout << destino + " - " + km + "km" << endl;
    }
    cout << endl;
}

void exibirVeiculos(vector<unique_ptr<Veiculo>>& frota){

    cout << "Tipo      Placa   Odometro   km_atual   consumo_medio   passageiros   carga   Descricao" << endl;
    cout << "=======================================================================================" << endl;
    for(const auto& veiculo : frota){
        cout << veiculo->toString() << endl;
    }
    cout << endl;
}

void pesquisarVeiculo(vector<unique_ptr<Veiculo>>& frota){

    string placa;
    cout << "Entre com a placa:\n";
    cin >> placa;

    for(const auto& veiculo: frota){
        if(veiculo->getPlaca() == placa){
    
            cout << veiculo->toString() << endl;
            auto historico = veiculo->getHistoricoViagens();
            exibirHistoricoDeViagens(historico);
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

    cout << "[placa (3 letras e 3 numeros)]: \n";
    cin >> placa;

    cout << "[descricao do veiculo]: \n";
    cin.ignore();
    getline(cin, descricao);
    
    cout << "[odometro]: \n";
    cin >> odometro;

    if(tipoDeVeiculo == 'c' || tipoDeVeiculo == 'C'){ 

        int passageiros;
        cout << "[numero de passageiros (maximo 4)]: \n";
        cin >> passageiros;

        cadastrarCarro(placa, descricao, odometro, passageiros, frota);  
    }

    if(tipoDeVeiculo == 'o' || tipoDeVeiculo == 'O'){

        int passageiros;
        cout << "[numero de passageiros (maximo 4)]: \n";
        cin >> passageiros;

        cadastrarOnibus(placa, descricao, odometro, passageiros, frota); 
    }

    if(tipoDeVeiculo == 'l' || tipoDeVeiculo == 'L'){

        float carga;
        cout << "[carga (maxima 30000)]: \n";
        cin >> carga;

        cadastrarCaminhaoLeve(placa, descricao, odometro, carga, frota);
    }

    if(tipoDeVeiculo == 'p' || tipoDeVeiculo == 'P'){

        float carga;
        cout << "[carga (maxima 30000)]: \n";
        cin >> carga;

        cadastrarCaminhaoLeve(placa, descricao, odometro, carga, frota);
    }
}


void efetuarViagem(
    vector<unique_ptr<Veiculo>>& frota, 
    const string placa, 
    const string destino, 
    float km, 
    float combustivel
){
    for(const auto& veiculo: frota){
        if(veiculo->getPlaca() == placa){
            veiculo->novaViagem(destino, km, combustivel);
            return;
        }
    }

    cout << "erro ao efetual cadastro de viagem" << endl;
}


/**
 * tentando fazer um cast do veiculo para Carro para obter acesso ao metodos da subclasse
 * o dynamic_cast permite fazer um downcasting que é uma forma mais segurade fazer o cast 
 * de um ponteiro da superclasse Veiculo para a subClasse Carro.
*/
void listarVeiculosCompativeisPessoas(vector<unique_ptr<Veiculo>>& frota){

    cout << "veiculos disponiceis:" << endl;
    for(const auto& veiculo: frota){

    
            if(Carro* carro = dynamic_cast<Carro*>(veiculo.get())){
                cout << carro->toString() << endl << endl;
            }

            else if(Onibus* onibus = dynamic_cast<Onibus*>(veiculo.get())){
                cout << onibus->toString() << endl << endl;
            }
    }
}

void listarVeiculosCompativeisCarga(vector<unique_ptr<Veiculo>>& frota){

    cout << "veiculos disponiceis:" << endl;
    cout << "=====================" << endl << endl;
    for(const auto& veiculo: frota){
        
        if(CaminhaoLeve* cl = dynamic_cast<CaminhaoLeve*>(veiculo.get())){
            cout << cl->toString() << endl;
        }

        else if(CaminhaoPesado* cp = dynamic_cast<CaminhaoPesado*>(veiculo.get())){
            cout << cp->toString() << endl;
        }
    }
}

void cadastrarViagem(vector<unique_ptr<Veiculo>>& frota){

    string  placa, destino;
    float   km,    combustivel;
    char    opcao;

    cout << "ESCOLHA UM TIPO DE VIAGEM  " << endl;
    cout << "---------------------------" << endl;
    cout << "A - transporte de pessoa   " << endl;
    cout << "B - transporte de carga    " << endl;
    cout << "[escolha uma opcao A ou B]:" << endl;

    cin >> opcao;

    if(opcao != 'A' && opcao != 'a' && opcao != 'B' && opcao != 'b'){
        cout << "opcao invalida!" << endl;
        return;
    }

    if(opcao == 'A' || opcao == 'a'){

        listarVeiculosCompativeisPessoas(frota);
    }
    
    if(opcao == 'B' || opcao == 'b'){

        listarVeiculosCompativeisCarga(frota);
    }

    cout << "[placa]:" << endl;
    cin >> placa;

    cout << "[destino]: " << endl;
    cin >> destino;

    cout << "[quilometragem]: " << endl;
    cin >> km;

    cout << "[combustivel]: " << endl;
    cin >> combustivel;

    efetuarViagem(frota, placa, destino, km, combustivel);
}