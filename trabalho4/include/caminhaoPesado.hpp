#ifndef CAMINHAOPESADO_HPP
#define CAMINHAOPESADO_HPP

#include "./veiculo.hpp"

class CaminhaoPesado: public Veiculo {

    private:
        float carga;
        void setCarga(float carga);

    public:
        CaminhaoPesado(const string placa, const string descricao, float quilometragem_inicial, float carga);
        ~CaminhaoPesado();

        string toString() const;
        float getCarga() const;
};

#endif