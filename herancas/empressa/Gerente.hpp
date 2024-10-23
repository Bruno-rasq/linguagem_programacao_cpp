#pragma once

#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "Empregado.hpp"
#include <string>

using namespace std;

class Gerente : public Empregado {

    private:
        string departamento;

    public:
        Gerente();
        Gerente(const string nome, float salario, const string departamento);

        ~Gerente();

        string getDepartamento() const ;
        void setDepartamento(const string departamento);

        string toString() const override ;
};

#endif