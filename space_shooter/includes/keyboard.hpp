#ifndef __KEYBOARD__HPP__
#define __KEYBOARD__HPP__

#include "./core_sys.hpp"
#include "./core_std.hpp"

class Keyboardhandler {
    public:
        static WinKeyState keypress();
};

#endif