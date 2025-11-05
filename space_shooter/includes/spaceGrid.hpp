#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <windows.h>

using namespace std;

namespace SpaceGrid {

    #define SPACE_WIDTH 70
    #define SPACE_HEIGHT 20
    #define SPACEZONE ' '

    struct SpaceCoord {

        int8_t x, y;

        SpaceCoord(int8_t x, int8_t y);

        // verifica se a coordenada atual está dentro dos limites do grid.
        bool inBounds(const int8_t x, const int8_t y);

        // curva a coordenada atual para que o player nunca colida com bordas ou saida do grid.
        void wrapAround(int8_t& x, int8_t& y);

        // junta os metodos inBounds e wrapAround
        void normalizeCoord(int8_t x, int8_t y);

        // executa a movimentação alterando as coordenadas.
        void MOVE(const uint16_t& key);
    };


    class Space {
        private:
            vector<string> space;

        public:

            Space();

            // desenha na coordenada o objeto passado.
            void setCoord(const int8_t x, const int8_t y, const char ob);

            // limpa a coordenada antiga.
            void clearCoord(const int8_t x, const int8_t y);

            // retorna o frame visual atual do grid(space).
            string getFrameState() const;
    };
}