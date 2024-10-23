#include "Gerente.hpp"
#include <sstream>

using namespace std;

Gerente::Gerente(): Empregado(), departamento(""){};

Gerente::Gerente(const string nome, float salario, const string departamento): 
Empregado(nome, salario), departamento(departamento){};

Gerente::~Gerente(){};

void Gerente::setDepartamento(const string departamento){
    this->departamento = departamento;
}

string Gerente::getDepartamento() const {
    return this->departamento;
}

string Gerente::toString() const {
    ostringstream oss;
    oss << Empregado::toString() << ", departamento; " << this->departamento;
    return oss.str();
}