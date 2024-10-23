#ifndef CONTAESPECIAL_HPP
#define CONTAESPECIAL_HPP

#include "ContaCorrente.hpp"
#include <string>

using namespace std;

class ContaEspecial : public ContaCorrente {

    private:
        float limite;

    public:
        ContaEspecial(float saldo, float limite);

        ~ContaEspecial();

        string toString() const override ;
        bool sacar(float valor) override ;

        void setLimite(float limite);
        float getLimite() const ;
};

#endif