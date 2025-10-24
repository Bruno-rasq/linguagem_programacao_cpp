#include "./includes/grid.hpp"
#include "./includes/keyboardcontroller.hpp"
#include "./includes/fruitcontroller.hpp"
#include "./includes/snack.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

#define GRIDWIDTH   45
#define GRIDHEIGHT  15
#define TIME        120

int main() {
    std::srand(std::time(nullptr));

    Grid grid(GRIDWIDTH, GRIDHEIGHT);
    Snack snack(grid);
    FruitController fc(snack, grid);

    while (true) {
        system("cls");

        uint16_t nextDirection = KeyboardController::pollKey();

        if (nextDirection == VK_ESCAPE) break;

        if (!KeyboardController::isOppositeDirection(nextDirection))
            KeyboardController::setCurrentDirection(nextDirection);

        bool grow = snack.hasEatenFruit(fc);
        snack.updatePosition(grid, nextDirection, grow);

        if (grow) fc.generateFruit(snack, grid);
        if (snack.hasSelfCollision()) break;

        grid.update_grid_state(snack, fc);
        grid.print_grid_state();

        Sleep(TIME);
    }

    return 0;
}
