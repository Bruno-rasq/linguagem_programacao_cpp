#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>

using namespace std;

namespace SpaceBoardHandler {

    #define WIDTH  70
    #define HEIGHT 25

    struct  Coordination
    {
        uint8_t x, y;

        Coordination();
        Coordination(uint8_t x, uint8_t y);

        bool inBounds(const uint8_t x, const uint8_t y);

        void wrapAround(uint8_t& x, uint8_t& y);

        void normalizeCoord(uint8_t x, uint8_t y);

        void MOV(const uint16_t& key);
    };
    
    class SpaceBoard 
    {
        private:
            vector<string> board;

        public:
            SpaceBoard();

            void draw(const uint8_t x, const uint8_t y, const char obj);
            void clear(const uint8_t x, const uint8_t y);
            void render() const;
    };
}