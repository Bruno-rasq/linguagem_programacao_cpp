#pragma once

#include "./core.hpp"

namespace Engine2D {

    //===========================================================
    //
    //  Macros e definições de tipo.
    //
    //===========================================================

    #define BOARDWIDTH 70
    #define BOARDHEIGTH 20

    typedef std::vector<std::string> Frame;


    //============================================================================
    //
    //  Estruturas e metodos auxiliares
    //
    //============================================================================

    struct Sprite {

        uint8_t row, col;
        char obj;

        Sprite();
        Sprite(uint8_t row, uint8_t col, const char obj);
    };

    struct  Coordinates {

        uint8_t row, col;

        Coordinates();
        Coordinates(uint8_t row, uint8_t col);

        void MOV(const uint16_t& key);
    };
    
    bool inBounds(const uint8_t row, const uint8_t col);

    void wrapAround(uint8_t& row, uint8_t& col); //desabilitei...

    //============================================================================
    //
    //  Controles (keyboard)
    //
    //============================================================================

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


    //============================================================================
    //
    //  gerenciamento de frames.
    //
    //============================================================================

    class FrameBuffer {
        private:
            Frame current_frame;

        public:
            FrameBuffer();
            void Render() const;
            void DrawSprite(const Sprite sprite);
            void ClearSprite(const Sprite sprite);
    };

    
    //============================================================================
    //
    //  gerenciamento de frames por segundo.
    //
    //============================================================================

    class Timer {};

    //============================================================================
    //
    //  motor rudimentar minimalista e feio.
    //
    //============================================================================

    class Engine {};
};