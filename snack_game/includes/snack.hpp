#ifndef SNACKHPP
#define SNACKHPP

#include <deque>
#include <iostream>

#include "./structs.hpp"
#include "./grid.hpp" 

class Snack {
private:
    const char cell = '@';
    std::deque<SnackCell> snack;

public:

    Snack(Grid& grid);

    // TODO
    void update_position(const Grid& gd, const uint16_t direction, bool grow = false);

    bool check_snack_eats_fruit(const FruitController& fruit);

    bool check_self_snack_collision();

    std::deque<SnackCell> get_snack_body() const;

    Coord get_tail_snack() const;
    Coord get_head_snack() const; 

    char get_snack_cell() const;
};

#endif