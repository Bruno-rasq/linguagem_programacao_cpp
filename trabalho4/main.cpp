#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <sstream>

#include "carro.cpp"
#include "onibus.cpp"
#include "caminhaoLeve.cpp"
#include "caminhaoPesado.cpp"

using namespace std;

//g++ -o programa main.cpp veiculo.cpp carro.cpp onibus.cpp caminhaoLeve.cpp caminhaoPesado.cpp
//g++ main.cpp source/veiculo.cpp -o programa
//g++ -Iheaders main.cpp source/veiculo.cpp -o programa

string precisaoDecimal(float valor, int casas){
    ostringstream oss;
    oss << fixed << setprecision(casas) << valor;
    return oss.str();
}

void exibirHistoricoDeViagens(vector<tuple<string, float, float>>& viagens){
    cout << "historico de viagems:" << endl;
    for(int i = 0; i < viagens.size(); i++){
        auto viagem = viagens[i];

        string destino = get<0>(viagem);
        string km = precisaoDecimal(get<1>(viagem), 2);
        string combustivel = precisaoDecimal(get<2>(viagem), 2);

        cout << destino + " " + km + " " + combustivel << endl;
    }
    cout << endl;
}

int main() {

    Carro veiculo1("abc123", "carro economico", 0.0);
    Onibus veiculo2("def456", "onibus escolar", 0.0);
    CaminhaoLeve veiculo3("ghi789", "caminhao leve", 0.0);
    CaminhaoPesado veiculo4("jkl012", "caminhao pesado", 0.0);

    veiculo1.novaViagem("desinto", 500, 100);
    veiculo1.novaViagem("desinto", 5500, 600);
    veiculo2.novaViagem("desinto", 400, 80);
    veiculo2.novaViagem("desinto", 500, 100);
    veiculo3.novaViagem("desinto", 50, 20);
    veiculo4.novaViagem("desinto", 500, 100);

    cout << veiculo1.toString() << endl;
    auto v1Viagens = veiculo1.getHistoricoViagens();
    exibirHistoricoDeViagens(v1Viagens);
    cout << "quilometragem total: " + veiculo1.getQuilometragemAtual() << endl << endl;

    cout << veiculo2.toString() << endl;
    auto v2Viagens = veiculo2.getHistoricoViagens();
    exibirHistoricoDeViagens(v2Viagens);
    cout << "quilometragem total: " + veiculo2.getQuilometragemAtual() << endl << endl;

    cout << veiculo3.toString() << endl;
    auto v3Viagens = veiculo1.getHistoricoViagens();
    exibirHistoricoDeViagens(v3Viagens);
    cout << "quilometragem total: " + veiculo3.getQuilometragemAtual() << endl << endl;

    cout << veiculo4.toString() << endl;
    auto v4Viagens = veiculo1.getHistoricoViagens();
    exibirHistoricoDeViagens(v4Viagens);
    cout << "quilometragem total: " + veiculo4.getQuilometragemAtual() << endl << endl;

    return 0;
}