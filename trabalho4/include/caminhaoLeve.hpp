#ifndef CAMINHAOLEVE_HPP
#define CAMINHAOLEVE_HPP

#include "./veiculo.hpp"

class CaminhaoLeve: public Veiculo {

    private:
        float carga;
        void setCarga(float carga);

    public:
        CaminhaoLeve(const string placa, const string descricao, float quilometragem_inicial, float carga);
        ~CaminhaoLeve();

        string toString() const;
        float getCarga() const;
};


#endif