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
#include <iomanip>
#include <ctime>

/* macros */
const uint8_t TIME_SLEEP = 120;
const uint8_t FRAME_BOARD_MAX_WIDTH = 70;
const uint8_t FRAME_BOARD_MAX_HEIGTH = 20;
const uint8_t PLAYER_INITIAL_COORD_ROW = 9;
const uint8_t PLAYER_INITIAL_COORD_COL = 34;

/* MSB -> most significant bit */
const int KEY_MSB_MASK = 0x8000;

const char ASTEROID_CHAR = 'O';

const int8_t DELTAOPTIONS[3] = {-1, 0, 1};

/* Pontuação para cada asteroid */
const uint32_t MAX_SCORE = 99999; 
const uint8_t SCORE_SMALL_ASTEROID = 10;
const uint8_t SCORE_MEDIUM_ASTEROID = 25;
const uint8_t SCORE_LARGE_ASTEROID = 50;

/* Quantidade de hits para destruir um asteroid. */
const uint8_t HITS_TO_DESTROY_SMALL_ASTEROID = 1;
const uint8_t HITS_TO_DESTROY_MEDIUM_ASTEROID = 3;
const uint8_t HITS_TO_DESTROY_LARGE_ASTEROID = 5;

const uint8_t TOTAL_LIFES = 3;

#endif