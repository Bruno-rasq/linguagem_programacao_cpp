#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

struct Coord {
    int32_t row;
    int32_t col;
    char16_t cell;
};

typedef std::vector<Coord> row_t;
typedef std::vector<row_t> grid_t;

void print_grid_state(grid_t& grid){
    std::ostringstream buffer;

    char a = static_cast<char>(grid[0][0].cell);
    char b = static_cast<char>(grid[0][1].cell);
    char c = static_cast<char>(grid[0][2].cell);
    char d = static_cast<char>(grid[1][0].cell);
    char e = static_cast<char>(grid[1][1].cell);
    char f = static_cast<char>(grid[1][2].cell);
    char g = static_cast<char>(grid[2][0].cell);
    char h = static_cast<char>(grid[2][1].cell);
    char i = static_cast<char>(grid[2][2].cell);

    buffer << "|-------------------------------|\n";
    buffer << "|         |         |           |\n";
    buffer << "|    "<<a<<"    |    "<<b<<"    |     "<<c<<"     |\n";
    buffer << "|         |         |           |\n";
    buffer << "|_________|_________|___________|\n";
    buffer << "|         |         |           |\n";
    buffer << "|    "<<d<<"    |    "<<e<<"    |     "<<f<<"     |\n";
    buffer << "|         |         |           |\n";
    buffer << "|_________|_________|___________|\n";
    buffer << "|         |         |           |\n";
    buffer << "|    "<<g<<"    |    "<<h<<"    |     "<<i<<"     |\n";
    buffer << "|         |         |           |\n";
    buffer << "|_________|_________|___________|\n";

    std::cout << buffer.str() << std::endl;
}

grid_t define_initial_grid(){

    grid_t grid (3, row_t(3, {-1, -1, ' '}));
    
    for(size_t i = 0; i < 3; i++)
        for(size_t j = 0; j < 3; j++){
            grid[i][j].row = i;
            grid[i][j].col = j;
        }
    

    return grid;
}

bool is_valid_play(grid_t& grid, uint32_t x, uint32_t y){
    return ( 0 <= x && x < 3 && 0 <= y && y < 3 && grid[x][y].cell != ' ');
}

void execute_play(grid_t& grid, bool is_player_1){

    while(true){

        uint32_t row, col;

        std::cout << "Escolha uma linha e coluna (1 a 3)\n";
        std::cout << "Linha: ";
        std::cin >> row;
        std::cout << "Coluna: ";
        std::cin >> col;

        if(is_valid_play(grid, row, col)){
            grid[row - 1][col - 1].cell = (is_player_1 ? 'O' : 'X');
            break;
        }

        std::cout << "jogada invalida! por favor tente novamente.\n";
    }
}

int main() {

    grid_t grid = define_initial_grid();

    grid[0][0].cell = 'O';
    grid[1][1].cell = 'O';
    grid[2][2].cell = 'O';

    print_grid_state(grid);

    return 0;
}