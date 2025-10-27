#include "../includes/keyboardHandler.hpp"

uint16_t KEYBOARDHANDLER::WaitForKeyBlockingConsole(){

    int ch = _getch();

    if(ch == 0 || ch == 224){
        int code = _getch();

        if(code == 72) return VK_UP;
        if(code == 80) return VK_DOWN;
        if(code == 75) return VK_LEFT;
        if(code == 77) return VK_RIGHT;

        return static_cast<uint16_t>(code);
    }

    if(ch == 27) return VK_ESCAPE;

    return static_cast<uint16_t>(ch);
}