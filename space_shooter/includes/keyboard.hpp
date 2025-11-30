#ifndef __KEYBOARD__HPP__
#define __KEYBOARD__HPP__

#include "./core_sys.hpp"
#include "./core_types.hpp"

using namespace TYPING;

/**
 *  Classe utiliza a lib windows.h que disponibiliza metodos e definições
 *  que auxiliam a identificar qual tecla  do teclado o player pressionou
 * 
 *  apenas uma tecla por vez.
 * 
 *  teclas mapeaddas foram:
 *  controle do player:
 *  - seta direcional para cima
 *  - seta direcional para baixo
 *  - seta direcional para esquerda
 *  - seta direcional para direita
 * 
 *  - espaço (dispara projeteis)
 *  - esc (sair.)
*/
class Keyboardhandler
{
    public:
        static WinKeyState keypress();
};

#endif