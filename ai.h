// @author: Minh Minh
// @filename: ai.cpp
// @date: 01/18/2022


#ifndef AI_H
#define AI_H

#include <map>
#include <iostream>

const char player{ 'x' };
const char ai{ 'o' };

struct MovePosition
{
    int row = -1;
    int col = -1;
};

int checkMoveRemains(char state[3][3]);

int evaluateScore(char array[3][3]);

int minimax(char state[3][3], int depth, bool aiTurn);

void AIMove(char state[3][3]);

#endif

