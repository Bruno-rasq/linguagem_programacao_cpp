#pragma once

// libs
#include <cstdint>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>


// declaração antecipada (evita inclusao ciclica)
namespace PlayerSpaceshipHandler { class Player; };


namespace Engine2D {

    //===========================================================
    //
    //  Macros e definições de tipo.
    //
    //===========================================================

    #define FPS 80
    #define FRAMETIME  1000 / FPS
    #define BOARDWIDTH 70
    #define BOARDHEIGTH 20

    typedef std::vector<std::string> Frame;
    typedef PlayerSpaceshipHandler::Player GPlayer;

    //============================================================================
    //
    //  Estruturas auxiliares
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

        // checa se a nova coordenada está dentro do limite das bordas do board.
        bool inBounds(const uint8_t row, const uint8_t col);

        // modifica a nova coordenada jogando a nave para o lado oposto do grid
        // quando a mesma sair tentar sair do limite do board.
        void wrapAround(uint8_t& row, uint8_t& col);

        // nomaliza a nova coordenada aplicando in/bounds e wrapAround.
        void normalizeCoord(uint8_t row, uint8_t col);

        // modifica as coodenadas y e x de acordo com a tecla pressionada.
        void MOV(const uint16_t& key);
    };
    
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

    class Engine {
        private:
            bool on_off = false;
            FrameBuffer FBC;
            //PlayerSpaceshipHandler::Player* plyr;

        public:
            Engine();

            void On();
            void Off();
            void Game();
    };


};