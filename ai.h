#ifndef AI_H
#define AI_H

#include "interface.h"

int evaluateScore(char array[][SUB_SIZE_OF_BOARD]);

void AIMove(char array[][SUB_SIZE_OF_BOARD]);

int bestMove(char array[][SUB_SIZE_OF_BOARD], int depth, bool isMax);

#endif
