#include "../includes/snack.hpp"
#include "../includes/grid.hpp"
#include "../includes/fruitcontroller.hpp"
#include <windows.h>

Snack::Snack(Grid& grid) {
    uint16_t x = grid.get_grid_height() / 2;
    uint16_t y = grid.get_grid_width() / 2;

    snack.push_back({CELL, x, y});
    //teste
    snack.push_back({CELL, x - 1, y});
    snack.push_back({CELL, x - 2, y});
}

bool Snack::hasEatenFruit(const FruitController& fruit) const {
    const Coord fruitCoord = fruit.getFruitPosition();
    const SnackCell& head = snack.back();
    return (head.x == fruitCoord.x && head.y == fruitCoord.y);
}

bool Snack::hasSelfCollision() const {
    if (snack.size() < 2) return false;

    const SnackCell& head = snack.back();
    for (size_t i = 0; i < snack.size() - 1; ++i)
        if (snack[i].x == head.x && snack[i].y == head.y)
            return true;

    return false;
}

const std::deque<SnackCell>& Snack::getSnackBody() const {
    return snack;
}

Coord Snack::getTail() const {
    const SnackCell& tail = snack.front();
    return {tail.x, tail.y};
}

Coord Snack::getHead() const {
    const SnackCell& head = snack.back();
    return {head.x, head.y};
}

char Snack::getSnackCell() const {
    return CELL;
}

void Snack::updatePosition(const Grid& gd, uint16_t direction, bool grow) {
    int16_t x = snack.back().x;
    int16_t y = snack.back().y;

    if (direction == VK_UP)         x--;
    else if (direction == VK_DOWN)  x++;
    else if (direction == VK_RIGHT) y++;
    else if (direction == VK_LEFT)  y--;

    // wrap-around nas bordas
    if (x < 0) x = gd.get_grid_height() - 1;
    if (x >= gd.get_grid_height()) x = 0;
    if (y < 0) y = gd.get_grid_width() - 1;
    if (y >= gd.get_grid_width()) y = 0;

    if (!grow) snack.pop_front();

    snack.push_back({CELL, x, y});
}
