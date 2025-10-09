#ifndef HORSE_HPP
#define HORSE_HPP

#include "./player.hpp"
#include <iostream>

using namespace std;

class Horse: public Player {
    protected:
        int criticalHit(){
            int probability = rand()%5;
            int ch = 1;

            //20% de chance de selecionar 0
            if(probability == 0){
                cout << "FALAITY HORSE" << endl;
                ch = 10;
            }
            return ch;
        };

    public:
        Horse(string name){
            this->name = "Horse " + name;
            this->life = 300;
            this->damage = 45;
        };

        Horse(string n, int l, int d): Player("Horse" + n, l, d){};
        ~Horse(){};

        void AttackPlayer(Player* enemy){
            int ch = this->criticalHit();
            enemy->BeingAttacked(this->damage * ch);
        };
};

#endif