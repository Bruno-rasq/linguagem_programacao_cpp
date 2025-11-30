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

/* macros */
const uint8_t TIME_SLEEP = 120;
const uint8_t FRAME_BOARD_MAX_WIDTH = 70;
const uint8_t FRAME_BOARD_MAX_HEIGTH = 20;
const uint8_t PLAYER_INITIAL_COORD_ROW = 9;
const uint8_t PLAYER_INITIAL_COORD_COL = 34;

/* MSB -> most significant bit */
const int KEY_MSB_MASK = 0x8000;


#endif