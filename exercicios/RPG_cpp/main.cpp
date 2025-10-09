#include <vector>
#include <ctime>

#include "./players/player.hpp"
#include "./players/horse.hpp"
#include "./players/hero.hpp"
#include "./players/pawn.hpp"
#include "./players/mage.hpp"

using namespace std;

int main(){

    srand(time(0));

    vector<Player*> players;

    players.push_back(new Pawn("a1"));
    players.push_back(new Pawn("a2"));
    players.push_back(new Pawn("a3"));
    players.push_back(new Pawn("a4"));
    players.push_back(new Pawn("a5"));
    players.push_back(new Hero("Joao"));
    players.push_back(new Horse("Pe de pano"));
    players.push_back(new Horse("ventania"));
    players.push_back(new Mage("mestre dos magos"));

    size_t numOfLives = 1; //numero de vivos no final
    while(players.size() > numOfLives){

        //escolher aleatoriamente dois players para duelar.
        size_t id1 = rand()%players.size();
        size_t id2 = rand()%players.size();

        if(id1 == id2) continue; // impede que um player se ataque.

        cout << players.at(id1)->getName() << " will attack " << players.at(id2)->getName() << endl;

        players.at(id1)->AttackPlayer(players.at(id2));
        if(players.at(id2)->getLife() < 1){
            cout << "   -> " << players.at(id2)->getName() << " is dead." << endl;
            delete players.at(id2);
            players.erase(players.begin() + id2);
        }
    }

    cout << "winners: " << endl;
    for(size_t i = 0; i < players.size(); i++){
        cout << players.at(i)->getName() << " -> " << players.at(i)->getLife() << endl;
    }

    //limpando memoria dos sobreviventes
    for(size_t i = 0; i < players.size(); i++){
        delete players.at(i);
    }


    return 0;
}