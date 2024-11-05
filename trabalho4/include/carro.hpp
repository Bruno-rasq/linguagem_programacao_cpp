#ifndef CARRO_HPP
#define CARRO_HPP

#include "./veiculo.hpp"

class Carro: public Veiculo {

    private:
        int numero_passageiros;
        void setPassageiros(int passageiros);

    public:
        Carro(const string placa, const string descricao, float quilometragem_inicial, int passageiros);
        ~Carro();

        string toString() const;
        int getNumeroPassageiros() const;
};

#endif