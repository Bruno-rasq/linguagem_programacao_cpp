#ifndef EMPREGADO_HPP
#define EMPREGADO_HPP

#include "Pessoa.cpp"
#include <sstream>

using namespace std;

class Empregado : public Pessoa {

    private:
        int codigo_setor;
        float salario_base, percentual_imposto;

    public:
        Empregado(
            const string nome, 
            const string endereco, 
            const string tel, 
            int code, 
            float salario, 
            float imposto
        ):
        Pessoa(nome, endereco, telefone), codigo_setor(code), 
        salario_base(salario), percentual_imposto(imposto){};

        ~Empregado(){};

        void setCodigoSetor(int code){
            this->codigo_setor = code;
        };

        void setSalario(float salario){
            this->salario_base = salario;
        };

        void setPercentualImposto(float porcentagem) {
            this->percentual_imposto = porcentagem;
        };

        int getCodigoSetor() const {
            return this->codigo_setor;
        };

        float getSalario() const {
            return this->salario_base;
        };

        float getPercentualImposto() const {
            return this->percentual_imposto;
        };

        virtual float calcularSalario() const {
            float impost_sobre_salario = (this->percentual_imposto * this->salario_base) / 100;
            float salario = this->salario_base - impost_sobre_salario;
            return salario;
        };

        string toString() const override {
            ostringstream oss;
            oss << Pessoa::toString() << ", setor:" << this->codigo_setor << ", salario: R$" << this->salario_base << ", imposto: " << this->percentual_imposto << "%";
            return oss.str();
        }; 

};

#endif