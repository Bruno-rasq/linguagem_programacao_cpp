#include "../includes/fruit.hpp"
#include "../includes/structs.hpp"

#include <deque>

FruitController::FruitController(Snack& snack, Grid& grid){
    this->current_fruit_position = this->generate_fruit_on_grid(snack, grid);
}

Coord FruitController::get_fruit_position() const {
    return this->current_fruit_position;
}

Coord FruitController::generate_fruit_on_grid(Snack& snack, Grid& grid) {
    while (true) {
        Coord fruit = grid.get_random_coordinates();
        if (!this->check_fruit_span_on_snack_position(snack, fruit))
            return fruit;
    }
}

bool FruitController::check_fruit_span_on_snack_position(Snack& snack, Coord& fruit){

    const std::deque<SnackCell> snack_body = snack.get_snack_body();
    for (const auto& cs : snack_body)
        if (cs.x == fruit.x && cs.y == fruit.y)
            return true;
    return false;

}

char FruitController::get_cell() const {
    return this->FruitCell;
}