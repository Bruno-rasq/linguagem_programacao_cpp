#pragma once

#include <cstdint>
#include <windows.h>
#include <sstream>
#include <iostream>

#include "./spaceBoard.hpp"

namespace Engine2D {

    typedef SpaceBoardHandler::BoardFrame Frame;
    
    /*
        sistema de entrada
    */
    class KeyboardInput  {
        public:
            // Captura a tecla de forma nao bloqueante.
            // Teclas mapeadas::
            //  - MOVIMENTAÇÃO: seta para cima, baixo, esquerda E direita
            //  - ATIRAR: barra
            //  - SAIR: esc
            // Deve por padrão retornar 0.
            uint16_t capturePressedKey();
    };

    /*
        representa o frame atual
    */
    class FrameBuffer {
        public:
            static void Render(Frame frame);
    };

    /*
        gerenciamento de tempo (FPS)
    */
    class Timer {};

    /*
        classe principal da engine
    */
    class Engine {};
};