#include "./keyboard.hpp"

WinKeyState Keyboardhandler::keypress()
{

    if((GetAsyncKeyState(VK_UP)     & KEY_MSB_MASK) != 0) return VK_UP;
    if((GetAsyncKeyState(VK_DOWN)   & KEY_MSB_MASK) != 0) return VK_DOWN;
    if((GetAsyncKeyState(VK_LEFT)   & KEY_MSB_MASK) != 0) return VK_LEFT;
    if((GetAsyncKeyState(VK_RIGHT)  & KEY_MSB_MASK) != 0) return VK_RIGHT;
    if((GetAsyncKeyState(VK_SPACE)  & KEY_MSB_MASK) != 0) return VK_SPACE;
    if((GetAsyncKeyState(VK_ESCAPE) & KEY_MSB_MASK) != 0) return VK_ESCAPE;

    return 0; // nenhuma tecla foi pressionada.
};