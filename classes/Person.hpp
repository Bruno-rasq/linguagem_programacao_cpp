#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

    /**
     *  Arquivos .hpp ou header files contem as definições de classes, funções, constantes 
     *  e outras declarações que deveram ser implementadas no arquivo de mesmo nome .cpp
     * 
    */

    class Person {

        private:
            string name, adress, job;

        public:

            void setName(string& name);
            void setAdress(string& adress);
            void setJob(string& job);

            string getName();
            string getAdress();
            string getJob();
    };

#endif