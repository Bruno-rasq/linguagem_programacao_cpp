#include "../includes/grid.hpp" 
#include "../includes/structs.hpp"
#include "../includes/snack.hpp"
#include "../includes/fruit.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>


Grid::Grid(uint16_t gridwidth, uint16_t gridheight, char backgroundcell)
{
    this->GRIDWIDTH = gridwidth;
    this->GRIDHEIGHT = gridheight;
    
    for(size_t i = 0; i < this->GRIDHEIGHT; i++){
        std::vector<char> row;
        for(size_t j = 0; j < this->GRIDWIDTH; j++)
            row.push_back(backgroundcell);
        this->grid.push_back(row);
    }
};


Coord Grid::get_random_coordinates(){
    const uint16_t x = std::rand() % this->GRIDHEIGHT;
    const uint16_t y = std::rand() % this->GRIDWIDTH;
    return {x, y};
};


char Grid::get_grid_position(uint16_t x, uint16_t y){
    return this->grid[x][y];
};


void Grid::print_grid_state(){
    std::ostringstream buffer;
    buffer << "\n\t";
    for (size_t i = 0; i < this->GRIDWIDTH; i++) buffer << "_";
    buffer << "\n";

    for (size_t i = 0; i < this->GRIDHEIGHT; i++) {
        buffer << "\t|";
        for (size_t j = 0; j < this->GRIDWIDTH; j++)
            buffer << this->get_grid_position(i, j);
        buffer << "|\n";
    }

    buffer << "\t|";
    for (size_t i = 0; i < this->GRIDWIDTH; i++) buffer << "_";
    buffer << "|\n";

    std::cout << buffer.str();
};


void Grid::update_grid_state(const Snack& snack, const FruitController& fruit){

    const Coord tail_snack = snack.get_tail_snack();
    const Coord head_snack = snack.get_head_snack();
    const Coord fruit_coor = fruit.get_fruit_position();

    this->set_grid_position(tail_snack.x, tail_snack.y, '.');
    this->set_grid_position(head_snack.x, head_snack.y, '@');
    this->set_grid_position(fruit_coor.x, fruit_coor.y, 'O');
    
};

uint16_t Grid::get_grid_width() const {
    return this->GRIDWIDTH;
};

uint16_t Grid::get_grid_height() const {
    return this->GRIDHEIGHT;
};