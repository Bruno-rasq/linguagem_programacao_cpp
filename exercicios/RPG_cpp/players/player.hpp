#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using namespace std;

class Player {
    protected:
        string name;
        int life, damage;

    public:
        
        Player(){};
        Player(string name, int life, int damage): name(name), life(life), damage(damage){};

        string getName() const { return this->name; };
        int getLife() const { return this->life; };
        int geDamage() const { return this->damage; };

        virtual void AttackPlayer(Player* p) = 0;
        void BeingAttacked(int damage){
            this->life -= damage;
        };
};

#endif