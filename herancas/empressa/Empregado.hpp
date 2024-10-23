#ifndef EMPREGADO_HPP
#define EMPREGADO_HPP

#include <string>

using namespace std;

class Empregado {

    public:
        string nome;

    protected:
        float salario;

    public:
        Empregado(){};
        Empregado(const string nome, float salario){};

        virtual ~Empregado(){};

        virtual string toString() const {};

    protected:

        //estes metodos são protegidos para que as classes filhas tenham acesso a eles.
        string getNome() const {};
        float getSalario() const {};

        void setNome(const string nome){};
        void setSalario(float salario){};
};

#endif