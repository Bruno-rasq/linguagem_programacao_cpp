#pragma once

#ifndef OPERARIO_HPP
#define OPERARIO_HPP

#include "Empregado.cpp"

using namespace std;

class Operario : public Empregado {

    private:
        float valor_producao, comissao;

    public:
        Operario(
            const string nome, 
            const string endereco, 
            const string tel, int code, 
            float salario, 
            float imposto,
            float valorProducao,
            float comissao
            
        ): Empregado(nome, endereco, tel, code, salario, imposto), 
        valor_producao(valorProducao), comissao(comissao){};

        ~Operario(){};

        float calcularSalario() const override {
            float acrescimo = (this->valor_producao * this->comissao) / 100;
            float salario = Empregado::calcularSalario();
            return salario + acrescimo;
        };

};

#endif