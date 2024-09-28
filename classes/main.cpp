#include <iostream>
#include <vector>
#include "Person.hpp"

using namespace std;

int main(){

    vector<Person> people;

    Person p1, p2, p3, p4;

    // Adiciona objetos ao vetor
    people.push_back(p1);
    people.push_back(p2);
    people.push_back(p3);
    people.push_back(p4);

    // Define nomes para cada pessoa
    for (int i = 0; i < people.size(); i++) {
        string nome, adre, job;
        nome = "nome " + to_string(i + 1);
        adre = "rua 0" + to_string(i + 1);
        job = "programador";
        
        people[i].setName(nome);
        people[i].setAdress(adre);
        people[i].setJob(job);
    }

    // Exibe os nomes das people
    for (Person& pe : people) {
        cout << pe.getName() << endl;
        cout << pe.getAdress() << endl;
        cout << pe.getJob() << endl << endl;
    }

    return 0;

}