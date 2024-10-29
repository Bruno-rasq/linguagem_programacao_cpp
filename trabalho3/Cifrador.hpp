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

    public:

        Cifrador();
        Cifrador(const string txt, bool isdecoded);
        Cifrador(const string txt, bool isdecoded, int key);

        void setEncodingTable(int key);
        void setEncodedText(const string txt);
        void setDecodedText(const string txt);
        void setCharFrequences();
        void countCharFrequences();

        string getEncodedText() const;
        string getDecodedText() const;
        vector<pair<unsigned char, size_t>> getCharFrequences() const;

        string decode(const string txt = "") const;
        string encode(const string txt = "") const;

        //metodos auxiliares.
        string isDecodedTextEmpty() const;
};

#endif