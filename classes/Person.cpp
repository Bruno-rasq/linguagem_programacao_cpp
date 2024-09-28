#include "Person.hpp"

using namespace std;

void Person::setName(string& name){
    this->name = name;
}

void Person::setAdress(string& adress){
    this->adress = adress;
}

void Person::setJob(string& job){
    this->job = job ;
}

string Person::getName(){
    return this->name;
}

string Person::getAdress(){
    return this->adress;
}

string Person::getJob(){
    return this->job;
}