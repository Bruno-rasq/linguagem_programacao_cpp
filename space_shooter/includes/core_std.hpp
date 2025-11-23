#ifndef __CORE__SDT__HPP__
#define __CORE__SDT__HPP__

// streams
#include <sstream>
#include <iostream>

// Data struct
#include <vector>
#include <string>
#include <unordered_map>

#include <cstdlib>
#include <cstdint>

// -- macros

const uint8_t TIME_SLEEP = 100;
const uint8_t FRAME_BOARD_MAX_WIDTH = 70;
const uint8_t FRAME_BOARD_MAX_HEIGTH = 20;
const uint8_t PLAYER_INITIAL_COORD_ROW = 9;
const uint8_t PLAYER_INITIAL_COORD_COL = 34;


const int KEY_MSB_MASK = 0x8000; //MSB -> most significant bit

typedef std::stringstream           Buffer;
typedef std::vector<std::string>    Frame;        // estado atual do game.

typedef int8_t                      Coord_row;      
typedef int8_t                      Coord_col;
typedef uint8_t                     Direction;      // 1=cima, 2=baixo 3=esquerda, 4=direita
typedef uint16_t                    WinKeyState;

typedef char                        Obj_ascii;
typedef char                        Spaceshipface;


#endif