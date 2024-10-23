#pragma once

#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string> 
#include <sstream>

using namespace std;

class Pessoa {

    protected:
        string nome, endereco, telefone;

    public:
        Pessoa()
        : nome("Nao informado"), endereco("Nao informado"), telefone("(00) 0000-0000"){};

        Pessoa(const string nome)
        : nome(nome), endereco("Nao informado"), telefone("(00) 0000-0000"){};

        Pessoa(const string nome, const string endereco, const string telefone)
        : nome(nome), endereco(endereco), telefone(telefone){};

        ~Pessoa(){};

        void setNome(const string nome){
            this->nome = nome;
        };

        void setTelefone(const string telefone){
            this->telefone = telefone;
        };

        void setEndereco(const string endereco){
            this->endereco = endereco;
        };

        string getNome() const {
            return this->nome;
        };

        string getEndereco() const {
            return this->endereco;
        };

        string getTelefone() const {
            return this->telefone;
        };

        virtual string toString() const {
            ostringstream oss;
            oss << "nome: " << this->nome << ", end:" << this->endereco << ", tel: " << this->telefone;
            return oss.str();
        };
 
};

#endif