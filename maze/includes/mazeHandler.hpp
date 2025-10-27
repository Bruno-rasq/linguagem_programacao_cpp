#pragma once

#include <vector>
#include <sstream>      // -> para buffer de output.
#include <iostream>     // -> para impressão no console.
#include <fstream>      // -> para leitura de arquivos.
#include <cstdint>      // -> para uso mais especifico de tipos de variaveis
#include <windows.h>    // -> para acessar as VK_* (teclas)

namespace MazeHandler {

    typedef std::vector<std::vector<char>> maze_t;
    
    struct Coord {
        int32_t x, y;
        Coord(int32_t x, int32_t y);
    };

    struct MazeObject {
        maze_t maze;
        Coord start;    // coordenada de inicio do labirinto (S)
        Coord end;      // coordenada de saida do labirinto (E)

        MazeObject();
        MazeObject(const maze_t& maze, const Coord& start, const Coord& end);
    };

    // executa a leitura de arquivo modelo de um labirinto.
    MazeObject loadMaze(const std::string& filePath);

    // escolhe randomicamente um dos 7 modelos de labirinto para ser
    // o modelo que a instancia da classe Maze vai usar.
    MazeObject randMaze();

    // calcula dado uma coordenada e uma key (delta) a nova coordenada.
    Coord getNextCoord(Coord currentCoord, const uint16_t key);

    class Maze {
    private:
        MazeObject currentMaze;

    public:
        Maze();

        void setCoord(uint16_t x, uint16_t y);
        void clearCoord(uint16_t x, uint16_t y);
        bool inBounds(uint16_t x, uint16_t y) const;
        void display() const;
        MazeObject getMaze() const;
    };
}

