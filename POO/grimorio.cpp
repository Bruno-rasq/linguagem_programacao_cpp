#include <vector>
#include <iostream>
#include <tuple>
#include <ctime>
#include <string>

using namespace std;

class Caos {

    protected:
        string spell_name;
        int power, base_power = 100;

    public:
        Caos(const string& name, int power){
            this->spell_name = name;
            this->power = power + this->base_power;
        };

        virtual ~Caos() = default; //destrutor padrao
        virtual void cast_spell() const = 0;

};

class Spell: public Caos {
    public:
        Spell(const string& name, int power): Caos(name, power){};

        void cast_spell() const override {
            cout << this->spell_name << "!!" << endl;
        };

        int get_damage() const {
            return this->power;
        };
};

class Grimorio {
    private:
        vector<Spell> spells;
        string book_name;

    public:
        Grimorio(const string& name): book_name(name){};
        ~Grimorio(){};

        void add_spell(const Spell& spell){
            this->spells.push_back(spell);
        }

        void cast() const {
            if(this->spells.empty()){
                cout << "No spells to cast!" << endl;
                return;
            }

            int id = rand() % this->spells.size();
            this->spells[id].cast_spell();
            cout << "damage: " << to_string(this->spells[id].get_damage()) << endl;
        }
};

int main() {

    srand(time(nullptr));

    Grimorio spellBook("Grimorio do Dragao");

    vector<tuple<string, int>> spells = {
        {"Fogo divino",       20},
        {"Chama ardente",     50},
        {"Tempestade gelida", 40},
        {"raio Divino",       96},
        {"Sombra corrosiva",  60},
        {"Explosao arcana",   60},
        {"Cura rapida",       80},
        {"Escudo mistico",    25},
        {"Erupcao toxica",    45},
        {"Invocacao celest",  90},
    };

    for(const auto& spell: spells){
        spellBook.add_spell(
            Spell(
                get<0>(spell),
                get<1>(spell)
            )
        );
    }

    for(int i = 0; i < 5; i++){
        spellBook.cast();
    }

    return 0;
}