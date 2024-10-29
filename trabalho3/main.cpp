#include "Cifrador.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main(){

    Cifrador c1, c2;

    c1.setDecodedText("texto aleatorio");
    c1.setEncodingTable(5);

    string encodeText = c1.encode();
    cout << "original: " << c1.getDecodedText() << endl;
    cout << "criptografado: " << encodeText << endl << endl;


    cout << "==============================" << endl;
    c2.setEncodedText(encodeText);
    c2.setEncodingTable(5);

    string decodedText = c2.decode();
    cout << "criptografado: " << c2.getEncodedText() << endl;
    cout << "original: " << decodedText << endl << endl;



    cout << "==============================" << endl;
    Cifrador c3("ana ama banana mas nao conta a hana", true, 5);
    cout << c3.getDecodedText() << endl;
    cout << c3.encode() << endl;

    c3.countCharFrequences();
    vector<pair<unsigned char, size_t>> frequences = c3.getCharFrequences(); 

    for(size_t i = 0; i < frequences.size(); i++){
        cout << (int) frequences.at(i).first << " -> "
        << (char) frequences.at(i).first << " -> "
        << frequences.at(i).second << endl; 
    }

    return 0;
}