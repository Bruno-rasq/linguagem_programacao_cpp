#ifndef HERO_HPP
#define HERO_HPP

#include "./player.hpp"

using namespace std;


class Hero: public Player {
    protected:
    public:
        Hero(string name){
            this->name = "Hero " + name;
            this->life = 250;
            this->damage = 55;
        };

        Hero(string n, int l, int d): Player("Hero" + n, l, d){};
        ~Hero(){};

        void AttackPlayer(Player* enemy){
            enemy->BeingAttacked(this->damage);
        };
};

#endif