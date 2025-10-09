#ifndef CAOS_HPP
#define CAOS_HPP

#include <string>

using namespace std;


//o caos vai servir como base parar todas as magias e feitiços derivados
//toda magia deverá ter um nome, um dano base e um custo
//custos podem ser de mana ou outros (exm: vida)
class Caos {

    protected:
        string spellName;
        int baseDamage, cost;

    public:
        ~Caos(){}
        Caos(){}
        Caos(string spell, int basedamage, int cost){
            this->spellName = spell;
            this->baseDamage = basedamage;
            this->cost = cost;
        }

        //metodo de invocacaos;
        virtual int castSpell() = 0;
};

#endif