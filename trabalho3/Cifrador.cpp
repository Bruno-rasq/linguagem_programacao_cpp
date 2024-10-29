#include <vector>
#include <utility>
#include <string>
#include <sstream>

#include "Cifrador.hpp"

using namespace std;

//auxiliares
string Cifrador::isDecodedTextEmpty() const {
    if(this->decodedtext.empty()){
        return this->encodedtext;
    }
    return this->decodedtext;
}


//construtores com distribuicao de cargas
Cifrador::Cifrador(): encodedtext(""), decodedtext(""){
    Cifrador::setCharFrequences();
};

Cifrador::Cifrador(const string txt, bool isdecoded): Cifrador(){
    if(isdecoded){
        this->decodedtext = txt;
        this->encodedtext = "";
    } else {
        this->decodedtext = "";
        this->encodedtext = txt;
    }
};

Cifrador::Cifrador(const string txt, bool isdecoded, int key): Cifrador(txt, isdecoded){
    Cifrador::setEncodingTable(key);
};


//setters
void Cifrador::setEncodingTable(int key){
    for(size_t i = 0; i < 256; i++){

        /*
            explicacao: (i + key) % 256
            i = indice
            key = desvio
            % 256 é uma forma de iterar sobre elementos de um vetor ou lista de forma circular.

            exem: vector<int> v = {1, 2, 3}; tamanho é 3 porem o ultimo indice será o 2

            caso tente acessar o elemento no indice 3 recebe um erro de out range

            quando calcula o resto da divisao do indice pelo tamanho do vetor sempre vai dar um valor 
            dentro do indices validos.

            0 % 3 -> resta 0 -> primeiro elemento
            1 % 3 -> resta 1 -> segundo elemento
            2 % 3 -> resta 2 -> segundo elemento
            agora..
            3 % 3 -> resta 0 -> primeiro elemento novamente...
            4 % 3 -> resta 1 -> segundo elemento novamente...
            ...
        */

        unsigned char ch = static_cast<unsigned char>(i); 
        unsigned char encodedCh = static_cast<unsigned char>((i + key) % 256); 

        pair<unsigned char, unsigned char> p(ch, encodedCh);
        this->encodingTable.push_back(p);
    }
};

void Cifrador::setEncodedText(const string txt){
    this->encodedtext = txt;
};

void Cifrador::setDecodedText(const string txt){
    this->decodedtext = txt;
};

void Cifrador::setCharFrequences(){

    //inicializa  o veotr que armazena a frequencia dos caracters.
    for(size_t i = 0; i < 256; i++){
        pair<unsigned char, size_t> p (i, 0);
        this->charFrequences.push_back(p);
    }
};

void Cifrador::countCharFrequences(){

    //itera sobre cada caracter da string e armazena sua frquencia.
    string text = Cifrador::isDecodedTextEmpty();
    for(size_t i = 0; i < text.size(); i++){
        char ch = text.at(i);                           
        charFrequences.at(ch).second++;
    }
}


//getters
string Cifrador::getDecodedText() const {
    return this->decodedtext;
};

string Cifrador::getEncodedText() const {
    return this->encodedtext;
};

vector<pair<unsigned char, size_t>> Cifrador::getCharFrequences() {

    //antes de devolver o vetor remove caracteres que possuem frequencia 0.
    size_t pos = 0;
    while(pos < this->charFrequences.size()){
        if(this->charFrequences.at(pos).second == 0){
            this->charFrequences.erase(this->charFrequences.begin() + pos);
        } else {
            pos++;
        }
    };
    
    return this->charFrequences;
}



/**
 * obs: o valor padrão para parametros deve ser especificado apenas na declaracap 
 * do metodo no cabeçalho .hpp
*/
string Cifrador::encode(const string txt) {
    string text = txt.empty() ? this->decodedtext : txt;
    stringstream sst;

    for(size_t i = 0; i < text.size(); i++){
        char ch = text.at(i);

        for(size_t j = 0; j < this->encodingTable.size(); j++){
            if(ch == this->encodingTable.at(j).first){
                sst << this->encodingTable.at(j).second;
                break;
            }
        }
    }

    return sst.str();
};

string Cifrador::decode(const string txt) {
    string text = txt.empty() ? this->encodedtext : txt;
    stringstream sst;

    for(size_t i = 0; i < text.size(); i++){
        char ch = text.at(i);

        for(size_t j = 0; j < this->encodingTable.size(); j++){
            if(ch == this->encodingTable.at(j).second){
                sst << this->encodingTable.at(j).first;
                break;
            }
        }
    }

    return sst.str();
}