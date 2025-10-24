#include "../includes/keyboardController.hpp"
#include <iostream>
#include <windows.h>
#include <cstdlib>

// Inicialização dos membros estáticos
KeyState KeyboardController::previousPressed;
uint16_t KeyboardController::currentDirection = VK_RIGHT;

uint16_t KeyboardController::pollKey() {
    
    const SHORT up    = GetAsyncKeyState(VK_UP);
    const SHORT down  = GetAsyncKeyState(VK_DOWN);
    const SHORT left  = GetAsyncKeyState(VK_LEFT);
    const SHORT right = GetAsyncKeyState(VK_RIGHT);
    const SHORT esc   = GetAsyncKeyState(VK_ESCAPE);

    const KeyState prev = getPreviousPressedKey();

    bool curUp    = (up    & 0x8000) != 0;
    bool curDown  = (down  & 0x8000) != 0;
    bool curLeft  = (left  & 0x8000) != 0;
    bool curRight = (right & 0x8000) != 0;

    uint16_t result = getCurrentDirection();

    if (curUp && !prev.stateUp)             result = VK_UP;
    else if (curDown && !prev.stateDown)    result = VK_DOWN;
    else if (curLeft && !prev.stateLeft)    result = VK_LEFT;
    else if (curRight && !prev.stateRight)  result = VK_RIGHT;
    else if (esc & 0x8000)                  result = VK_ESCAPE; 

    setPreviousKeyState(curUp, curDown, curLeft, curRight);
    return result;
}

bool KeyboardController::isOppositeDirection(uint16_t nextDirection) {
    const uint16_t current = getCurrentDirection();
    return (current == VK_UP && nextDirection == VK_DOWN) ||
           (current == VK_DOWN && nextDirection == VK_UP) ||
           (current == VK_LEFT && nextDirection == VK_RIGHT) ||
           (current == VK_RIGHT && nextDirection == VK_LEFT);
}

KeyState KeyboardController::getPreviousPressedKey() {
    return previousPressed;
}

void KeyboardController::setPreviousKeyState(bool up, bool down, bool left, bool right) {
    previousPressed.stateUp = up;
    previousPressed.stateDown = down;
    previousPressed.stateLeft = left;
    previousPressed.stateRight = right;
}

uint16_t KeyboardController::getCurrentDirection() {
    return currentDirection;
}

void KeyboardController::setCurrentDirection(uint16_t newDirection) {
    currentDirection = newDirection;
}
