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

    // Atualiza visualmente o grid incrementando apenas posições alteradas
    void update_grid_state(const Snack& snack, const FruitController& fruit);

    // Imprime o estado atual do grid no console
    void print_grid_state() const;

    Coord get_random_coordinates() const;

    char get_grid_position(uint16_t x, uint16_t y) const;
    void set_grid_position(uint16_t x, uint16_t y, char cell);

    uint16_t get_grid_width() const;
    uint16_t get_grid_height() const;
    //char get_background_cell() const;
};
