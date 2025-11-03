#pragma once 

#include <cstdint>
#include <windows.h>

namespace KEYBOARDHANDLER {

    // Captura a tecla de forma nao bloqueante.
    // Teclas mapeadas::
    //  - MOVIMENTAÇÃO: seta para cima, baixo, esquerda E direita
    //  - ATIRAR: barra
    //  - SAIR: esc
    // Deve por padrão retornar 0.
    uint16_t captureKey();
};