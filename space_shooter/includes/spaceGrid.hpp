#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
using namespace std;

namespace SpaceGrid {

    #define SPACE_WIDTH 55          // zone acessivel (excluindo bordas.)
    #define SPACE_HEIGHT 11
    #define SPACEZONE ' '

    typedef vector<string> SpaceOBJ;

    struct SpaceCoord {
        uint8_t x, y;
        SpaceCoord(uint8_t x, uint8_t y);
    };

    class Space {
        private:
            static const SpaceOBJ spaceDefault;
            SpaceOBJ space;

        public:
            Space();

            void setCoord(const uint8_t x, const uint8_t y, const char ob);
            void clearCoord(const uint8_t x, const uint8_t y);
            bool inBound(const uint8_t nx, const uint8_t ny);
            void wrap_around(const uint8_t nx, const uint8_t ny);
            string getFrameState() const;
    };
}