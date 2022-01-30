// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#ifndef AI_H
#define AI_H

#include "interface.h"
#include <map>
#include <cstdlib>

struct MovePosition
{
    int row = -1;
    int col = -1;
};

int checkMoveRemains(char state[][SUB_SIZE_OF_BOARD]);

int evaluateScore(char array[][SUB_SIZE_OF_BOARD]);

int minimax(char state[][SUB_SIZE_OF_BOARD], int depth, bool aiTurn);

void AIMove(char state[][SUB_SIZE_OF_BOARD]);

#endif
