#ifndef MAGE_HPP
#define MAGE_HPP

#include "./player.hpp"

using namespace std;

class Mage: public Player {

    protected:

    public:
        Mage(string name){
            this->name = name;
            this->life = 100;
            this->damage = 75;
        }

        Mage(string n, int l, int d): Player("Mage" + n, l, d){}

        void AttackPlayer(Player* enemy){
            enemy->BeingAttacked(this->damage);
        }
};


#endif