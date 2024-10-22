#include "Ingresso.hpp"
#include <sstream>

using namespace std;

Ingresso::Ingresso(): descricao(""), valor(0.0f){}

Ingresso::Ingresso(const string descricao, float valor): descricao(descricao), valor(valor){}

Ingresso::~Ingresso(){}

string Ingresso::toString() const {
    std::ostringstream oss;
    oss << "Descricao: " << this->descricao << " - valor: R$" << this->valor;
    return oss.str();
}