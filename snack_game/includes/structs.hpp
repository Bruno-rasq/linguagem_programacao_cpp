#include <iostream>

struct Coord {
    int32_t x, y;
};

struct SnackCell {
    int32_t x, y;
    char cell;

    SnackCell(char c, int32_t x, int32_t y): x(x), y(y), cell(c){}
};