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

    public:
        Cinema(){}
        ~Cinema(){}

        void getPoltronasDaSessao(string ID){
            for(auto& sala: this->sessoes){
                if(sala.getID() == ID){
                    sala.exibirMapaPoltronas();
                }
            }
        }


        void getInfoAllSessoes() const {

            cout << "| FILMES DISPONIVEIS |" << endl << endl;
            cout << "[Sessao]   Titulo - Genero - Classificacao indicativa - Duracao" << endl << endl;
            for(int i = 0; i < this->sessoes.size(); i++){
                cout << this->sessoes[i].getID() << "   " << this->sessoes[i].getFilme()  << endl;
            }
        }

        bool ocuparPoltronaSessao(const string& ID, int fileira, int coluna){
            for(int i = 0; i < this->sessoes.size(); i++){
                if(this->sessoes[i].getID() == ID){
                    return this->sessoes[i].ocuparPoltrona(fileira, coluna);
                }
            }
            return false;
        }

        void adicionarSessao(SalaDeCinema sessao){
            this->sessoes.push_back(sessao);
        }

};

void ExibirMenu(){
    ostringstream oss;

    oss << endl << endl;
    oss << "---------------------------------" << endl;
    oss << "|          Cinema Teste         |" << endl;
    oss << "---------------------------------" << endl;
    oss << "     selecione uma opcao         " << endl;
    oss << "                                 " << endl;
    oss << "     1 Ver Filmes em cartaz      " << endl;
    oss << "     2 comprar Bilhete           " << endl;
    oss << "     3 sair.                     " << endl;

    cout << oss.str() << endl;
}

int main(){

    Filme filme1("Bug o filme",  "ficcao",  "livre", 1.45);
    Filme filme2("for____loop",  "terror",  "+18",   1.50);
    Filme filme3("Bit &7 Byte",  "desenho", "livre", 2.20);

    SalaDeCinema sala01("SL-001", filme1, 4);
    SalaDeCinema sala02("SL-002", filme2, 4);
    SalaDeCinema sala03("SL-003", filme3, 4);

    Cinema cinema;

    cinema.adicionarSessao(sala01);
    cinema.adicionarSessao(sala02);
    cinema.adicionarSessao(sala03);

    while(true){

        ExibirMenu();
        int opcao;
        cin >> opcao;

        switch(opcao){

            case 1: { cinema.getInfoAllSessoes(); break; }
            case 2: {

                string sessao;
                int fileira, coluna;

                cinema.getInfoAllSessoes();
                cin >> sessao;

                cout << "| ESCOLHA SUA POLTRONA (pxx indisponiveis)" << endl << endl;
                cinema.getPoltronasDaSessao(sessao);
                cout << "fileira:" << endl;
                cin >> fileira;
                cout << "coluna:" << endl;
                cin >> coluna;

                bool resposta = cinema.ocuparPoltronaSessao(sessao, fileira, coluna);

                cout << (resposta == true ? "Bom filme!" : "algo deu errado!") << endl;

                break;
            }


            case 3: { return 1; }
            default: { break; }
        }

    }

    return 0;
}