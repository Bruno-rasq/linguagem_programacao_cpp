#ifndef CAMINHAOLEVE_HPP
#define CAMINHAOLEVE_HPP

#include "veiculo.hpp"
#include <sstream>

class CaminhaoLeve: public Veiculo {

    public:
        CaminhaoLeve(const string placa, const string descricao, float quilometragem_inicial): 
        Veiculo(placa, descricao, quilometragem_inicial){};
        ~CaminhaoLeve(){};

        string toString() const {
            std::ostringstream oss;
            oss << "Veiculo: Caminhao leve" << endl;
            oss << Veiculo::toString();
            return oss.str();
        }
};


#endif