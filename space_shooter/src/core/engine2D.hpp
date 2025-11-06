#pragma once

#include <cstdint>
#include <windows.h>
#include <sstream>

#include "./spaceBoard.hpp"

using namespace SpaceBoardHandler;

namespace Engine2D {

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
            static constexpr uint16_t capturePressedKey();
    };

    /*
        representa o frame atual
    */
    class FrameBuffer {
        public:
            static constexpr void Render(BoardFrame& frame);
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