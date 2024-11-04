#ifndef CAMINHAOLEVE_HPP
#define CAMINHAOLEVE_HPP

#include "./veiculo.hpp"

class CaminhaoLeve: public Veiculo {

    public:
        CaminhaoLeve(const string placa, const string descricao, float quilometragem_inicial);
        ~CaminhaoLeve();

        string toString() const;
};


#endif