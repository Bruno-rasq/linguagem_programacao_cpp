#include "Empregado.hpp"
#include "Gerente.hpp"
#include "Vendedor.hpp"
#include <iostream>

using namespace std;

int main(){


    Empregado empregado("joao", 1400.50f);
    Vendedor joao("joao", 1400.50f, 15.5f);
    Gerente Joao_g("joao", 3500.50f, "vendas");

    cout << empregado.toString() << endl;
    cout << joao.toString() << endl;
    cout << Joao_g.toString() << endl;


    return 0;
}