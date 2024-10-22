#include "IngressoVip.hpp"
#include <sstream>

using namespace std;

IngressoVip::IngressoVip(): Ingresso(), descricaovip(""), adicional(0.0f){};

IngressoVip::IngressoVip(const string descricao, float valor, const string descricaoVip, float adicional):
Ingresso(descricao, valor), descricaovip(descricaoVip), adicional(adicional){};

IngressoVip::~IngressoVip(){};

string IngressoVip::toString() const {
    std::ostringstream oss;
    oss << Ingresso::toString() << "Bonus: " << this->descricaovip << " -- adicional: R$" << this->adicional;
    return oss.str();
};