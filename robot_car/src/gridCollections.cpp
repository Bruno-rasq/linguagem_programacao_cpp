#include <vector>
#include <map>
#include <random>
#include <utility>
#include <fstream>

#include "../include/gridCollections.hpp"

namespace GridCollections {
    
    std::vector<Board> BOARDS;

    const std::map<int, char> cells = {
        {0, '#'}, // - celula de obstaculo
        {1, '.'}, // - celula de livre acesso
        {2, 'X'}, // - posicao do robo
        {3, '.'}  // - posicao passada do robot (nao acessivel)
    };

    const Board& getRandomGrid() {

        static std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<size_t> dist(0, 100);

        return BOARDS[dist(rng) % BOARDS.size()];
    };

    bool loadFileText(const std::string& PATH) {
        std::ifstream file(PATH);
        if(!file.is_open()) return false;

        int rows, cols;
        while(file >> rows >> cols) {
            std::vector<std::vector<int>> board(rows, std::vector<int>(cols));
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(!(file >> board[i][j])) return false;
                }
            }
            BOARDS.push_back(board);
        }
        file.close();
        return true;
    }

}