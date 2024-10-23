#include "Vendedor.hpp"
#include <sstream>

using namespace std;

Vendedor::Vendedor(): Empregado(), percentual_comissao(0.0){};

Vendedor::Vendedor(const string nome, float salario, float comissao): 
Empregado(nome, salario), percentual_comissao(comissao){};

Vendedor::~Vendedor(){};

string Vendedor::toString() const {
    ostringstream oss;
    oss << Empregado::toString() << ", comissao: " << this->percentual_comissao << "%, salrio+bonus: R$" << this->calcularSalario();
    return oss.str(); 
}

void Vendedor::setPercentualComissao(float comissao){
    this->percentual_comissao = comissao;
}

float Vendedor::getPercentualComissao() const {
    return this->percentual_comissao;
}

float Vendedor::calcularSalario() const {
    float salario_com_bonus = this->salario + ((this->salario * this->percentual_comissao) / 100);
}