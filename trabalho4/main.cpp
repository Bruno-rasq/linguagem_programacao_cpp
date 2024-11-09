#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "./include/output.hpp"
#include "./include/veiculo.hpp"
#include "./include/procedimentos.hpp"
#include "./include/cadastros.hpp"

using namespace std;

/**
 *  mêtodo responsavel por de fato adicionar uma nova viagem ao veiculo
 *  assim que o programa inicia e carrega os dados.
 *  meotod novaViagem alem de gravar no historico a viagem atutaliza a
 *  quilometragaem.
*/
void carregarHistoricoEmFrota(
    const string placa,
    const string destino,
    float km,
    float combustivel,
    vector<unique_ptr<Veiculo>>& frota
){
    for(const auto& veiculo: frota){
        if(veiculo->getPlaca() == placa){
            veiculo->novaViagem(destino, km, combustivel);
            return;
        }
    }
}


/**
 *  lê o arquivo que contem os dados dos historicos de visagens dos veiculo
 *  e adiciona esses dados ao veiculos assim que iniciar o programa.
*/
bool carregarHistorico(vector<unique_ptr<Veiculo>>& frota){
    
    ifstream file("./memoria/historico");
    if(file.is_open()){

        string placa, destino;
        float km, combustivel;
        while(file >> placa >> destino >> km >> combustivel){
            carregarHistoricoEmFrota(placa, destino, km , combustivel, frota);
        }

        file.close();
        return true;
    }
    return false;
}


/**
 * Mêtodo responsavel por identificar a classe do veiculo e criar a instancia
 * armazenando-a em frota assim que o programa inicia e carrega os dados.
*/
void carregarVeiculosEmfrota(
    char tipo,
    const string placa,
    const string descricao,
    float odometro,
    int passageiros,
    float carga,
    vector<unique_ptr<Veiculo>>& frota
){

    if(tipo == 'C'){ cadastrarCarro(placa, descricao, odometro, passageiros, frota); }
    if(tipo == 'O'){ cadastrarOnibus(placa, descricao, odometro, passageiros, frota); }
    if(tipo == 'L'){ cadastrarCaminhaoLeve(placa, descricao, odometro, carga, frota); }
    if(tipo == 'P'){ cadastrarCaminhaoPesado(placa, descricao, odometro, carga, frota); }

}


/**
 * mêtodo responsavel por iniciar o carregamento dos dados do programa.
*/
bool carregarDados(vector<unique_ptr<Veiculo>>& frota){ 

    ifstream file("./memoria/memoria.txt");

	if(file.is_open()){

        string  line;
		int     veiculos;

        file >> veiculos;
        file.ignore();
        
        for(int i = 0; i < veiculos; i++){

            char    tipo;
            string  placa,          descricao;
            float   odometro,       carga;
            int     passageiros;

            file >> tipo >> placa >> odometro >> passageiros >> carga;
            file.ignore();

            getline(file, descricao);

            carregarVeiculosEmfrota(tipo, placa, descricao, odometro, passageiros, carga, frota);
        }

        bool dadoscarregados = carregarHistorico(frota);
        if(!dadoscarregados){
            cout << "erro ao carregar dados de viagens" << endl;
        }

		file.close();
		return true;
	}
	return false;
}


//implementando...
void gravarDados(vector<unique_ptr<Veiculo>>& frota){ cout << "salvando dados..." << endl;}


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