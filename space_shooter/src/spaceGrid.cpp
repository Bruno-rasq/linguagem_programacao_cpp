#include "../includes/spaceGrid.hpp"

using namespace std;

namespace SpaceGrid {

    SpaceCoord::SpaceCoord(uint8_t x, uint8_t y): x(x), y(y){};


    bool inBounds(uint8_t& nx, uint8_t& ny){

        return (0 <= nx && nx < SPACE_HEIGHT &&
                0 <= ny && ny < SPACE_WIDTH);
    };


    void wrapAround(uint8_t& nx, uint8_t& ny){

        if(nx < 0)              nx = SPACE_HEIGHT - 1;
        if(nx >= SPACE_HEIGHT)  nx = 0;
        if(ny < 0)              ny = SPACE_WIDTH - 1;
        if(ny >= SPACE_WIDTH)   ny = 0;
    };


    void normalizeCoord(uint8_t& x, uint8_t& y) {

        if(!inBounds(x, y))
            wrapAround(x, y);
    }

    // -----------------------------------------------------------------------------------
    // implementacao da class Space
    // -----------------------------------------------------------------------------------

    Space::Space(){
        for(size_t i = 0; i < SPACE_HEIGHT; i++)
            this->space.push_back(string(SPACE_WIDTH, SPACEZONE));
    };


    void Space::setCoord(const uint8_t x, const uint8_t y, const char ob){
        this->space[x][y] = ob;
    };


    void Space::clearCoord(const uint8_t x, const uint8_t y){
        this->space[x][y] = SPACEZONE;
    };


    string Space::getFrameState() const {
        stringstream buff;

        buff << string(SPACE_WIDTH + 2, '_') << "\n";
        for(const string& line : this->space){
            buff <<  "|" << line << "|\n";
        }
        buff << "|" << string(SPACE_WIDTH, '_') << "|\n";

        return buff.str();
    };
}