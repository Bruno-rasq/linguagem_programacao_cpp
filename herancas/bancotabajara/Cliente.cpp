#include "Cliente.hpp"
#include <sstream>

using namespace std;

Cliente::Cliente(): nome(""){};

Cliente::Cliente(const string nome): nome(nome){};

Cliente::~Cliente(){};

void Cliente::setNome(const string nome){
    this->nome = nome;
}

string Cliente::getNome() const {
    return this->nome;
}

void Cliente::setContas(ContaCorrente conta){
    this->contas.push_back(conta);
}

vector<ContaCorrente> Cliente::getContas(){
    return this->contas;
}

string Cliente::toString() const {
    ostringstream oss;
    oss << "cliente: " << this->nome;
    return oss.str();
}