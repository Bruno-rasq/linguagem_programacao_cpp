#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include "./veiculo.hpp"

class Onibus: public Veiculo {

    public:
        Onibus(const string placa, const string descricao, float quilometragem_inicial);
        ~Onibus();

        string toString() const;
};

#endif