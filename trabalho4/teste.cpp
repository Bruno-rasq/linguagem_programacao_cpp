#include <iostream>

#include "./include/carro.hpp"
#include "./include/onibus.hpp"
#include "./include/caminhaoLeve.hpp"
#include "./include/caminhaoPesado.hpp"
#include "./include/procedimentos.hpp"

using namespace std;

int main() {

    Carro veiculo1("abc123", "carro economico", 0.0, 3);
    Onibus veiculo2("def456", "onibus escolar", 0.0, 32);
    CaminhaoLeve veiculo3("ghi789", "caminhao leve", 0.0, 300);
    CaminhaoPesado veiculo4("jkl012", "caminhao pesado", 0.0, 25000);

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
    auto v3Viagens = veiculo3.getHistoricoViagens();
    exibirHistoricoDeViagens(v3Viagens);
    cout << "quilometragem total: " + veiculo3.getQuilometragemAtual() << endl << endl;

    cout << veiculo4.toString() << endl;
    auto v4Viagens = veiculo4.getHistoricoViagens();
    exibirHistoricoDeViagens(v4Viagens);
    cout << "quilometragem total: " + veiculo4.getQuilometragemAtual() << endl << endl;

    veiculo1.setQuilometragemAtual(10.0);

    return 0;
}