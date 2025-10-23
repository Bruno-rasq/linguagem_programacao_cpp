#include "../includes/keyboardController.hpp"

KeyboardController::KeyboardController(){}

uint16_t KeyboardController::poll_key() {

    const SHORT up    = GetAsyncKeyState(VK_UP);
    const SHORT down  = GetAsyncKeyState(VK_DOWN);
    const SHORT left  = GetAsyncKeyState(VK_LEFT);
    const SHORT right = GetAsyncKeyState(VK_RIGHT);
    const SHORT esc   = GetAsyncKeyState(VK_ESCAPE);
    const KeyState prev = this->get_previous_pressed_key();


    bool curUp    = (up    & 0x8000) != 0;
    bool curDown  = (down  & 0x8000) != 0;
    bool curLeft  = (left  & 0x8000) != 0;
    bool curRight = (right & 0x8000) != 0;

    uint16_t result = this->get_current_direction();


    if (curUp && !prev.stateUp)               result = VK_UP;
    else if (curDown && !prev.stateDown)      result = VK_DOWN;
    else if (curLeft && !prev.stateLeft)      result = VK_LEFT;
    else if (curRight && !prev.stateRight)    result = VK_RIGHT;
    else if (esc & 0x8000)                    result = VK_ESCAPE; 


    this->set_previous_state_key(curUp, curDown, curLeft, curRight);

    return result;
}

bool KeyboardController::is_opposite_direction(uint16_t nextdirection){

    const uint16_t current = this->get_current_direction();
    return (current == VK_UP && nextdirection == VK_DOWN) ||
           (current == VK_DOWN && nextdirection == VK_UP) ||
           (current == VK_LEFT && nextdirection == VK_RIGHT) ||
           (current == VK_RIGHT && nextdirection == VK_LEFT);
}

KeyState KeyboardController::get_previous_pressed_key(){
    return this->previousPressed;
}

void KeyboardController::set_previous_state_key(
    bool up, bool down, bool left, bool right
){
    this->previousPressed.stateUp = up;
    this->previousPressed.stateDown = down;
    this->previousPressed.stateLeft = left;
    this->previousPressed.stateRight = right;
}

uint16_t KeyboardController::get_current_direction(){
    return this->currentDirection;
}

void KeyboardController::set_current_direction(uint16_t newdirection){
    this->currentDirection = newdirection;
}