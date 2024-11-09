#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

#include "../include/cadastros.hpp"
#include "../include/controleMemoria.hpp"

#define MEMORIA_HISTORICOS "./memoria/historico.txt"
#define MEMORIA_VEICULOS "./memoria/memoria.txt"

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
    
    ifstream file(MEMORIA_HISTORICOS);
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

    ifstream file(MEMORIA_VEICULOS);

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