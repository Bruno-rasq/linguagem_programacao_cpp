#pragma once
#include "../includes/structs.hpp"

// Forward declarations
class Snack;
class Grid;

class FruitController {
private:
    static const char FRUIT_CELL = 'O';
    Coord currentFruitPosition;

public:
    FruitController(Snack& snack, Grid& grid);

    // Verifica se a fruta está sobre a serpente
    bool isOnSnack(const Snack& snack, const Coord& fruit) const;

    // Gera uma fruta nova no grid, evitando colisão com a serpente
    Coord generateFruit(Snack& snack, Grid& grid);

    Coord getFruitPosition() const;
    char getCell() const;
};
