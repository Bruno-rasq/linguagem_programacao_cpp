#include "../includes/snack.hpp"
#include "../includes/fruit.hpp"
#include "../includes/grid.hpp"
#include "../includes/structs.hpp"

#include <iostream>
#include <cstdlib>
#include <windows.h>

Snack::Snack(Grid& grid){

    uint16_t x = grid.get_grid_height() / 2;
    uint16_t y = grid.get_grid_width() / 2;

    this->snack.push_back({'@', x, y});
}

bool Snack::check_snack_eats_fruit(const FruitController& fruit) {

    const Coord fruit_coord = fruit.get_fruit_position();
    return (snack.back().x == fruit_coord.x && snack.back().y == fruit_coord.y);
}

bool Snack::check_self_snack_collision(){
    const std::deque<SnackCell> snack_body = this->get_snack_body();
    const SnackCell snack_head = snack_body.back();

    if(snack_body.size() < 2) return false;

    for(size_t i = 0; i < snack_body.size() - 1; i++)
        if(snack_body[i].x == snack_head.x && snack_body[i].y == snack_head.y)
            return true;

    return false;
}

std::deque<SnackCell> Snack::get_snack_body() const {
    return this->snack;
}

Coord Snack::get_tail_snack() const {
    SnackCell tail = this->snack.front();
    return {tail.x, tail.y};
}

Coord Snack::get_head_snack() const {
    SnackCell head = this->snack.back();
    return {head.x, head.y};
}

char Snack::get_snack_cell() const {
    return this->cell;
}

void Snack::update_position(const Grid& gd, const uint16_t direction, bool grow = false){

    int16_t x = snack.back().x;
    int16_t y = snack.back().y;

    if (direction == VK_UP)    x--;
    if (direction == VK_DOWN)  x++;
    if (direction == VK_RIGHT) y++;
    if (direction == VK_LEFT)  y--;

    // wrap-around nas bordas
    if (x < 0) x = gd.get_grid_height() - 1;
    if (x >= gd.get_grid_height()) x = 0;
    if (y < 0) y = gd.get_grid_width() - 1;
    if (y >= gd.get_grid_width() ) y = 0;

    if (!grow) this->snack.pop_front();

    this->snack.push_back({x, y, this->cell});
}