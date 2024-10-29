#ifndef CIFRADOR_HPP
#define CIFRADOR_HPP

#include <vector>
#include <utility>
#include <string>

using namespace std;

class Cifrador {

    private:

        string encodedtext, decodedtext;
        vector<pair<unsigned char, unsigned char>> encodingTable;
        vector<pair<unsigned char, size_t>> charFrequences;

        void setCharFrequences();
        
    public:

        Cifrador();
        Cifrador(const string txt, bool isdecoded);
        Cifrador(const string txt, bool isdecoded, int key);

        void setEncodingTable(int key);
        void setEncodedText(const string txt);
        void setDecodedText(const string txt);
        void countCharFrequences();

        string getEncodedText() const;
        string getDecodedText() const;
        vector<pair<unsigned char, size_t>> getCharFrequences();

        string decode(const string txt = "");
        string encode(const string txt = "");

        //metodos auxiliares.
        string isDecodedTextEmpty() const;
};

#endif