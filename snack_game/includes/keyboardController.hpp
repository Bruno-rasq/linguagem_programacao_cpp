#ifndef KEYBOARDCONTROLLERHPP
#define KEYBOARDCONTROLLERHPP

#include <iostream>
#include <windows.h>

struct KeyState {
    bool stateUp = false,   stateDown = false; 
    bool stateLeft = false, stateRight = false;
};

class KeyboardController {
private:
    KeyState previousPressed;
    uint16_t currentDirection = VK_RIGHT;

public:

    KeyboardController();

    /**
     * Retorna o codigo (ou direcao) da tecla que esta sendo pressionada.
     * o nome Poll key segue uma convenção usada em engine graficas para
     * indicar uma aleitura não-bloqueante.
     * estado atual sem pausar o programa.
    */
    uint16_t poll_key();

    bool is_opposite_direction(uint16_t nextdirection);


    // getter & setter -> previousPressed

    KeyState get_previous_pressed_key(); 

    void set_previous_state_key(bool up, bool down, bool left, bool right);


    //getter & setter -> currentDirection

    uint16_t get_current_direction();

    void set_current_direction(uint16_t newDirection);
};

#endif