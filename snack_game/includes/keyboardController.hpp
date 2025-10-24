#pragma once
#include <windows.h>
#include <cstdint>

struct KeyState {
    bool stateUp = false, stateDown = false; 
    bool stateLeft = false, stateRight = false;
};

class KeyboardController {
private:
    // Mantemos os estados e direção como estáticos para simular classe estática
    static KeyState previousPressed;
    static uint16_t currentDirection;

    // Construtor privado para evitar instância
    KeyboardController() {}

public:
    // Polling da tecla pressionada de forma não bloqueante
    static uint16_t pollKey();

    // Verifica se a próxima direção é oposta à atual
    static bool isOppositeDirection(uint16_t nextDirection);

    // Getters e setters
    static KeyState getPreviousPressedKey();
    static void setPreviousKeyState(bool up, bool down, bool left, bool right);

    static uint16_t getCurrentDirection();
    static void setCurrentDirection(uint16_t newDirection);
};

//g++ src/*.cpp main.cpp -Iincludes -o snack_game.exe -Wall -Wextra
