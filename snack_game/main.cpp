#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <windows.h>
#include <deque>

#define GRIDWIDTH   45
#define GRIDHEIGHT  15
#define SNACKCELL   '#'
#define FRUITCELL   'O'
#define VOIDCELL    '.'
#define TIME        120

struct Coord { int32_t x, y; };
struct CoordSnack { int32_t x, y; char cell; };
struct CellGrid { char cell; };

typedef std::vector<std::vector<CellGrid>> grid_t;
typedef std::deque<CoordSnack> snack_t;

// limpa o console
void clear_console() {
    system("cls");
}

// cria grid vazio
grid_t define_grid() {
    return grid_t(GRIDHEIGHT, std::vector<CellGrid>(GRIDWIDTH, {VOIDCELL}));
}

// define serpente no centro
snack_t define_snack() {
    const int32_t x = GRIDHEIGHT / 2;
    const int32_t y = GRIDWIDTH / 2;
    return snack_t(1, {x, y, SNACKCELL});
}

// gera coordenadas aleatórias dentro do grid
Coord get_random_coordinates() {
    return { std::rand() % GRIDHEIGHT, std::rand() % GRIDWIDTH };
}

// verifica se a coordenada colide com a serpente
bool check_fruit_span_on_snack_position(const snack_t& snack, const Coord& fruit) {
    for (const auto& cs : snack)
        if (cs.x == fruit.x && cs.y == fruit.y)
            return true;
    return false;
}

// gera fruta em posição válida
Coord generate_fruit_on_grid(const snack_t& snack) {
    while (true) {
        Coord fruit = get_random_coordinates();
        if (!check_fruit_span_on_snack_position(snack, fruit))
            return fruit;
    }
}

// captura tecla direcional (não bloqueante)
uint16_t get_key_board_onpress(
    bool& prevUp, bool& prevDown, bool& prevLeft, bool& prevRight, uint16_t currentDirection
) {
    const SHORT up    = GetAsyncKeyState(VK_UP);
    const SHORT down  = GetAsyncKeyState(VK_DOWN);
    const SHORT left  = GetAsyncKeyState(VK_LEFT);
    const SHORT right = GetAsyncKeyState(VK_RIGHT);
    const SHORT esc   = GetAsyncKeyState(VK_ESCAPE);

    bool curUp    = (up    & 0x8000) != 0;
    bool curDown  = (down  & 0x8000) != 0;
    bool curLeft  = (left  & 0x8000) != 0;
    bool curRight = (right & 0x8000) != 0;

    uint16_t result = currentDirection;

    if (curUp && !prevUp)               result = VK_UP;
    else if (curDown && !prevDown)      result = VK_DOWN;
    else if (curLeft && !prevLeft)      result = VK_LEFT;
    else if (curRight && !prevRight)    result = VK_RIGHT;
    else if (esc & 0x8000)              result = VK_ESCAPE; 

    prevUp = curUp;
    prevDown = curDown;
    prevLeft = curLeft;
    prevRight = curRight;

    return result;
}

bool is_opposite_direction(uint16_t current, uint16_t next) {
    return (current == VK_UP && next == VK_DOWN) ||
           (current == VK_DOWN && next == VK_UP) ||
           (current == VK_LEFT && next == VK_RIGHT) ||
           (current == VK_RIGHT && next == VK_LEFT);
}


// atualiza posição da serpente
void update_snack_position(snack_t& snack, uint16_t currentDirection, bool grow = false) {
    int16_t x = snack.back().x;
    int16_t y = snack.back().y;

    if (currentDirection == VK_UP)    x--;
    if (currentDirection == VK_DOWN)  x++;
    if (currentDirection == VK_RIGHT) y++;
    if (currentDirection == VK_LEFT)  y--;

    // wrap-around nas bordas
    if (x < 0) x = GRIDHEIGHT - 1;
    if (x >= GRIDHEIGHT) x = 0;
    if (y < 0) y = GRIDWIDTH - 1;
    if (y >= GRIDWIDTH) y = 0;

    if (!grow)
        snack.pop_front();
    snack.push_back({x, y, SNACKCELL});
}

// verifica se a serpente comeu a fruta
bool check_snack_eats_fruit(snack_t& snack, const Coord& fruit) {
    return (snack.back().x == fruit.x && snack.back().y == fruit.y);
}

// atualiza o grid com serpente e fruta
void update_grid_state(grid_t& grid, const snack_t& snack, const Coord& fruit) {
    for (auto& row : grid)
        for (auto& cell : row)
            cell.cell = VOIDCELL;

    for (const auto& cs : snack)
        grid[cs.x][cs.y].cell = cs.cell;

    grid[fruit.x][fruit.y].cell = FRUITCELL;
}

// imprime o grid
void print_grid_state(const grid_t& grid) {
    std::ostringstream buffer;
    buffer << "\n\t";
    for (size_t i = 0; i < GRIDWIDTH; i++) buffer << "_";
    buffer << "\n";

    for (size_t i = 0; i < GRIDHEIGHT; i++) {
        buffer << "\t|";
        for (size_t j = 0; j < GRIDWIDTH; j++)
            buffer << grid[i][j].cell;
        buffer << "|\n";
    }

    buffer << "\t|";
    for (size_t i = 0; i < GRIDWIDTH; i++) buffer << "_";
    buffer << "|\n";

    std::cout << buffer.str();
}

bool check_self_snack_collision(const snack_t& snack){
    if(snack.size() < 2) return false;

    const CoordSnack& head = snack.back();
    for(size_t idx = 0; idx < snack.size() - 1; idx++)
        if(snack[idx].x == head.x && snack[idx].y == head.y)
            return true;

    return false;
}

// loop principal
int main() {
    std::srand(std::time(nullptr));

    uint16_t direction = VK_RIGHT;
    grid_t grid = define_grid();
    snack_t snack = define_snack();
    Coord fruit = generate_fruit_on_grid(snack);

    bool prevUp = false, prevDown = false, prevLeft = false, prevRight = false;

    while (true) {
        clear_console();

        uint16_t nextDirection = get_key_board_onpress(prevUp, prevDown, prevLeft, prevRight, direction);
        if (nextDirection == VK_ESCAPE) break;

        // verifica se a proxima direcao nao é oposta a direcao atual,
        // evitando auto colisao
        if(!is_opposite_direction(direction, nextDirection)){
            direction = nextDirection;
        }

        bool grow = check_snack_eats_fruit(snack, fruit);
        update_snack_position(snack, direction, grow);

        
        if (grow)
            fruit = generate_fruit_on_grid(snack);

        if(check_self_snack_collision(snack)) break;

        update_grid_state(grid, snack, fruit);
        print_grid_state(grid);

        Sleep(TIME);
    }

    return 0;
}
