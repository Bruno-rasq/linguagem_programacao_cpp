#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <tuple>

#include "./include/output.hpp"
#include "./include/veiculo.hpp"
#include "./include/procedimentos.hpp"
#include "./include/controleMemoria.hpp"
#include "./include/cadastros.hpp"


#include "./include/carro.hpp"
#include "./include/onibus.hpp"
#include "./include/caminhaoLeve.hpp"
#include "./include/caminhaoPesado.hpp"

using namespace std;

void gravarHistoricos(vector<tuple<string, float, float>>& historico, ofstream& arquivo, const string placa){

    for(int i = 0; i < historico.size(); i++){
        auto viagem = historico[i];

        string destino = get<0>(viagem);
        string km = precisaoDecimal(get<1>(viagem), 2);
        string combustivel = precisaoDecimal(get<2>(viagem), 2);

        arquivo << placa + " " + destino + " " + km + " " + combustivel << endl;
    }
}

//implementando...
bool gravarDados(vector<unique_ptr<Veiculo>>& frota){ 
    
    int quantidade_veiculo = frota.size();

    //abriando o arquivo e limpando para uso.
    ofstream file("./memoria/memoria.txt", ios::out);
    ofstream hist("./memoria/historico.txt", ios::out);

    if(!file.is_open() || !hist.is_open()){
        cout << "houve um erro ao gravar os dados." << endl;
        return false;
    }

    file << quantidade_veiculo << endl;

    for(int i = 0; i < quantidade_veiculo; i++){

        const auto& veiculo = frota[i];
        auto historico = veiculo->getHistoricoViagens();
        string placa, odometro;

        //grava os dados de carro na memoria
        if(Carro* carro = dynamic_cast<Carro*>(veiculo.get())){

            odometro = carro->getHodometro();
            size_t pos = odometro.find("km");
            if(pos != string::npos){
                odometro = odometro.substr(0, pos);
            }

            file << "C " << carro->getPlaca() 
                    + " " + odometro
                    + " " + precisaoDecimal(carro->getNumeroPassageiros(), 2) 
                    + " 0.0" << endl;

            file << carro->getDescricao() << endl;
            placa = carro->getPlaca();
        }

        //grava os dados de onibus na memoria
        if(Onibus* onibus = dynamic_cast<Onibus*>(veiculo.get())){

            odometro = onibus->getHodometro();
            size_t pos = odometro.find("km");
            if(pos != string::npos){
                odometro = odometro.substr(0, pos);
            }
            
            file << "O " << onibus->getPlaca() 
                    + " " + odometro 
                    + " " + precisaoDecimal(onibus->getNumeroPassageiros(), 2) 
                    + " 0.0" << endl;

            file << onibus->getDescricao() << endl;
            placa = onibus->getPlaca();
        }

        //grava os dados de caimnhao leve na memoria
        if(CaminhaoLeve* cl = dynamic_cast<CaminhaoLeve*>(veiculo.get())){

            odometro = cl->getHodometro();
            size_t pos = odometro.find("km");
            if(pos != string::npos){
                odometro = odometro.substr(0, pos);
            }
            
            file << "L " << cl->getPlaca() 
                    + " " + odometro 
                    + " 0 "  + precisaoDecimal(cl->getCarga(), 2) << endl;

            file << cl->getDescricao() << endl;
            placa = cl->getPlaca();
        }

        //grava os dados de caimnhao pesado na memoria
        if(CaminhaoPesado* cp = dynamic_cast<CaminhaoPesado*>(veiculo.get())){

            odometro = cp->getHodometro();
            size_t pos = odometro.find("km");
            if(pos != string::npos){
                odometro = odometro.substr(0, pos);
            }
            
            file << "P " << cp->getPlaca() 
                    + " " + odometro 
                    + " 0 "  + precisaoDecimal(cp->getCarga(), 2) << endl;

            file << cp->getDescricao() << endl;
            placa = cp->getPlaca();
        }

        gravarHistoricos(historico, hist, placa);
    }

    file.close();
    hist.close();

    return true;
}


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