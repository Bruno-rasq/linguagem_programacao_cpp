#include "Cliente.hpp"
#include "ContaCorrente.hpp"
#include "ContaEspecial.hpp"
#include <iostream>

using namespace std;

int main(){

    Cliente cliente_teste("cliente test");
    ContaCorrente conta1(5000.50f);
    ContaEspecial conta2(1000.0f, 1000.0f);

    cliente_teste.setContas(conta1);

    cout << cliente_teste.toString() << endl;
    cout << conta1.toString() << endl;

    conta1.depositar(50.0f);

    cout << conta1.toString() << endl;

    bool saque_concluido = conta1.sacar(1000.0f);
    if(saque_concluido){
        cout << "Saque concluido com sucesso." << endl;
    }

    cout << conta1.toString() << endl;


    bool saque_conta_especial_concluido = conta2.sacar(1500.0f);
    cout << conta2.toString() << endl;

    if(saque_conta_especial_concluido){
        cout << "Saque concluido com sucesso." << endl;
    }

    cout << conta2.toString() << endl;

    
    bool saque_conta_especial_falhou = conta2.sacar(1500.0f);
    if(!saque_conta_especial_falhou){
        cout << "Saque falhou! voce excedeu seu limite de credito." << endl;
    }

    cout << conta2.toString() << endl;

    return 0;
}