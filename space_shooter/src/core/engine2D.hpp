#pragma once

// libs
#include <cstdint>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

// headers
#include "./spaceBoard.hpp"

namespace Engine2D {

    //===========================================================
    //
    //  Macros e definições de tipo.
    //
    //===========================================================

    #define FPS 80
    #define BOARDWIDTH 70
    #define BOARDHEIGTH 20

    typedef std::vector<std::string> GFrame;
    typedef SpaceBoardHandler::Sprite GSprite;
    
    //===========================================================
    //
    //  Controles (keyboard)
    //
    //===========================================================

    class KeyboardInput  {
        public:
            // Captura a tecla de forma nao bloqueante.
            // Teclas mapeadas::
            //  - MOVIMENTAÇÃO: seta para cima, baixo, esquerda E direita
            //  - ATIRAR: barra
            //  - SAIR: esc
            // Deve por padrão retornar 0.
            static uint16_t capturePressedKey();
    };


    //===========================================================
    //
    //  gerenciamento de frames.
    //
    //===========================================================

    class FrameBuffer {
        private:
            GFrame current_frame;

        public:
            FrameBuffer();
            void Render() const;
            void DrawSprite(const GSprite sprite);
            void ClearSprite(const GSprite sprite);
    };

    
    //===========================================================
    //
    //  gerenciamento de frames por segundo.
    //
    //===========================================================
    class Timer {};

    //===========================================================
    //
    //  motor rudimentar minimalista e feio.
    //
    //===========================================================
    class Engine {
        private:
            bool on_off = false;

        public:
            Engine();

            void on();
            void off();
            void game();
    };
};