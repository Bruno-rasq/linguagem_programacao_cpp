#pragma once
#include <vector>
#include "./snack.hpp"
#include "./fruitcontroller.hpp"
#include "./structs.hpp"

class Grid {
private:
    //static constexpr char BACKGROUND_CELL = '.';
    std::vector<std::vector<char>> grid;
    uint16_t GRIDWIDTH, GRIDHEIGHT;

public:
    Grid(uint16_t gridwidth, uint16_t gridheight);

    void updateGridState(const Snack& snack, const FruitController& fruit);

    void printGridState() const;

    Coord getRandomCoordinates() const;

    char getGridPosition(uint16_t x, uint16_t y) const;
    void setGridPosition(uint16_t x, uint16_t y, char cell);

    uint16_t getGridWidth() const;
    uint16_t getGridHeight() const;
};
