#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Filme {
    private:
        string nome;
        string genero;
        string faixa_etaria;
        float duracao;

    public:
        Filme(){}
        Filme(const string& nome, const string& genero, const string& FE, float duracao):
        nome(nome), genero(genero), faixa_etaria(FE), duracao(duracao){}

        ~Filme(){};

        string getNome()        const { return this->nome; }
        string getGenero()      const { return this->genero; }
        string getFaicaEtaria() const { return this->faixa_etaria; }
        float  getDuracao()     const { return this->duracao; }
};

class SalaDeCinema {
    private:
        int fileiras;
        string ID;
        Filme filme;
        vector<vector<bool>> poltronas;

    public:
        SalaDeCinema(const string& id, Filme filme, int fileiras){
            this->ID = id;
            this->filme = filme;
            this->fileiras = fileiras;
            this->setPoltronas(this->fileiras);
        }

        string getID() const { return this->ID; }

        void setPoltronas(int fileiras){
            for(int linha = 0; linha < fileiras; linha++){
                vector<bool> fileira;
                for(int coluna = 0; coluna < 10; coluna++){
                    fileira.push_back(true);
                }
                this->poltronas.push_back(fileira);
            }
        }

        void exibirMapaPoltronas(){
            for(int linha = 0; linha < this->fileiras; linha++){
                string fileira = "";
                for(int coluna = 0; coluna < 10; coluna++){

                    string poltrona = this->poltronas[linha][coluna] == true ? 
                    "P" + to_string(linha) + to_string(coluna): "PXX";

                    fileira +=  poltrona + "   ";
                }
                cout << fileira << endl;
            }
        }

        bool ocuparPoltrona(int fileira, int coluna){

            if(fileira >= 0 && fileira <= this->fileiras && coluna >= 0 && coluna <= 10){

                if(this->poltronas[fileira][coluna] == true){
                    this->poltronas[fileira][coluna] = false;
                    return true;
                }
            }
            return false;
        }

        string getFilme() const {

            ostringstream oss;

            oss << this->filme.getNome() << " - ";
            oss << this->filme.getGenero() << " - ";
            oss << this->filme.getFaicaEtaria() << " - ";
            oss << this->filme.getDuracao()  << "";

            return oss.str();
        }
};

class Cinema {
    private:
        vector<SalaDeCinema> sessoes;

        void getPoltronasDaSessao(string ID){
            for(auto& sala: this->sessoes){
                if(sala.getID() == ID){
                    sala.exibirMapaPoltronas();
                }
            }
        }

        void getInfoFilmeSessao (const string& ID){
            for(int i = 0; i < this->sessoes.size(); i++){
                if(this->sessoes[i].getID() == ID){
                    this->sessoes[i].getFilme();
                }
            }
        }

        void getInfoAllSessoes() const {
            for(int i = 0; i < this->sessoes.size(); i++){
                cout << this->sessoes[i].getFilme() << endl << endl;
            }
        }

        bool ocuparPoltronaSessao(const string& ID, int fileira, int coluna){
            for(int i = 0; i < this->sessoes.size(); i++){
                if(this->sessoes[i].getID() == ID){
                    this->sessoes[i].ocuparPoltrona(fileira, coluna);
                    return true;
                }
            }
            return false;
        }

        void adicionarSessao(SalaDeCinema sessao){
            this->sessoes.push_back(sessao);
        }

    public:
        Cinema(){}
        ~Cinema(){}

};

int main(){

    Filme filme1("Bug o filme", "ficcao", "livre", 1.45);
    Filme filme2("for loop", "terror", "+18", 1.50);
    Filme filme3("Bit and Byte", "desenho", "livre", 2.20);

    SalaDeCinema sala01("SL-001", filme1, 4);
    SalaDeCinema sala02("SL-001", filme2, 4);
    SalaDeCinema sala03("SL-001", filme3, 4);

    Cinema cinema();

    // cinema.adicionarSessao(sala01);
    // cinema.adicionarSessao(sala02);
    // cinema.adicionarSessao(sala03);

    // cout << "sala inical:" << endl;
    // sala.exibirMapaPoltronas();

    // sala.ocuparPoltrona(0, 0);
    // sala.ocuparPoltrona(0, 1);
    // sala.ocuparPoltrona(0, 2);
    // sala.ocuparPoltrona(0, 3);
    // sala.ocuparPoltrona(0, 4);
    // sala.ocuparPoltrona(0, 5);


    // cout << "sala atual:" << endl;
    // sala.exibirMapaPoltronas();

    return 0;
}