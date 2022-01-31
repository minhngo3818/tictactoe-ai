// @author: Minh Minh
// @filename: interface.cpp
// @date: 01/18/2022


#ifndef AI_H
#define AI_H

#include <map>
#include <cstdlib>

const int SIZE_OF_BOARD = 3;
const int SUB_SIZE_OF_BOARD = 3;
const char player = 'o';
const char ai = 'x';

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
