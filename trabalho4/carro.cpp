#ifndef CARRO_HPP
#define CARRO_HPP

#include "veiculo.hpp"
#include <sstream>

class Carro: public Veiculo {

    public:
        Carro(const string placa, const string descricao, float quilometragem_inicial): 
        Veiculo(placa, descricao, quilometragem_inicial){};
        ~Carro(){};

        string toString() const {
            std::ostringstream oss;
            oss << "Veiculo: Carro" << endl;
            oss << Veiculo::toString();
            return oss.str();
        }
};

#endif