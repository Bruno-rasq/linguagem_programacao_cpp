#pragma once

#ifndef FORNECEDOR_HPP
#define FORNECEDOR_HPP

#include "Pessoa.cpp"
#include <sstream>

using namespace std;

class Fornecedor: public Pessoa {

    private:
        float credito_max, valor_divida;

    public:
        Fornecedor(): Pessoa(), credito_max(0.0), valor_divida(0.0){};

        Fornecedor(const string nome, const string endereco, const string tel, float creditomax, float valordivida)
        : Pessoa(nome, endereco, telefone), credito_max(creditomax), valor_divida(valordivida){};

        ~Fornecedor(){};

        float obterSaldo() const {
            return this->credito_max - this->valor_divida;
        };

        string toString() const override {
            ostringstream oss;
            oss << Pessoa::toString() << ", credito: R$" << this-> credito_max << ", divida: R$" << this->valor_divida;
            return oss.str();
        }; 
};

#endif