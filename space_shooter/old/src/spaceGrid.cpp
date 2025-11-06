#include "../includes/spaceGrid.hpp"

using namespace std;

namespace SpaceGrid {


    // ---------------------------------------------------------------------------
    // implementacao da estrutura space coord
    // ---------------------------------------------------------------------------

    SpaceCoord::SpaceCoord(int8_t x, int8_t y): x(x), y(y){};


    bool SpaceCoord::inBounds(const int8_t nx, const int8_t ny){

        return (0 <= nx && nx < SPACE_HEIGHT && 0 <= ny && ny < SPACE_WIDTH);
    };


    void SpaceCoord::wrapAround(int8_t& nx, int8_t& ny){

        if(nx < 0)              nx = SPACE_HEIGHT - 1;
        if(nx >= SPACE_HEIGHT)  nx = 0;
        if(ny < 0)              ny = SPACE_WIDTH - 1;
        if(ny >= SPACE_WIDTH)   ny = 0;
    };


    void SpaceCoord::normalizeCoord(int8_t x, int8_t y) {

        if (!this->inBounds(x, y)) this->wrapAround(x, y);

        this->x = x;
        this->y = y;
    };

    void SpaceCoord::MOVE(const uint16_t& key) {

        if(key == VK_UP)    { this->normalizeCoord((this->x - 1), this->y); }
        if(key == VK_DOWN)  { this->normalizeCoord((this->x + 1), this->y); }
        if(key == VK_LEFT)  { this->normalizeCoord(this->x, (this->y - 1)); }
        if(key == VK_RIGHT) { this->normalizeCoord(this->x, (this->y + 1)); }
    };

    // ---------------------------------------------------------------------------
    // implementacao da class Space
    // ---------------------------------------------------------------------------

    Space::Space(){
        for(size_t i = 0; i < SPACE_HEIGHT; i++)
            this->space.push_back(string(SPACE_WIDTH, SPACEZONE));
    };


    void Space::setCoord(const int8_t x, const int8_t y, const char ob){
        this->space[x][y] = ob;
    };


    void Space::clearCoord(const int8_t x, const int8_t y){
        this->space[x][y] = SPACEZONE;
    };


    string Space::getFrameState() const {
        stringstream buff;

        buff << string(SPACE_WIDTH + 2, '_') << "\n";

        for(const string& line : this->space)
            buff <<  "|" << line << "|\n";
        
        buff << "|" << string(SPACE_WIDTH, '_') << "|\n";

        return buff.str();
    };
}