#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include "veiculo.hpp"
#include <sstream>

class Onibus: public Veiculo {

    public:
        Onibus(const string placa, const string descricao, float quilometragem_inicial): 
        Veiculo(placa, descricao, quilometragem_inicial){};
        ~Onibus(){};

        string toString() const {
            std::ostringstream oss;
            oss << "Veiculo: Onibus" << endl;
            oss << Veiculo::toString();
            return oss.str();
        }
};

#endif