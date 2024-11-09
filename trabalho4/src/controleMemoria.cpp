#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

#include "../include/cadastros.hpp"
#include "../include/controleMemoria.hpp"
#include "../include/procedimentos.hpp"

#include "../include/carro.hpp"
#include "../include/onibus.hpp"
#include "../include/caminhaoLeve.hpp"
#include "../include/caminhaoPesado.hpp"

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


void gravarHistoricos(vector<tuple<string, float, float>>& historico, ofstream& arquivo, const string placa){

    for(int i = 0; i < historico.size(); i++){
        auto viagem = historico[i];

        string destino = get<0>(viagem);
        string km = precisaoDecimal(get<1>(viagem), 2);
        string combustivel = precisaoDecimal(get<2>(viagem), 2);

        arquivo << placa + " " + destino + " " + km + " " + combustivel << endl;
    }
}

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