#pragma once

#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Empregado.cpp"

class Administrador : public Empregado {

    private:
        float ajuda_de_custos;

    public:
        Administrador(

            const string nome, 
            const string endereco, 
            const string tel, 
            int code, 
            float salario, 
            float imposto, 
            float ajudadecustos
            
        ): Empregado(nome, endereco, tel, code, salario, imposto), 
        ajuda_de_custos(ajudadecustos){};

        float calcularSalario() const  {
            float salario = Empregado::calcularSalario();
            return this->ajuda_de_custos + salario;
        };
};

#endif