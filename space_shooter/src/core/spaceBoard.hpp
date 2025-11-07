#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <windows.h>

using namespace std;

namespace SpaceBoardHandler {

    /*
        Definindo dimenções do board
    */
    #define WIDTH  70
    #define HEIGHT 30

    typedef vector<string> BoardFrame;

    struct Sprite {
        uint8_t x, y;
        char obj_ascii;
        Sprite();
        Sprite(uint8_t x, uint8_t y, const char obj);
    };

    struct  Coordinates {
        uint8_t x, y;

        Coordinates();
        Coordinates(uint8_t x, uint8_t y);

        bool inBounds(const uint8_t x, const uint8_t y);

        void wrapAround(uint8_t& x, uint8_t& y);

        void normalizeCoord(uint8_t x, uint8_t y);

        void MOV(const uint16_t& key);
    };
    
    class SpaceBoard {
        private:
            BoardFrame board;

        public:
            SpaceBoard();

            void draw(const uint8_t x, const uint8_t y, const char obj);
            void clear(const uint8_t x, const uint8_t y);
            BoardFrame getFrameBoard() const;
    };
}