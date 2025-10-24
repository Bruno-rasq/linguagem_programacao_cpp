#pragma once
#include <cstdint>

struct Coord {
    int32_t x, y;
};

struct SnackCell {
    int32_t x, y;
    char cell;

    SnackCell() : x(0), y(0), cell(' ') {}
    SnackCell(char c, int32_t x, int32_t y) : x(x), y(y), cell(c) {}
};
