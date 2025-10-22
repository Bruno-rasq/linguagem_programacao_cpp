#ifndef SNACKHPP
#define SNACKHPP

#include <deque>
#include <iostream>

#include "./structs.hpp"
#include "./grid.hpp" 

class Snack {
private:
    std::deque<SnackCell> snack;

public:

    Snack(Grid& grid);

    // TODO
    void update_position(const uint16_t direction, bool grow = false);

    bool check_snack_eats_fruit(const FruitController& fruit);

    bool check_self_snack_collision();

    std::deque<SnackCell> get_snack_body() const;

    Coord get_tail_snack() const;
    Coord get_head_snack() const; 

    // TODO
    void add_cell_on_snack(uint16_t x, uint16_t y, char cell);
};

#endif