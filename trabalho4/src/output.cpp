#include "../include/output.hpp"

#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string menu(){
    ostringstream oss;
    
    oss << "UFSC VEHICLE MANAGER SYSTEM (UVMS)\n";
    oss << "----------------------------------\n";
    oss << "1.cadastrar novo veiculo.\n";
    oss << "2.Cadastrar viagem para um veiculo.\n";
    oss << "3.Mostrar relatorio (geral).\n";
    oss << "4.Pesquisar veiculo (por placa).\n";
    oss << "5.sair.\n";

    return oss.str();
}

string menuTiposDeVeiculos(){
    ostringstream oss;
    
    oss << "ESCOLHA UM TIPO DE VEICULO PARAR CADASTRAR:\n";
    oss << "-------------------------------------------\n";
    oss << "c - carro              (comporta ate 4 passageiros)\n";
    oss << "o - onibus             (comporta ate 32 passageiros)\n";
    oss << "l - caminhao leve      (carga maxima de 15000kg)\n";
    oss << "p - caminhao pesado    (carga maxima de 30000kg)\n";

    return oss.str();
}