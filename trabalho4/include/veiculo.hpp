#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>
#include <vector>
#include <tuple>

using namespace std;

class Veiculo {

    protected:

        string PLACA, DESCRICAO;
        float HODOMETRO;
        float quilometragem_atual;

        //destino - km - combustivel
        vector<tuple<string, float, float>> historico_viagens;


    public:

        ~Veiculo();
        Veiculo(const string placa, const string descricao, float quilometragem_inicial);

        string getPlaca() const;
        string getDescricao() const;
        string getHodometro() const;
        string getQuilometragemAtual() const;
        vector<tuple<string, float, float>> getHistoricoViagens() const;

        virtual string toString() const;

        void novaViagem(const string destino, float km, float combustivel);
        void setQuilometragemAtual(float km);
        void setHistoricoViagens(const string destino,float km, float combustivel);

        float consumoMedio() const;
};

#endif