#include "Administrador.cpp"
#include <iostream>

using namespace std;

int main(){

    Administrador a("adm", "teste", "(00) 0000-0000", 5, 5000.0f, 20.0f, 2500.0f);

    cout << a.toString() << endl;

    float salario = a.calcularSalario();

    cout << "salario com imposto: R$" << to_string(salario) << endl;

    return 0;
}