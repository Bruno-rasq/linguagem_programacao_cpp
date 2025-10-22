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

    Grid grid = Grid(GRIDWIDTH, GRIDHEIGHT, '.');
    Snack snack = Snack(grid);
    FruitController fc = FruitController(snack, grid);
    KeyboardController kd = KeyboardController();

    while(true){
        system("cls");

        const uint16_t nextDirection = kd.poll_key();

        if (nextDirection == VK_ESCAPE) break;

        if(!kd.is_opposite_direction(nextDirection)){
            kd.set_current_direction(nextDirection);
        }

        // TODO: terminar de implementar...
    }
}