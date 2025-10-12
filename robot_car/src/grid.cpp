#include "../include/grid.hpp"
#include "../include/gridCollections.hpp"
#include <vector>
#include <iostream>


Grid::Grid(){
    this->board = GridCollections::getRandomGrid();
}

void Grid::printGridState(){

    for(size_t i = 0; i < this->board.size(); i++){
        
        for(size_t j = 0; j < this->board[0].size(); j++)
            std::cout << GridCollections::cells.at(this->board[i][j]);
        
        std::cout << "\n";
    }
};

void Grid::setRobotCoord(int x, int y){
    this->board[x][y] = 2;
};

void Grid::clearPrevRobotCoord(int x, int y){
    this->board[x][y] = 3;
};

GridCollections::Board Grid::getGridState() const {
    return this->board;
};