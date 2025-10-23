#include "./includes/grid.hpp"
#include "./includes/keyboardController.hpp"
#include "./includes/fruit.hpp"
#include "./includes/snack.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define GRIDWIDTH   45
#define GRIDHEIGHT  15
#define TIME        120

int main(){

    std::srand(std::time(nullptr));

    KeyboardController kd = KeyboardController();
    Grid grid = Grid(GRIDWIDTH, GRIDHEIGHT);
    Snack snack = Snack(grid);
    FruitController fc = FruitController(snack, grid);

    while(true){
        system("cls");

        const uint16_t nextDirection = kd.poll_key();

        if (nextDirection == VK_ESCAPE) break;

        if(!kd.is_opposite_direction(nextDirection))
            kd.set_current_direction(nextDirection);

        bool grow = snack.check_snack_eats_fruit(fc);
        snack.update_position(grid, nextDirection, grow);

        if(grow) fc.generate_fruit_on_grid(snack, grid);
        if(snack.check_self_snack_collision()) break;

        grid.update_grid_state(snack, fc);
        grid.print_grid_state();

        Sleep(TIME);
    }

    return 0;
}