#ifndef CONTACORRENTE_HPP
#define CONTACORRENTE_HPP

#include <string>

using namespace std;

class ContaCorrente {

    protected:
        float saldo;

        void setSaldo(float valor);
        float getSaldo() const ;

    public:

        ContaCorrente();
        ContaCorrente(float saldo);

        virtual ~ContaCorrente();

        virtual bool sacar(float valor);
        virtual void depositar(float valor);

        virtual string toString() const ;

};

#endif