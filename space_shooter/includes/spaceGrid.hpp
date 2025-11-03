#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
using namespace std;

namespace SpaceGrid {

    #define SPACE_WIDTH 70          // zone acessivel (excluindo bordas.)
    #define SPACE_HEIGHT 20
    #define SPACEZONE ' '


    struct SpaceCoord {
        uint8_t x, y;
        SpaceCoord(uint8_t x, uint8_t y);
    };

    // verifica se a coordenada atual está dentro dos limites do grid.
    bool inBounds(uint8_t& x, uint8_t& y);

    // curva a coordenada atual para que o player nunca colida com bordas ou saida do grid.
    void WrapAround(uint8_t& x, uint8_t& y);

    // junta os metodos inBounds e wrapAround
    void normalizeCoord(uint8_t& x, uint8_t& y);


    class Space {
        private:
            vector<string> space;

        public:
            Space();

            void setCoord(const uint8_t x, const uint8_t y, const char ob);
            void clearCoord(const uint8_t x, const uint8_t y);
            string getFrameState() const;
    };
}