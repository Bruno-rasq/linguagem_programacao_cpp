#ifndef PAWN_HPP
#define PAWN_HPP

#include "./player.hpp"

using namespace std;

class Pawn: public Player {
    protected:
    public:
        Pawn(string name){
            this->name = "pawn " + name;
            this->life = 100;
            this->damage = 15;
        };

        Pawn(string n, int l, int d): Player("Pawn" + n, l, d){};
        ~Pawn(){};

        void AttackPlayer(Player* enemy){
            enemy->BeingAttacked(this->damage);
        };
};

#endif