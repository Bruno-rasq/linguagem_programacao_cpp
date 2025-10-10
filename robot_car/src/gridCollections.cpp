#include <vector>
#include <map>
#include <random>
#include <utility>

namespace GridCollections {
    
    using Board = std::vector<std::vector<int>>;

    const std::vector<Board> BOARDS = {

        // example board 7 x 8
        {
            {1, 1, 0, 0, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 0, 1, 1},
            {1, 1, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 1, 1},
            {1, 1, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 1, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 1, 0, 0},
        },

        // example board 7 x 8
        {
            {1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 1, 1, 1, 0},
            {1, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 0, 1, 0},
            {1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 1, 0},
            {1, 1, 1, 1, 1, 1, 1, 0},
        } 
    };

    /**
     * 0 - celula de obstaculo
     * 1 - celula de livre acesso
     * 2 - posicao do robo
     * 3 - posicao passada do robot (nao acessivel)
    */
    const std::map<int, char> cells = {
        {0, '#'}, {1, '.'}, {2, 'X'}, {3, '.'}
    };

    const Board& getRandomGrid() {

        static std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<size_t> dist(0, BOARDS.size() - 1);

        return BOARDS[dist(rng)];
    };
}