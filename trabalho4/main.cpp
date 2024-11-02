#include <iostream>
#include "veiculo.hpp"
#include <vector>
#include <tuple>
#include <iomanip>
#include <sstream>

//g++ main.cpp source/veiculo.cpp -o programa
//g++ -Iheaders main.cpp source/veiculo.cpp -o programa

using namespace std;

int main() {

    Veiculo carro("abc123", "carro economico", 0.0);

    carro.novaViagem("fortaleza", 500, 200);
    carro.novaViagem("ararangua", 100, 50);
    carro.novaViagem("porto alegre", 400, 100);


    cout << "CARRO" << endl;
    cout << "PLACA: " + carro.getPlaca() << endl;
    cout << "DESCR: " + carro.getDescricao() << endl;
    cout << "hodometro: " << carro.getHodometro() << endl << endl;

    cout << "historico de viagems:" << endl;
    auto viagens = carro.getHistoricoViagens();

    for(int i = 0; i < viagens.size(); i++){
        auto viagem = viagens[i];

        string destino = get<0>(viagem);
        float km = get<1>(viagem);
        float combustivel = get<2>(viagem);

        cout << destino + " " + to_string(km) + " " + to_string(combustivel) << endl;
    }

    ostringstream oss;
    oss << "quilometragem atual: ";
    oss << fixed << setprecision(2) << carro.getQuilometragemAtual();
    oss << "km";

    cout << oss.str() << endl;

    return 0;
}