#include "../includes/spaceGrid.hpp"

using namespace std;

namespace SpaceGrid {

    SpaceCoord::SpaceCoord(uint8_t x, uint8_t y): x(x), y(y){};

    // template padrão do board do game.
    const SpaceOBJ Space::spaceDefault = {
        " _______________________________________________________",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|                                                       |",
        "|_______________________________________________________|",
    };

    // implementando classe Space:
    Space::Space(): space(spaceDefault){};

    void Space::setCoord(const uint8_t x, const uint8_t y, const char ob){
        if(this->inBound(x, y))
            this->space[x][y] = ob;
    };

    void Space::clearCoord(const uint8_t x, const uint8_t y){
        this->space[x][y] = SPACEZONE;
    };

   
    bool Space::inBound(const uint8_t nx, const uint8_t ny){
        // como não pode passar da borda então nx e ny não podem ser zero.
        return (0 < nx && 
                0 < ny &&
                nx < SPACE_WIDTH &&
                ny < SPACE_HEIGHT);
    };

    void Space::wrap_around(const uint8_t nx, const uint8_t ny){};

    string Space::getFrameState() const {
        stringstream buff;
        for(const string& line : this->space){
            buff << line << "\n";
        }

        return buff.str();
    };
}