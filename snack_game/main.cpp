#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

#define GRIDWIDTH 45
#define GRIDHEIGHT 15
#define SNACKCELL '#'
#define FRUITCELL 'O'

struct Coord {
    int8_t x, y;
    char cell;
};

std::vector<std::vector<Coord>> define_grid(){
    std::vector<std::vector<Coord>> grid (GRIDHEIGHT, 
        std::vector<Coord>(GRIDWIDTH, {-1, -1, ' '}));

    for(size_t i = 0; i < GRIDHEIGHT; i++)
        for(size_t j = 0; j < GRIDWIDTH; j++){
            grid[i][j].x = i;
            grid[i][j].y = j;
        }

    return grid;
}

void print_grid_state(std::vector<std::vector<Coord>>& grid){
    std::ostringstream buffer;

    buffer << "\n";
    buffer << "\t";
    for(size_t i = 0; i < GRIDWIDTH; i++)
        buffer << "_";
    buffer << "\n";


    for(size_t i = 0; i < GRIDHEIGHT; i++){
        buffer << "\t|";
        for(size_t j = 0; j < GRIDWIDTH; j++)
            buffer << grid[i][j].cell;
        buffer << "|\n"; 
    }

    buffer << "\t|";
    for(size_t i = 0; i < GRIDWIDTH; i++)
        buffer << "_";
    buffer << "|\n";

    std::cout << buffer.str() << std::endl;

}

int main(){

    std::vector<std::vector<Coord>> grid = define_grid();

    grid[8][4].cell = SNACKCELL;
    grid[9][4].cell = SNACKCELL;
    grid[8][5].cell = SNACKCELL;
    grid[8][6].cell = SNACKCELL;
    grid[8][15].cell = FRUITCELL;

    print_grid_state(grid);

    return 0;
}
