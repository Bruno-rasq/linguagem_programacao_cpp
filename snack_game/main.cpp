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


Coord get_random_coordinates(){
    uint8_t x = std::rand() % GRIDHEIGHT;
    uint8_t y = std::rand() % GRIDWIDTH;
    return {x, y};
}

// limpa o console (Windows)
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

// atualiza posição da serpente
void update_snack_position(snack_t& snack, uint16_t currentDirection) {
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

    snack.pop_front();
    snack.push_back({x, y, SNACKCELL});
}

// atualiza o grid conforme posição da serpente
void update_grid_state(grid_t& grid, snack_t& snack) {
    for (auto& row : grid)
        for (auto& cell : row)
            cell.cell = VOIDCELL;

    for (const auto& cs : snack)
        grid[cs.x][cs.y].cell = cs.cell;
}

// imprime o estado atual do grid
void print_grid_state(grid_t& grid) {
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

// loop principal
int main() {
    std::srand(std::time(nullptr));

    uint16_t direction = VK_RIGHT;
    grid_t grid = define_grid();
    snack_t snack = define_snack();

    bool prevUp = false, prevDown = false, prevLeft = false, prevRight = false;

    while (true) {
        clear_console();

        uint16_t key = get_key_board_onpress(prevUp, prevDown, prevLeft, prevRight, direction);
        if (key == VK_ESCAPE) break;

        update_snack_position(snack, key);
        update_grid_state(grid, snack);
        print_grid_state(grid);

        Sleep(TIME);
        direction = key;
    }

    return 0;
}
