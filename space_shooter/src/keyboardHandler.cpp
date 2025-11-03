#include "../includes/keyboardHandler.hpp"

namespace KEYBOARDHANDLER {

    uint16_t captureKey(){

        const int KEY_MSB_MASK = 0x8000; //MSB -> most significant bit

        if((GetAsyncKeyState(VK_UP)     & KEY_MSB_MASK) != 0) return VK_UP;
        if((GetAsyncKeyState(VK_DOWN)   & KEY_MSB_MASK) != 0) return VK_DOWN;
        if((GetAsyncKeyState(VK_LEFT)   & KEY_MSB_MASK) != 0) return VK_LEFT;
        if((GetAsyncKeyState(VK_RIGHT)  & KEY_MSB_MASK) != 0) return VK_RIGHT;
        if((GetAsyncKeyState(VK_SPACE)  & KEY_MSB_MASK) != 0) return VK_SPACE;
        if((GetAsyncKeyState(VK_ESCAPE) & KEY_MSB_MASK) != 0) return VK_ESCAPE;

        return 0;
    };
};