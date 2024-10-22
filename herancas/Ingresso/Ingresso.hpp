#ifndef INGRESSO_HPP
#define INGRESSO_HPP

#include <string>

class Ingresso {

    protected:
        std::string descricao;
        float valor;

    public:
        Ingresso();
        Ingresso(const std::string descricao_ingresso, float valor);

        virtual ~Ingresso();

        virtual std::string toString() const;

};

#endif