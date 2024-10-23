#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "Empregado.hpp"
#include <string>

using namespace std;

class Vendedor : public Empregado {

    private:
        float percentual_comissao;

    public:
        Vendedor(){};
        Vendedor(const string nome, float salario, float comissao){};

        ~Vendedor(){};

        float getPercentualComissao() const {};
        void setPercentualComissao(float comissao){};

        float calcularSalario() const {};

        string toString() const {};

};

#endif