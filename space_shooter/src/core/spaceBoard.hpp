#pragma once

// libs
#include <cstdint>
#include <windows.h>

#include "./engine2D.hpp"

namespace SpaceBoardHandler {

    //===========================================================
    //
    //  macros
    //
    //===========================================================

    #define WIDTH 70
    #define HEIGHT 20

    //===========================================================
    //
    //  Estruturas auxiliares
    //
    //===========================================================

    // coordenada e simbolo do elemento que vai ser desenhado em tela.
    struct Sprite {

        uint8_t y; // <- linha
        uint8_t x; // <- coluna 
        char obj_ascii;

        Sprite();
        Sprite(uint8_t y, uint8_t x, const char obj);
    };

    // controle de coordenada para os objetos do game.
    struct  Coordinates {

        uint8_t y; // <- linha
        uint8_t x; // <- coluna 

        Coordinates();
        Coordinates(uint8_t y, uint8_t x);

        // checa se a nova coordenada está dentro do limite das bordas do board.
        bool inBounds(const uint8_t y, const uint8_t x);

        // modifica a nova coordenada jogando a nave para o lado oposto do grid
        // quando a mesma sair tentar sair do limite do board.
        void wrapAround(uint8_t& y, uint8_t& x);

        // nomaliza a nova coordenada aplicando in/bounds e wrapAround.
        void normalizeCoord(uint8_t y, uint8_t x);

        // modifica as coodenadas y e x de acordo com a tecla pressionada.
        void MOV(const uint16_t& key);
    };
    
}