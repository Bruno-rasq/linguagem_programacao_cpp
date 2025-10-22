#ifndef FRUITHPP
#define FRUITHPP

#include "./snack.hpp"
#include "./grid.hpp"

class FruitController {
    private:
        Coord current_fruit_position;

    public:
        FruitController(Snack& snack, Grid& grid);

        bool check_fruit_span_on_snack_position(Snack& snack, Coord& fruit);

        Coord generate_fruit_on_grid(Snack& snack, Grid& grid);

        Coord get_fruit_position() const;
};

#endif