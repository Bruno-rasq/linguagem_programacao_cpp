#include "ContaEspecial.hpp"
#include <sstream>

using namespace std;

ContaEspecial::ContaEspecial(float saldo, float limite)
: ContaCorrente(saldo), limite(limite){};

ContaEspecial::~ContaEspecial(){};

bool ContaEspecial::sacar(float valor){
    float limite_negativo = - this->limite;

    //verifica se há saldo suficiente ou se o valor do saque não ultrapassa o limite de credito
    bool saldo_suficiente = this->saldo >= valor;
    bool dentro_limite_credito = this->saldo < valor && this->saldo - valor >= limite_negativo;

    if(saldo_suficiente || dentro_limite_credito){ 
        this->saldo -= valor;
        return true;
    } 

    return false;
}

string ContaEspecial::toString() const {
    ostringstream oss;
    oss << ContaCorrente::toString() << ", limite: R$" << this->limite;
    return oss.str();
}

void ContaEspecial::setLimite(float limite){
    this->limite = limite;
}

float ContaEspecial::getLimite() const {
    return this->limite;
}