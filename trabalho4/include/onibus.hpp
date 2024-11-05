#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include "./veiculo.hpp"

class Onibus: public Veiculo {

    private:
        int numero_passageiros;
        void setPassageiros(int passageiros);

    public:
        Onibus(const string placa, const string descricao, float quilometragem_inicial, int passageiros);
        ~Onibus();

        string toString() const;
        int getNumeroPassageiros() const;
};

#endif