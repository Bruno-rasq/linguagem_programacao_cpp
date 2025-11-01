#pragma once

#include <string>
#include <vector>
#include <cstdint>
using namespace std;


namespace SpaceGrid {

    #define SPACE_WIDTH 49
    #define SPACE_HEIGHT 8

    typedef vector<string> SpaceOBJ;

    struct SpaceCoord {
        uint8_t x, y;
        SpaceCoord(uint8_t x, uint8_t y);
    };

    // exemplo visual do game
    const SpaceOBJ space = {
        " _______________________________________________",
        "|                                               |",
        "|                         X                     |",
        "|      X                                        |",
        "|                                               |",
        "|                   >     -         X           |",
        "|                                               |",
        "|                                               |",
        "|                                               |",
        "|_______________________________________________|", 
    };

    class Space {
        private:
            SpaceOBJ space;
        public:
            Space();

            void setCoord(const uint8_t x, const uint8_t y);
            void clearCoord(const uint8_t x, const uint8_t y);
            bool inBound(const uint8_t nx, const uint8_t ny);
            void wrap_around(const uint8_t nx, const uint8_t ny);
            string getFrameState() const ;
    };
}