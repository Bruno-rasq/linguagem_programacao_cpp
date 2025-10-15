#ifndef GRIDCOLLECTIONS_HPP
#define GRIDCOLLECTIONS_HPP

#include <vector>
#include <map>
#include <string>

namespace GridCollections {

    // define o tipo do grid
    using Board = std::vector<std::vector<int>>;

    // mapa de representaççao vidual das celulas
    extern const std::map<int, char> cells;

    // lista de boards pré-definido
    extern std::vector<Board> BOARDS;

    // retorna uma referencia para um board aleatorio.
    const Board& getRandomGrid();

    // alimenta o vetor de boards
    bool loadFileText(const std::string& PATH);
}

#endif