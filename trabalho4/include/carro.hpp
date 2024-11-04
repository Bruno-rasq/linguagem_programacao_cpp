#ifndef CARRO_HPP
#define CARRO_HPP

#include "./veiculo.hpp"

class Carro: public Veiculo {

    public:
        Carro(const string placa, const string descricao, float quilometragem_inicial);
        ~Carro();

        string toString() const;
};

#endif