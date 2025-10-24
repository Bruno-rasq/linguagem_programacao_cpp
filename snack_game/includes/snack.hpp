#pragma once
#include <deque>
#include "../includes/structs.hpp"

// Forward declarations
class Grid;
class FruitController;

class Snack {
private:
    static const char CELL = '@';
    std::deque<SnackCell> snack;

public:
    Snack(Grid& grid);

    // Atualiza posição do snack
    void updatePosition(const Grid& gd, uint16_t direction, bool grow = false);

    // Verifica se a serpente comeu a fruta
    bool hasEatenFruit(const FruitController& fruit) const;

    // Verifica colisão da serpente consigo mesma
    bool hasSelfCollision() const;

    // Retorna corpo da serpente
    const std::deque<SnackCell>& getSnackBody() const;

    Coord getTail() const;
    Coord getHead() const;

    char getSnackCell() const;
};
