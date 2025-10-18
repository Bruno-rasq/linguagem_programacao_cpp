#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <string>

struct Coord {
    int32_t row;
    int32_t col;
    char cell;
};

typedef std::vector<Coord> row_t;
typedef std::vector<row_t> grid_t;

//prototipos de funçoes
grid_t define_initial_grid();
void execute_play(grid_t& grid, bool is_player_1);
void print_grid_state(grid_t& grid);
void clear_console();
bool check_if_player_won(grid_t& grid, char pc);
bool check_if_the_game_over(grid_t& grid);
bool is_valid_play(grid_t& grid, uint32_t x, uint32_t y);
bool had_O_and_X(std::vector<char> cells);
bool had_a_draw(grid_t& gd);


int main() {

    grid_t grid = define_initial_grid();

    bool controler = true;
    bool had_a_winner = false;

    for(size_t turn = 0; turn < 9; turn++){

        clear_console();

        if(had_a_draw(grid)) break;

        if(check_if_the_game_over(grid)){
            had_a_winner = true;
            break;
        }

        print_grid_state(grid);

        execute_play(grid, controler);

        controler = (controler? false : true);
    }

    if(!had_a_winner){ 
        clear_console();
        std::cout << "EMPATE!\n"; 
    }
    
    print_grid_state(grid);

    return 0;
}

void clear_console(){
    system("cls");
}

void print_grid_state(grid_t& grid){
    std::ostringstream buffer;

    char a = grid[0][0].cell;
    char b = grid[0][1].cell;
    char c = grid[0][2].cell;
    char d = grid[1][0].cell;
    char e = grid[1][1].cell;
    char f = grid[1][2].cell;
    char g = grid[2][0].cell;
    char h = grid[2][1].cell;
    char i = grid[2][2].cell;

    buffer << "\n";
    buffer << "\t|-------------------------------|\n";
    buffer << "\t|         |         |           |\n";
    buffer << "\t|    "<<a<<"    |    "<<b<<"    |     "<<c<<"     |\n";
    buffer << "\t|         |         |           |\n";
    buffer << "\t|_________|_________|___________|\n";
    buffer << "\t|         |         |           |\n";
    buffer << "\t|    "<<d<<"    |    "<<e<<"    |     "<<f<<"     |\n";
    buffer << "\t|         |         |           |\n";
    buffer << "\t|_________|_________|___________|\n";
    buffer << "\t|         |         |           |\n";
    buffer << "\t|    "<<g<<"    |    "<<h<<"    |     "<<i<<"     |\n";
    buffer << "\t|         |         |           |\n";
    buffer << "\t|_________|_________|___________|\n";
    buffer << "\n";

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

bool check_if_player_won(grid_t& grid, char pc){

    for(size_t i = 0; i < 3; i++){
        // linhas e colunas
        if(grid[i][0].cell == pc && grid[i][1].cell == pc && grid[i][2].cell == pc) return true;
        if(grid[0][i].cell == pc && grid[1][i].cell == pc && grid[2][i].cell == pc) return true;
    }

    //diagonais
    if(grid[0][0].cell == pc && grid[1][1].cell == pc && grid[2][2].cell == pc) return true;
    if(grid[0][2].cell == pc && grid[1][1].cell == pc && grid[2][0].cell == pc) return true;

    return false;
}

bool check_if_the_game_over(grid_t& grid){
    bool p1 = check_if_player_won(grid, 'O');
    bool p2 = check_if_player_won(grid, 'X');

    if(p1) {
        std::cout << "Jogador 1 venceu!\n";
        return true;
    }

    if(p2) {
        std::cout << "Jogador 2 venceu!\n";
        return true;
    }

    return false;
}

bool is_valid_play(grid_t& grid, uint32_t x, uint32_t y){
    return ( 0 <= x && x < 3 && 0 <= y && y < 3 && grid[x][y].cell == ' ');
}

void execute_play(grid_t& grid, bool is_player_1){

    while(true){

        uint32_t row, col;

        std::cout << "Jogador " << (is_player_1 ? "1 (O)\n" : "2 (X)\n"); 
        std::cout << "Escolha uma linha e coluna (1 a 3)\n";

        std::cout << "Linha: ";
        std::cin >> row;
        std::cout << "Coluna: ";
        std::cin >> col;

        if(is_valid_play(grid, (uint32_t)row - 1, (uint32_t)col - 1)){
            grid[row - 1][col - 1].cell = (is_player_1 ? 'O' : 'X');
            return;
        }

        std::cout << "jogada invalida! por favor tente novamente.\n";
    }
}

bool had_O_and_X(std::vector<char> cells){
    bool had_o = false;
    bool had_x = false;

    for(char c : cells){
        if(c == 'O') had_o = true;
        if(c == 'X') had_x = true;
    }

    return had_o && had_x;
}


// há 3 cenarios de empate.
// 1 - chegou ao ultimo turno sem definir um vencedor.
// 2 - não há uma possiblidade de alguem vencer mesmo antes do ultimo turno.
// 3 - empates antecipados (leva em consideração que ambos os jogados jogam de forma perfeita)
//      este caso é mais complicado de verificar, então o game não está 100% correto!
bool had_a_draw(grid_t& gd){
    
    for(size_t i = 0; i < 3; i++){

        std::vector<char> row = {gd[i][0].cell, gd[i][1].cell, gd[i][2].cell};
        std::vector<char> col = {gd[0][i].cell, gd[1][i].cell, gd[2][i].cell};

        if(!had_O_and_X(row) || !had_O_and_X(col)) return false;
    }

    std::vector<char> diagonal1 = {gd[0][0].cell, gd[1][1].cell, gd[2][2].cell};
    std::vector<char> diagonal2 = {gd[0][2].cell, gd[1][1].cell, gd[2][0].cell};

    if(!had_O_and_X(diagonal1) || !had_O_and_X(diagonal2)) return false;

    return true;
}