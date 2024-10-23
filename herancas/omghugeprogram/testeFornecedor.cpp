#include "Pessoa.cpp"
#include "Fornecedor.cpp"
#include <iostream>

using namespace std;

int main(){

    Pessoa p1("teste", "teste", "(00) 0000-0000");

    cout << p1.toString() << endl;


    Fornecedor f1("teste", "teste", "(00) 0000-0000", 1000.0f, 500.0f);

    cout << f1.toString() << endl;

    float saldo = f1.obterSaldo();

    cout << "saldo: R$" << to_string(saldo) << endl;
    

    return 0;
}