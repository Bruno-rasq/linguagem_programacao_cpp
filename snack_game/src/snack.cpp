#include "../includes/snack.hpp"
#include "../includes/fruit.hpp"


Snack::Snack(Grid& grid){
    const int32_t x = grid.get_grid_height() / 2;
    const int32_t y = grid.get_grid_width() / 2;

    this->add_cell_on_snack(x, y, '@');
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
    return this->snack.front();
}

Coord Snack::get_head_snack() const {
    return this->snack.back();
}