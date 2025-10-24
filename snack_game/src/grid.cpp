#include "../includes/grid.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>

Grid::Grid(uint16_t gridwidth, uint16_t gridheight)
    : GRIDWIDTH(gridwidth), GRIDHEIGHT(gridheight) {
    grid.resize(GRIDHEIGHT, std::vector<char>(GRIDWIDTH, '.'));
}

Coord Grid::get_random_coordinates() const {
    return { std::rand() % GRIDHEIGHT, std::rand() % GRIDWIDTH };
}

char Grid::get_grid_position(uint16_t x, uint16_t y) const {
    return grid[x][y];
}

void Grid::set_grid_position(uint16_t x, uint16_t y, char cell) {
    grid[x][y] = cell;
}

void Grid::print_grid_state() const {
    std::ostringstream buffer;
    buffer << "\n\t";
    for (size_t i = 0; i < GRIDWIDTH; i++) buffer << "_";
    buffer << "\n";

    for (size_t i = 0; i < GRIDHEIGHT; i++) {
        buffer << "\t|";
        for (size_t j = 0; j < GRIDWIDTH; j++)
            buffer << get_grid_position(i, j);
        buffer << "|\n";
    }

    buffer << "\t|";
    for (size_t i = 0; i < GRIDWIDTH; i++) buffer << "_";
    buffer << "|\n";

    std::cout << buffer.str();
}

void Grid::update_grid_state(const Snack& snack, const FruitController& fruit) {
    const Coord tail_snack = snack.getTail();
    const Coord head_snack = snack.getHead();
    const Coord fruit_coor = fruit.getFruitPosition();

    set_grid_position(tail_snack.x, tail_snack.y, '.');
    set_grid_position(head_snack.x, head_snack.y, '@');
    set_grid_position(fruit_coor.x, fruit_coor.y, 'O');
}

uint16_t Grid::get_grid_width() const { return GRIDWIDTH; }
uint16_t Grid::get_grid_height() const { return GRIDHEIGHT; }
//char Grid::get_background_cell() const { return BACKGROUND_CELL; }
