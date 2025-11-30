#ifndef __FRAMER__HPP__
#define __FRAMER__HPP__

#include "./core_std.hpp"
#include "./core_types.hpp"

using namespace TYPING;

namespace framerHandler
{

    /**
     *  Estrutura dos Sprites são as estruturas mais importantes visual-
     *  mente do game, elas guardam a coordenada x y do objeto e um char
     *  ASCII que é sua representação visual, seja do Player, Asteroids, 
     *  projeteis, inimigos e etc...
     */
    struct Sprite
    {

        Coord_row x;
        Coord_col y;
        Obj_ascii obj;

        Sprite();
        Sprite(Coord_row x, Coord_col y, Obj_ascii obj);
    };

    /**
     *  Estrutura framer_buffer é responsavel por gerar um vetor de strings
     *  que representa o frame da iteração do game, toda estrutura é gerada
     *  vazia, os elementos são adicionados, depois exibe o vetor em tela e
     *  destroi a estrutura finalizando o ciclo de vida de frame.
     * 
     *  Para melhorar o desempenho da exibição do vetor é usado um buffer 
     *  com a lib sstream, os dados são armazenados lá de forma a chamar a
     *  função cout apenas 1 vez.
    */
    struct framer_buffer 
    {
        Frame data;

        framer_buffer();
        void draw(const Sprite& sprite);
        void render() const;
    };
};

#endif