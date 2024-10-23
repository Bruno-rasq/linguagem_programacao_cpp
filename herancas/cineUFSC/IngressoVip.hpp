#ifndef INGRESSOVIP_HPP
#define INGRESSOVIP_HPP

#include "Ingresso.hpp"
#include <string>

using namespace std;

class IngressoVip: public Ingresso {

    private:
        float adicional;
        string descricaovip;

    public:
        IngressoVip();

        IngressoVip(const string descricao, float valor, const string descricaoVip, float adicional);

        ~IngressoVip();

        string toString() const override;

};

#endif