#pragma once

#include <cstdint>
#include <windows.h>
#include <conio.h>

namespace KEYBOARDHANDLER {

    // bloqueia console enquanto uma tecla nao for pressionada.
    // int ch = _getch(); -> bloqueia console ate aparecer um caracter;
    // teclas "especiais" (setas, f-keys, etc..) retornam 0 ou 224 primeiro
    // int code = _getch(); -> captura o codigo da tecla.
    //      - 72 (seta para cima)
    //      - 80 (seta para baixo)
    //      - 75 (seta para esquerda)
    //      - 77 (seta para direita)
    //      - 27 (escape)

    uint16_t WaitForKeyBlockingConsole();
}