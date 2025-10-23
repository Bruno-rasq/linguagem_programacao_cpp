#ifndef GRIDHPP
#define GRIDHPP

#include <iostream>
#include <vector>

#include "./snack.hpp"
#include "./fruit.hpp"

class Grid {
private:
    const char backgroundcell = '.';
    std::vector<std::vector<char>> grid;
    uint16_t GRIDWIDTH, GRIDHEIGHT;

public:
    Grid(uint16_t gridwidth, uint16_t gridheight);

    /**
     * Atualização visual do grid de forma incremental.
     * ao invés de redesenhar o grid a cada frame (complexidade O(NxM))
     * o metodo atualiza apenas as posicoes que mudaram:
     *  - limpa a posição antiga da cauda da serpente.
     *  - desenha a nova posição da cabeca da serpente.
     *  - desenha a posicao da fruta.
    */
    void update_grid_state(const Snack& snack, const FruitController& fruit);

    void print_grid_state();

    Coord get_random_coordinates();

    char get_grid_position(uint16_t x, uint16_t y);

    void set_grid_position(uint16_t x, uint16_t y, char cell);

    uint16_t get_grid_width() const;

    uint16_t get_grid_height() const;

    char get_cell() const;
};

#endif