#include "Empregado.hpp"
#include <sstream>

using namespace std;

Empregado::Empregado(): nome(" "), salario(0.0f){};

Empregado::Empregado(const string nome, float salario): nome(nome), salario(salario){};

Empregado::~Empregado(){};

string Empregado::toString() const {
    ostringstream oss;
    oss << "Empregado: " << this->nome << ", salario: R$" << this->salario;
    return oss.str();
}

string Empregado::getNome() const {
    return this->nome;
}

float Empregado::getSalario() const {
    return this->salario;
}

void Empregado::setNome(const string nome){
    this->nome = nome;
}

void Empregado::setSalario(float salario){
    this->salario = salario;
}