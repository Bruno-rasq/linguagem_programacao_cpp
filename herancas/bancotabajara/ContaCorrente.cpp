#include "ContaCorrente.hpp"
#include <sstream>

using namespace std;

ContaCorrente::ContaCorrente(): saldo(0.0f){};

ContaCorrente::ContaCorrente(float saldo): saldo(saldo){};

ContaCorrente::~ContaCorrente(){};

void ContaCorrente::setSaldo(float valor){
    this->saldo = valor;
}

float ContaCorrente::getSaldo() const {
    return this->saldo;
}

bool ContaCorrente::sacar(float valor){
    if(valor >= 0.0  && valor <= this->saldo){
        this->saldo -= valor;
        return true;
    }
    return false;
}

void ContaCorrente::depositar(float valor){
    this->saldo += valor;
}

string ContaCorrente::toString() const {
    ostringstream oss;
    oss << "Saldo bancario: R$" << this->saldo;
    return oss.str();
}