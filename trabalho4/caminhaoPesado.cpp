#ifndef CAMINHAOPESADO_HPP
#define CAMINHAOPESADO_HPP

#include "veiculo.hpp"
#include <sstream>

class CaminhaoPesado: public Veiculo {

    public:
        CaminhaoPesado(const string placa, const string descricao, float quilometragem_inicial): 
        Veiculo(placa, descricao, quilometragem_inicial){};
        ~CaminhaoPesado(){};

        string toString() const {
            std::ostringstream oss;
            oss << "Veiculo: Caminhao pesado" << endl;
            oss << Veiculo::toString();
            return oss.str();
        }
};


#endif