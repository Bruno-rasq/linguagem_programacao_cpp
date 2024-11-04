#ifndef CAMINHAOPESADO_HPP
#define CAMINHAOPESADO_HPP

#include "./veiculo.hpp"

class CaminhaoPesado: public Veiculo {

    public:
        CaminhaoPesado(const string placa, const string descricao, float quilometragem_inicial);
        ~CaminhaoPesado();

        string toString() const;
};

#endif