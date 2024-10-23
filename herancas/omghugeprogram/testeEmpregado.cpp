#include "Empregado.cpp"
#include <iostream>

using namespace std;

int main() {

    Empregado e("teste", "teste", "(00) 0000-0000", 5, 2500.50f, 7.5f);

    cout << e.toString() << endl;

    float salario = e.calcularSalario();

    cout << "salario com imposto: R$" << to_string(salario) << endl;

    return 0;
}