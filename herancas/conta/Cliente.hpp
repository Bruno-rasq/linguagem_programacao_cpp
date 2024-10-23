#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "ContaCorrente.hpp"
#include <string>
#include <vector>

using namespace std;

class Cliente {

    private:
        string nome;
        vector<ContaCorrente> contas;

    public:

        Cliente();
        Cliente(const string nome);

        ~Cliente();

        void setNome(const string nome);
        string getNome() const ;

        void setContas(ContaCorrente conta);
        vector<ContaCorrente> getContas() ;

        string toString() const ;
};

#endif