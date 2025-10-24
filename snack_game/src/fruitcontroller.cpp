#include "../includes/fruitcontroller.hpp"
#include "../includes/structs.hpp"
#include "../includes/grid.hpp"
#include "../includes/snack.hpp"

#include <deque>

FruitController::FruitController(Snack& snack, Grid& grid) {
    currentFruitPosition = generateFruit(snack, grid);
}

Coord FruitController::getFruitPosition() const {
    return currentFruitPosition;
}

Coord FruitController::generateFruit(Snack& snack, Grid& grid) {
    while (true) {
        Coord fruit = grid.getRandomCoordinates();
        if (!isOnSnack(snack, fruit)){
            currentFruitPosition = fruit;
            return fruit;
        }
    }
}

bool FruitController::isOnSnack(const Snack& snack, const Coord& fruit) const {
    const std::deque<SnackCell> snackBody = snack.getSnackBody();
    for (const auto& cs : snackBody)
        if (cs.x == fruit.x && cs.y == fruit.y)
            return true;
    return false;
}

char FruitController::getCell() const {
    return FRUIT_CELL;
}
