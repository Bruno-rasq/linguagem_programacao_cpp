#include <vector>
#include <utility>
#include <string>
#include <sstream>

#include "Cifrador.hpp"

using namespace std;

//verificar se o que estamos utilizando é o texte original ou criptografado.
string Cifrador::isDecodedTextEmpty() const {
    if(this->decodedtext.empty()){
        return this->encodedtext;
    }
    return this->decodedtext;
}


//construtor padrao, inicializa ambas as propriedades como ""
Cifrador::Cifrador(): encodedtext(""), decodedtext(""){};

//recebe uma string e um boolean indicando se a string já está criptografada ou nao.
Cifrador::Cifrador(const string txt, bool isdecoded){
    if(isdecoded){
        this->decodedtext = txt;
        this->encodedtext = "";
    } else {
        this->decodedtext = "";
        this->encodedtext = txt;
    }
};

//recebe um valor key referente ao desvio que o encondingTable vai sofrer, alem do balanceamento de carga
Cifrador::Cifrador(const string txt, bool isdecoded, int key): Cifrador(txt, isdecoded){
    Cifrador::setEncodingTable(key);
};


//criar pares de unsigned chars,  caracter original e o caracter com desvio de posicao.
void Cifrador::setEncodingTable(int key){
    for(size_t i = 0; i < 256; i++){

        unsigned char ch = static_cast<unsigned char>(i); 
        unsigned char encodedCh = static_cast<unsigned char>((i + key) % 256); 

        pair<unsigned char, unsigned char> p(ch, encodedCh);
        this->encodingTable.push_back(p);
    }
};

//setters para encodedtext e decodedtext
void Cifrador::setEncodedText(const string txt){
    this->encodedtext = txt;
};

void Cifrador::setDecodedText(const string txt){
    this->decodedtext = txt;
};

//inicia o vetor de frequencia com todos os contadores zerados.
void Cifrador::setCharFrequences(){
    for(size_t i = 0; i < 256; i++){
        pair<unsigned char, size_t> p (i, 0);
        this->charFrequences.push_back(p);
    }
};

//calcula a frequencia de cada caracter da string
void Cifrador::countCharFrequences(){
    string text = Cifrador::isDecodedTextEmpty();
    for(size_t i = 0; i < text.size(); i++){
        char ch = text.at(i);                           
        charFrequences.at(ch).second++;
    }
}


//getters para encodedtext e decodedtext
string Cifrador::getDecodedText() const {
    return this->decodedtext;
};

string Cifrador::getEncodedText() const {
    return this->encodedtext;
};

vector<pair<unsigned char, size_t>> Cifrador::getCharFrequences() const {
    return this->charFrequences;
}


string Cifrador::encode(const string txt = "") const {
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

string Cifrador::decode(const string txt = "") const {
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