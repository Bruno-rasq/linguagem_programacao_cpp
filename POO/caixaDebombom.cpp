#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doce {
    protected:
        string nome;
    public:
        Doce(const string& doce): nome(doce){};
        virtual ~Doce() = default;

        virtual void comer() const = 0; //metodo virtual puro para consomir o doce (polimorfismo)
};

class Chocolate: public Doce {
    public:
        Chocolate(const string& nome): Doce(nome){};

        void comer() const override {
            cout << "comendo chocolate " << this->nome << endl;
        }
};

class Bala : public Doce {
    public:
        Bala(const string& nome): Doce(nome){};

        void comer() const override {
            cout << "comendo uma bala " << this->nome << endl;
        }
};

int main(){

    vector<Doce*> caixa_de_bombom;

    caixa_de_bombom.push_back(new Chocolate("bis"));
    caixa_de_bombom.push_back(new Chocolate("trento"));
    caixa_de_bombom.push_back(new Chocolate("charge"));
    caixa_de_bombom.push_back(new Bala("mms"));
    caixa_de_bombom.push_back(new Bala("goma"));
    caixa_de_bombom.push_back(new Bala("kriptonita"));

    for(const auto& doce : caixa_de_bombom ){
        doce->comer();
    }

    return 0;
}