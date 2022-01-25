#ifndef AI_H
#define AI_H

#include "interface.h"
#include <map>

struct smartMove
{
    int row, col;
    int score;
};

int evaluateScore(char array[][SUB_SIZE_OF_BOARD]);

int minimax(char state[][SUB_SIZE_OF_BOARD], int depth, bool aiTurn);

#endif
